#include "Qint.h"

QInt::QInt()
{
	_arrayBits[0] = 0;
	_arrayBits[1] = 0;
	_arrayBits[2] = 0;
	_arrayBits[3] = 0;
}

void QInt::In(string strData, int base)
{
	_arrayBits[0] = 0;
	_arrayBits[1] = 0;
	_arrayBits[2] = 0;
	_arrayBits[3] = 0;

	if (base == 2)
	{

		int curPos = 3;
		int checkBit = 0;
		for (int i = strData.length() - 1; i >= 0; i--)
		{
			_arrayBits[curPos] = _arrayBits[curPos] | ((strData[i] - 48) << checkBit);
			checkBit++;
			if (checkBit == 32)
			{
				checkBit = 0;
				curPos--;
			}
		}
	}
	else if (base == 10)
	{
		//Xử lí nhập cơ số 10
		char bits[128] = { 0 };
		int i = 0;

		if (strData[0] != '-') //Số dương
		{
			while (strData != "0")
			{
				//Xét số cuối cùng của chuỗi, số chẵn thì bit là 0
				if ((strData[strData.length() - 1] - 48) % 2 == 0)
				{
					bits[i] = 0;
					i++;
				}
				//Nếu là số lẻ, bit là 1
				else
				{
					bits[i] = 1;
					i++;
				}
				//Chia chuỗi s cho 2
				strData = Div2(strData);

			};
			bits[127] = 0; //Bit dấu là 0 do là số dương
		}
		else //Số âm
		{
			string posS;
			posS = strData.substr(1, strData.length() - 1); //Lấy chuỗi sau dấu âm
			i = 0;
			while (posS != "0") //tương tự phần số dương
			{
				//Xét số cuối cùng của chuỗi, nếu là số chẵn khi chia 2 sẽ dư 0 
				if ((posS[posS.length() - 1] - 48) % 2 == 0)
				{
					bits[i] = 0;
					i++;
				}
				//Nếu là số lẻ, chia 2 sẽ dư 1
				else
				{
					bits[i] = 1;
					i++;
				}

				//Chia chuỗi s cho 2
				posS = Div2(posS);
				

			};
			bits[127] = 0;
			
			ConvertTwoComplement(bits, bits);//Chuyển sang s
		}

		int curPos = 0;
		int checkBit = 0;
		for (int i = 127; i >= 0; i--)
		{
			_arrayBits[curPos] = _arrayBits[curPos] | (bits[i] << (32 - 1 - checkBit));
			checkBit++;
			if (checkBit == 32)
			{
				checkBit = 0;
				curPos++;
			}
		}
	}
	else if (base == 16)
	{
		//Xử lí nhập cơ số 16
		int curPos = 3;
		int checkBit = 0;
		string bin = HexToBin(strData);

		for (int i = bin.length() - 1; i >= 0; i--)
		{
			_arrayBits[curPos] = _arrayBits[curPos] | ((bin[i] - 48) << checkBit);
			checkBit++;
			if (checkBit == 32)
			{
				checkBit = 0;
				curPos--;
			}
		}
	}
}

string QInt::Out(int base)
{
	string result;

	char bits[128] = { 0 };
	ConvertBitToArray(bits);//lấy dữ liệu ra mảng

	if (base == 2)
	{
		//Xử lí xuất _arrBit sang hệ 2
		
		for (int i = 127; i >= 0; i--)
			result += (bits[i] + 48);


	}
	else if (base == 10)
	{
		//Xử lí xuất _arrBit sang hệ 10

		result = "0";
		string temp;

		if (bits[127] == 0) //Bit dấu = 0 Số dương
		{
			for (int i = 0; i < 128; i++)
			{
				if (bits[i] == 1)
				{
					temp = MyPow(i);
					result = AddStr(result, temp);
				}
			}
		}
		else //Bit dấu = 1 Số âm
		{
			
			ConvertTwoComplement(bits, bits);//Chuyển về số đối

			for (int i = 0; i < 128; i++) //Tính giá trị như dạng không dấu
			{
				if (bits[i] == 1)
				{
					temp = MyPow(i);
					result = AddStr(result, temp);
				}
			}
			result = "-" + result;

			if (result == "-0")
				result = "0";

		}
		
	}
	else if (base == 16)
	{
		//Xử lí xuất _arrBit sang hệ 16

		for (int i = 31; i >= 0; i--)
		{
			int value = bits[i * 4 + 3] * 8 + bits[i * 4 + 2] * 4 + bits[i * 4 + 1] * 2 + bits[i * 4];
			if (value < 10)
				result += (value + '0');
			else
			{
				switch (value)
				{
				case 10:
					result += "A";
					break;
				case 11:
					result += "B";
					break;
				case 12:
					result += "C";
					break;
				case 13:
					result += "D";
					break;
				case 14:
					result += "E";
					break;
				case 15:
					result += "F";
					break;
				}

			}
			value = 0;
		}

	}

	//Xử lí xuất đúng số bit cần
	int pos = 0;
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] != '0')
		{
			pos = i;
			break;
		}
	}
	result = result.substr(pos, result.length() - pos);

	return result;
}

