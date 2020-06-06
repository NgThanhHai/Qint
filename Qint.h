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

	void In(string strData, int base);
	string Out(int base);

	string Convert(string strData, int base1, int base2);

	string DecToBin();
	QInt BinToDec(string);
	string HexToBin(string);

	string BinToHex(string);
	string DecToHex();
	QInt HexToDec(string);

	QInt& operator=(string);
	QInt operator<<(int);
	QInt operator>>(int);
	QInt operator^(QInt);
	QInt operator|(QInt);
	QInt operator~();
	QInt operator&(QInt);
	bool operator==(QInt);
	bool operator<(QInt);
	bool operator<=(QInt);
	bool operator>(QInt);
	bool operator>=(QInt);
	bool operator!=(QInt);
	void rol();
	void ror();

};


string chia2(string s);
string myPow(int n);
string multiple2(string s);
string plusNumInStr(string a, string b);
