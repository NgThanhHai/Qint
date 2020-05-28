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
	static QInt BinToDec();
	static string HexToBin();

	static string BinToHex();
	string DecToHex();
	static QInt HexToDec();

	QInt operator=(string s);
};