QInt operator+( QInt a,  QInt b)
{
	QInt sum;
	char bitsA[128] = { 0 }; //127 là bit dấu
	char bitsB[128] = { 0 };

	a.ConvertBitToArray(bitsA);
	b.ConvertBitToArray(bitsB);

	
	char bitsSum[128] = { 0 };
	Add(bitsA,bitsB,bitsSum);

	string result;
	for (int i = 127; i >=0; i--)
	{
		result +=(bitsSum[i] + '0');
	}
	sum.In(result, 2);

	return sum;
}

QInt operator-(QInt a, QInt b)
{
	QInt result;
	char bitsA[128] = { 0 }; //127 là bit dấu
	char bitsB[128] = { 0 };
	a.ConvertBitToArray(bitsA);
	b.ConvertBitToArray(bitsB);

	//Chuyển B sang số bù 2
	

	char bitResult[128] = { 0 };
	Sub(bitsA, bitsB, bitResult);
	string strResult;

	for (int i = 127; i >= 0; i--)
	{
		strResult += (bitResult[i] + '0');
	}
	result.In(strResult, 2);

	return result;
	
}

QInt operator*(QInt a, QInt b)
{
	QInt result;

	char bitsResult[128] = { 0 };
	char bitsA[128] = { 0 }; //127 là bit dấu
	char bitsB[128] = { 0 };

	a.ConvertBitToArray(bitsA);
	b.ConvertBitToArray(bitsB);

	for (int i = 0; i < 128; i++)
	{
		if (bitsB[i] == 1)
		{
			
			char temp[128] = { 0 };
			//dịch bit bitsA thành bitTemp
			DichPhaiTrenMang(bitsA, temp, i);
			Add(bitsResult, temp, bitsResult);
		}
	}


	string strResult;

	for (int i = 127; i >= 0; i--)
	{
		strResult += (bitsResult[i] + '0');
	}
	result.In(strResult, 2);

	return result;
}

QInt operator/(QInt a, QInt b)
{
	QInt result;

	char bitsResult[128] = { 0 };
	char bitsA[128] = { 0 }; //127 là bit dấu
	char bitsB[128] = { 0 };

	a.ConvertBitToArray(bitsA);
	b.ConvertBitToArray(bitsB);

	//số nào âm thì chuyển sang bù 2 đế thành phép chia dương
	char flagA = bitsA[127];
	char flagB = bitsB[127];

	if (bitsA[127] == 1)
		ConvertTwoComplement(bitsA,bitsA);
	if (bitsB[127] == 1)
		ConvertTwoComplement(bitsB,bitsB);

	for (int i = 127; i >= 0; i--)
	{
		char temp[128] = { 0 };
		//Số bit lấy
		int count = 127 - i;
		//Lấy ra các bit đầu
		for (int j = 0; j <= count; j++)
		{
			temp[j] = bitsA[j + i];
		}
		//Lấy các bit đó trừ cho số chia
		Sub(temp, bitsB, temp);
		//
		if (temp[127] == 1)
			bitsResult[i] = 0;

		else if (temp[127] == 0)
		{
			bitsResult[i] = 1;

			for (int j = 0; j <= count; j++)
			{
				bitsA[j + i] = temp[j];
			}
		}

	}
	if (flagA != flagB) //Nếu 2 số trái dấu thì lấy số đối của thương
		ConvertTwoComplement(bitsResult, bitsResult);

	string strResult;

	for (int i = 127; i >= 0; i--)
		strResult += (bitsResult[i] + '0');

	result.In(strResult, 2);

	return result;
}




