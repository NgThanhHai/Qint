#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "function.h"
using namespace std;
class QInt
{
private:
	int	_arrayBits[4];

	void ConvertBitToArray(char array[]);
public:
	QInt();

	void In(string strData, int base);
	string Out(int base);

	string Convert(string strData, int base1, int base2);
	string HexToBin(string);

	QInt operator<<(int);
	QInt operator>>(int);
	QInt operator^(QInt);
	QInt operator|(QInt);
	QInt operator~();
	QInt operator&(QInt);
	
	void rol();
	void ror();

	friend QInt operator+(QInt a, QInt b);
	friend QInt operator-(QInt a, QInt b);
	friend QInt operator*(QInt a, QInt b);
	friend QInt operator/(QInt a, QInt b);
	QInt& operator=(QInt other);

};



