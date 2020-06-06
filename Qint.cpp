#include "Qint.h"
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


QInt::QInt()
{
	_arrayBits[0] = 0;
	_arrayBits[1] = 0;
	_arrayBits[2] = 0;
	_arrayBits[3] = 0;
}

void QInt::In(string strData, int base)
{
	if (base == 2)
	{
		//Xử lí nhập cơ số 2

		int curPos = 0;
		int checkBit = 0;
		for (int i = 0; i < strData.length() - 1; i++)
		{
			_arrayBits[curPos] = _arrayBits[curPos] | ((strData[i] - 48) << checkBit);
			checkBit++;
			if (checkBit == 32)
			{
				checkBit = 0;
				curPos++;
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
	}
}

string QInt::Out(int base)
{
	if (base == 2)
	{
		//Xử lí xuất _arrBit sang hệ 2
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


		string result = "0";
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
		return result;
	}
	else if (base == 16)
	{
		//Xử lí xuất -arrBit sang hệ 16
	}
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

QInt QInt::BinToDec(string binStr)
{
	
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
	this->BinToDec(bin);
	return *this;
}
QInt QInt::operator<<(int n)
{
	if (n < 0)
	{
		exit(0);
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
		{
			_arrayBits[i] = _arrayBits[i] << n;
		}
		else
		{
			_arrayBits[i] = _arrayBits[i] << n | _arrayBits[i + 1] >> (32 - n);
		}
	}
	return *this;
}
QInt QInt::operator>>(int n)
{
	if (n < 0)
	{
		exit(0);
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
		{
			_arrayBits[i] = _arrayBits[i] >> n;
		}
		else
		{
			_arrayBits[i] = _arrayBits[i] >> n | _arrayBits[i + 1] << (32 - n);
		}
	}
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