void QInt::ConvertBitToArray(char array[])
{
	
	int curPos = 3;
	int checkBit = 0;

	for (int i = 0; i < 128; i++)
	{
		array[i] = 1 & (_arrayBits[curPos] >> checkBit);
		checkBit++;
		if (checkBit == 32)
		{
			checkBit = 0;
			curPos--;
		}
	}
}


string QInt::Convert(string strData, int base1, int base2)
{
	this->In(strData, base1);
	return this->Out(base2);
}


string QInt::HexToBin(string str)
{
	string bin;
	for (int i = 0; i < str.length() ; i++)
	{
		string temp;
		switch (str[i])
		{
		case '0':
			temp = "0000";
			break;
		case '1':
			temp = "0001";
			break;
		case '2':
			temp = "0010";
			break;
		case '3':
			temp = "0011";
			break;
		case '4':
			temp = "0100";
			break;
		case '5':
			temp = "0101";
			break;
		case '6':
			temp = "0110";
			break;
		case '7':
			temp = "0111";
			break;
		case '8':
			temp = "1000";
			break;
		case '9':
			temp = "1001";
			break;
		case'A': case'a':
			temp = "1010";
			break;
		case 'B': case'b':
			temp = "1011";
			break;
		case 'C': case'c':
			temp = "1100";
			break;
		case 'D': case'd':
			temp = "1101";
			break;
		case 'E':case 'e':
			temp = "1110";
			break;
		case 'F':case 'f':
			temp = "1111";
			break;
		default:
			cout << "#";
			break;
		}
		bin += temp;
		temp.clear();
	}
	return bin;
}


QInt QInt::operator<<(int n)
{
	
	string str;

	char bits[128] = { 0 };

	ConvertBitToArray(bits);

	char temp[128] = { 0 };
	DichPhaiTrenMang(bits, temp, n);

	for (int i = 127; i >= 0; i--)
		str += (temp[i] + 48);

	this->In(str, 2);

	return *this;
}
QInt QInt::operator>>(int n)
{
	
	string str;

	bool flag = true;//true-số dương, false-số âm
	char bits[128] = { 0 };

	ConvertBitToArray(bits);
	if (bits[127] == 1)
	{
		flag = false;
	}

	char temp[128] = { 0 };
	DichTraiTrenMang(bits, temp, n);

	for (int i = 127; i >= 0; i--)
	{
		if (127 - i < n && flag == false)
		{
			temp[i] = 1;
		}
		str += (temp[i] + 48);
		
	}
	
	this->In(str, 2);

	return *this;

}
QInt QInt::operator&(QInt other)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result._arrayBits[i] = _arrayBits[i] & other._arrayBits[i];
	}
	return result;
}
QInt QInt::operator^(QInt other)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result._arrayBits[i] = _arrayBits[i] ^ other._arrayBits[i];
	}
	return result;
}
QInt QInt::operator|(QInt other)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result._arrayBits[i] = _arrayBits[i] | other._arrayBits[i];
	}
	return result;
}
QInt QInt::operator~()
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result._arrayBits[i] =  ~ _arrayBits[i];
	}
	for (int i = 0; i < 4; i++)
	{
		_arrayBits[i] = result._arrayBits[i];
	}
	return *this;
}

void QInt::rol()
{
	int lastBit = 0;
	if ((_arrayBits[0] >> 31) & 1 == 1)
	{
		lastBit = 1;
	}
	*this << 1;
	if (lastBit == 1)
	{
		_arrayBits[3] = _arrayBits[3] | 1;
	}
}
void QInt::ror()
{
	int firstBit = 0;
	if (_arrayBits[3] & 1 == 1)
	{
		firstBit = 1;
	}
	*this >> 1;
	if (firstBit == 1)
	{
		_arrayBits[0] = _arrayBits[0] | (1 << 31);
	}
}


QInt& QInt::operator=(QInt other)
{
	// TODO: insert return statement here
	this->_arrayBits[0] = other._arrayBits[0];
	this->_arrayBits[1] = other._arrayBits[1];
	this->_arrayBits[2] = other._arrayBits[2];
	this->_arrayBits[3] = other._arrayBits[3];
	return *this;
}



