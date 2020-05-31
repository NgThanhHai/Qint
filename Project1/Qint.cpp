#include "Qint.h"

QInt::QInt()
{
	_arrayBits[0] = 0;
	_arrayBits[1] = 0;
	_arrayBits[2] = 0;
	_arrayBits[3] = 0;
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
	int arraySize = 0;
	int tranBit = 0;
	for (int i = 0; i < binStr.length()-1; i++)
	{
		_arrayBits[arraySize] = _arrayBits[arraySize] | ((binStr[i] - 48) >> tranBit);
		tranBit++;
		if (tranBit == 32)
		{
			tranBit = 0;
			arraySize++;
		}
	}
	return *this;
}

string QInt::HexToBin(string str)
{
	string bin;
	for (int i = 0; i < str.length() - 1; i++)
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
};
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
