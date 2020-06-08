#include "Qint.h"
QInt operator+( QInt a,  QInt b)
{
	QInt sum;
	int bitsA[128] = { 0 }; //127 là bit dấu
	int bitsB[128] = { 0 };
	a.ConvertBitToArray(bitsA);
	b.ConvertBitToArray(bitsB);

	
	int bitsSum[128] = { 0 };
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
	int bitsA[128] = { 0 }; //127 là bit dấu
	int bitsB[128] = { 0 };
	a.ConvertBitToArray(bitsA);
	b.ConvertBitToArray(bitsB);

	//Chuyển B sang số bù 2
	

	int bitResult[128] = { 0 };
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

	int bitsResult[128] = { 0 };
	int bitsA[128] = { 0 }; //127 là bit dấu
	int bitsB[128] = { 0 };
	a.ConvertBitToArray(bitsA);
	b.ConvertBitToArray(bitsB);
	for (int i = 0; i < 128; i++)
	{
		if (bitsB[i] == 1)
		{
			
			int temp[128] = { 0 };
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

	int bitsResult[128] = { 0 };
	int bitsA[128] = { 0 }; //127 là bit dấu
	int bitsB[128] = { 0 };
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
		int temp[128] = { 0 };
		//Số bit lấy
		int count = 127 - i;
		//Lấy ra các bit đầu
		for (int j = 0; j <= count; j++)
		{
			temp[j] = bitsA[j + i];
		}
		//Lấy các bit đó trừ cho số chia
		Sub(temp, bitsB, temp);
		//if()
		if (temp[127] == 1)
		{
			bitsResult[i] = 0;
		}
		else if (temp[127] == 0)
		{
			bitsResult[i] = 1;
			for (int j = 0; j <= count; j++)
			{
				bitsA[j + i] = temp[j];
			}
		}

	}
	if (flagA != flagB)
	{
		ConvertTwoComplement(bitsResult, bitsResult);
	}
	string strResult;

	for (int i = 127; i >= 0; i--)
	{
		strResult += (bitsResult[i] + '0');
	}
	result.In(strResult, 2);

	return result;
}

string chia2(string s)
{
	string temp;
	int divisor = 0;
	if (s.length() == 1)
	{
		divisor = s[0] - 48;
		temp += (divisor / 2) + 48;
	}
	else
	{
		int i = 0;
		divisor = s[0] - 48;
		for (int i = 0; i < s.length() - 1; i++)
		{
			if (divisor < 2)
			{
				i++;
				divisor = (divisor * 10) + (s[i] - 48);

			}
			char c = (divisor / 2) + 48;
			temp += c;
			divisor = divisor % 2;
			i--;
		}
	}
	s = temp;
	return s;

}
string myPow(int n) //n là số mũ
{
	string temp = "2";
	if (n == 0)
		return "1";
	if (n == 1)
		return "2";
	for (int i = 0; i < n - 1; i++)
	{
		temp = multiple2(temp);
	}
	return temp;
}
string multiple2(string s)
{
	int temp = 0, carry = 0;;
	int _length = s.length();
	int a_size = _length + 1;
	int* a = new int[a_size];
	string result;
	for (int i = 0; i < a_size; i++)
		a[i] = 0;
	for (int i = _length - 1; i >= 0; i--)
	{
		temp = (s[i] - '0') * 2;
		if (carry == 1)
			temp++;
		if (temp > 9)
			carry = 1;
		else
			carry = 0;
		a[i + 1] += temp % 10;

	}
	if (carry == 1)
	{
		a[0] = 1;
	}
	else
	{
		for (int i = 0; i < a_size - 1; i++)
			a[i] = a[i + 1];
		a_size--;
	}
	for (int i = 0; i < a_size; i++)
	{
		result += (a[i] + '0');
	}
	return result;
}
string plusNumInStr(string a, string b)
{
	string result; //biến chứa kết quả

	int i = a.length() - 1;
	int j = b.length() - 1;
	int nho = 0;
	while (i >= 0 && j >= 0) //Vòng lặp cộng các chữ số ở cuối của a, b 
	{
		int temp = (a[i] - 48) + (b[j] - 48) + nho;
		char c = (temp % 10) + 48;
		if (temp > 9)
		{
			nho = 1;
		}
		else
			nho = 0;
		result += c;
		i--;
		j--;
	}

	// Trường hợp số a nhiều chữ số hơn
	while (i >= 0)
	{
		int temp = (a[i] - 48) + nho;
		char c = (temp % 10) + 48;
		if (temp > 9)
		{
			nho = 1;
		}
		else
			nho = 0;
		result += c;
		i--;
	}

	//Trường hợp số b nhiều chữ số hơn
	while (j >= 0)
	{
		int temp = (b[j] - 48) + nho;
		char c = (temp % 10) + 48;
		if (temp > 9)
		{
			nho = 1;
		}
		else
			nho = 0;
		result += c;
		j--;
	}

	// Nếu sau khi cộng xong mà vẫn còn nhớ 1 thì ghi thêm 1 vào kết quả
	if (nho == 1)
	{
		result += "1";
	}

	reverse(result.begin(), result.end()); //Vì kết quả lưu ngược nên phải đảo chuỗi cho đúng 
	return result;
}


void QInt::ConvertBitToArray(int array[])
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
		char a[128] = { 0 };
		int i = 0;

		if (strData[0] != '-')
		{
			while (strData != "0")
			{
				//Xét số cuối cùng của chuỗi, nếu là số chẵn khi chia 2 sẽ dư 0 
				if ((strData[strData.length() - 1] - 48) % 2 == 0)
				{
					a[i] = 0;
					i++;
				}
				//Nếu là số lẻ, chia 2 sẽ dư 1
				else
				{
					a[i] = 1;
					i++;
				}

				//Chia chuỗi s cho 2
				strData = chia2(strData);
				if (i > 127)
				{
					throw "Stack Overflow";
				}

			};
			a[127] = 0; //Bit dấu
		}
		else //Số nhập vào là số âm
		{
			string positive_s;
			for (int i = 1; i < strData.length(); i++) //Lấy phần sau dấu âm của số
			{
				positive_s += strData[i];
			}
			i = 0;
			while (positive_s != "0")
			{
				//Xét số cuối cùng của chuỗi, nếu là số chẵn khi chia 2 sẽ dư 0 
				if ((positive_s[positive_s.length() - 1] - 48) % 2 == 0)
				{
					a[i] = 0;
					i++;
				}
				//Nếu là số lẻ, chia 2 sẽ dư 1
				else
				{
					a[i] = 1;
					i++;
				}

				//Chia chuỗi s cho 2
				positive_s = chia2(positive_s);
				if (i > 128)
				{
					throw "Stack Overflow";
				}

			};
			a[127] = 1; //Bit dấu
			int dem = i;
			// Đảo bit thành dạng bù 1
			for (int i = 0; i < 127; i++)
			{
				if (a[i] == 1)
				{
					a[i] = 0;
				}
				else
				{
					a[i] = 1;
				}
			}

			//Cộng 1 vào kết quả thành dạng bù 2
			for (int i = 0; i < 127; i++)
			{
				if (a[i] == 1)
				{
					a[i] = 0;
				}
				else
				{
					a[i] = 1;
					break;
				}
			}
			if (dem == 126)
			{
				a[0] = 0;
			}
		}

		// Bật các bit của data bằng cách OR với giá trị của mảng a tương ứng, bit dấu a[127]
		int count = 0;
		int d = 0;
		for (int i = 127; i >= 0; i--)
		{
			_arrayBits[d] = _arrayBits[d] | (a[i] << (32 - 1 - count));
			count++;
			if (count == 32)
			{
				count = 0;
				d++;
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

	if (base == 2)
	{
	
		//Xử lí xuất _arrBit sang hệ 2
		int bits[128] = { 0 };
		int curPos = 3;
		int checkBit = 0;

		for (int i = 0; i < 128; i++)
		{
			bits[i] = 1 & (_arrayBits[curPos] >> checkBit);
			checkBit++;
			if (checkBit == 32)
			{
				checkBit = 0;
				curPos--;
			}
		}

		for (int i = 127; i >= 0; i--)
		{
			result += (bits[i] + 48);
		}

		//return result;
		//Xuất chuỗi từ bit 1 đầu tiên.
		

	}
	else if (base == 10)
	{
		//Xử lí xuất _arrBit sang hệ 10
		unsigned int a[128] = { 0 };
		// Đọc các bit của data lưu vào mảng a, bit dấu là bit a[127]
		int d = 3, count = 0;
		for (int i = 0; i < 128; i++)
		{
			a[i] = 1 & (_arrayBits[d] >> count);
			count++;
			if (count == 32)
			{
				count = 0;
				d--;
			}
		}


		result = "0";
		string temp;
		if (a[127] == 0) //Bit dấu = 0
		{
			for (int i = 0; i < 127; i++)
			{
				if (a[i] == 1)
				{
					temp = myPow(i);
					result = plusNumInStr(result, temp);
				}
			}
		}
		else //Bit dấu = 1
		{
			// Trừ 1 để thành dạng bù 1
			for (int i = 0; i < 128; i++)
			{
				if (a[i] == 0)
				{
					a[i] = 1;
				}
				else
				{
					a[i] = 0;
					break;
				}
			}
			// Đảo bit
			for (int i = 0; i < 128; i++)
			{
				if (a[i] == 1)
					a[i] = 0;
				else
					a[i] = 1;
			}

			for (int i = 0; i < 128; i++) //Tính giá trị như dạng không dấu
			{
				if (a[i] == 1)
				{
					temp = myPow(i);
					result = plusNumInStr(result, temp);
				}
			}
			reverse(result.begin(), result.end()); //Đảo chuỗi
			result += "-"; //Thêm dấu âm vào cuối chuỗi
			reverse(result.begin(), result.end()); //Đảo chuỗi cho đúng kết quả
			if (result == "-0")
			{

			}
		}
		//return result;
	}
	else if (base == 16)
	{
		//Xử lí xuất _arrBit sang hệ 16
		//
		int bits[128] = { 0 };
		int curPos = 3;
		int checkBit = 0;

		for (int i = 0; i < 128; i++)
		{
			bits[i] = 1 & (_arrayBits[curPos] >> checkBit);
			checkBit++;
			if (checkBit == 32)
			{
				checkBit = 0;
				curPos--;
			}
		}
		//

		for (int i = 31; i >=0; i--)
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
		
		//return result;


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

string QInt::Convert(string strData, int base1, int base2)
{
	this->In(strData, base1);
	return this->Out(base2);
}

string QInt::DecToBin()
{
	int array[128] = { 0 };
	int arraySize = 3;
	int tranBit = 0;

	for (int i = 0; i < 128; i++)
	{
		array[i] = 1 & (_arrayBits[arraySize] >> tranBit);
		tranBit++;
		if (tranBit == 32)
		{
			tranBit = 0;
			arraySize--;	
		}
	}

	string returnStr;

	for (int i = 128; i >= 0; i--)
	{
		returnStr += (array[i] + 48);
	}
	return returnStr;
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
string QInt::BinToHex(string bin)
{
	int binLength = bin.length();
	int hexLength = (binLength % 4 == 0) ? (binLength / 4) : (binLength / 4 + 1);

	char* listBit = new char[hexLength * 4];

	int posBin = binLength - 1;
	for (int i = 0; i < hexLength * 4; i++)
		listBit[i]=0;
	int pos = hexLength * 4 - 1;
	while (posBin >= 0)
	{
		listBit[pos] = bin[posBin]-48;
		posBin--;
		pos--;
	}
	string result;

	for (int i = 0; i < hexLength; i++)
	{
		int value = listBit[i * 4] * 8 + listBit[i * 4 + 1] * 4 + listBit[i * 4 + 2] * 2 + listBit[i * 4 + 3];
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
	delete[] listBit;
	return result;
}
string QInt::DecToHex()
{
	string bin=this->DecToBin();
	
	string result = BinToHex(bin);

	return result;
}
QInt QInt::HexToDec(string hex)
{
	string bin = HexToBin(hex);
	
	return *this;
}

QInt QInt::operator<<(int n)
{/*
	int array[4] = {0};
	for (int i = 0; i < 4; i++)
	{
		array[i] = array[i] | _arrayBits[i];
		
	}
	if (n < 0)
	{
		exit(0);
	}
	else if ( n == 0 )
	{
		return *this;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				_arrayBits[i] = _arrayBits[i] << n;
			}
			else
			{
				_arrayBits[i] = (_arrayBits[i] << n) | (array[i + 1] >> (32 - n));
			}
		}
	}
	return *this;*/
	string str;
	int bits[128] = { 0 };
	ConvertBitToArray(bits);
	int temp[128] = { 0 };
	DichPhaiTrenMang(bits, temp, n);
	for (int i = 127; i >= 0; i--)
	{
		str += (temp[i] + 48);
	}
	this->In(str, 2);
	return *this;
}
QInt QInt::operator>>(int n)
{
	/*if (n < 0)
	{
		exit(0);
	}
	else if ( n == 0 )
	{
		return *this;
	}
	else 
	{
		for (int i = 3; i >= 0; i--)
		{
			if (i == 0)
			{
				_arrayBits[i] = _arrayBits[i] >> n;
			}
			else
			{
				_arrayBits[i] = (_arrayBits[i] >> n) | (_arrayBits[i - 1] << (32 - n));
			}
		}
	}
	return *this;*/
	string str;
	bool flag = true;
	int bits[128] = { 0 };
	ConvertBitToArray(bits);
	if (bits[127] == 1)
	{
		flag = false;
	}
	int temp[128] = { 0 };
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
bool QInt::operator<(QInt other)
{
	if (_arrayBits[0] != other._arrayBits[0])
	{
		if (_arrayBits[0] == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}
	else
	{
	}
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

void Add(int bits1[], int bits2[], int result[])
{
	
	int mark = 0;
	for (int i = 0; i < 128; i++)
	{
		int sumBit = bits1[i] + bits2[i] + mark;

		result[i] = sumBit % 2;
		mark = sumBit / 2;
	}
}

void Sub(int bits1[], int bits2[], int result[])
{
	int temp[128] = { 0 };
	ConvertTwoComplement(bits2,temp);
	Add(bits1, temp, result);
}

void ConvertTwoComplement(int bitsSource[], int bitsDes[])
{
	for (int i = 0; i < 128; i++)
	{
		if (bitsSource[i] == 0)
			bitsDes[i] = 1;
		else if (bitsSource[i] == 1)
			bitsDes[i] = 0;
	}
	int temp[128] = { 0 }; temp[0] = { 1 };
	Add(bitsDes, temp, bitsDes);
}

void DichPhaiTrenMang(int arrSource[], int arrDes[], int k)
{
	
	int pos = 0;
	while (pos+k < 128)
	{
		arrDes[pos + k] = arrSource[pos];
		pos++;
	}
	
}

void DichTraiTrenMang(int arrSource[], int arrDes[], int k)// đối với bit dấu 127 là 0
{
	int pos = 127;
	while (pos - k >=0 )
	{
		arrDes[pos - k] = arrSource[pos];
		pos--;
	}
}

vector<string> Parse(string line)
{
	vector<string> tokens;

	string seperator = " ";
	int startPos = 0;
	//tham khao phan tach chuoi trong lab08 - OOP
	size_t foundPos = line.find(seperator, startPos);

	while (foundPos != string::npos)
	{
		int count = foundPos - startPos;
		string token = line.substr(startPos, count);

		tokens.push_back(token);
		startPos = foundPos + seperator.length();
		foundPos = line.find(seperator, startPos);
	}

	int count = line.length() - startPos;
	string token = line.substr(startPos, count);
	tokens.push_back(token);

	return tokens;
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



