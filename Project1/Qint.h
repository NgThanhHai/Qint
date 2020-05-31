#pragma once
#include <iostream>
#include <string>
using namespace std;
class QInt
{
private:
	int	_arrayBits[4];
public:
	QInt();
	string DecToBin();
	QInt BinToDec(string);
	string HexToBin(string);

	string BinToHex();
	string DecToHex();
	QInt HexToDec();

	QInt& operator=(string);
	QInt operator<<(int);
	QInt operator>>(int);
	QInt operator^(QInt);
	QInt operator|(QInt);
	QInt operator~();
	QInt operator&(QInt)

};

