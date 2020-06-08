#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class QInt
{
private:
	int	_arrayBits[4];

	void ConvertBitToArray(int array[]);
public:
	QInt();

	void In(string strData, int base);
	string Out(int base);

	string Convert(string strData, int base1, int base2);

	string DecToBin();
	
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
	
	bool operator<(QInt);
	
	void rol();
	void ror();

	friend QInt operator+(QInt a, QInt b);
	
	friend QInt operator-(QInt a, QInt b);
	friend QInt operator*(QInt a, QInt b);
	friend QInt operator/(QInt a, QInt b);
	QInt& operator=(QInt other);

};


string chia2(string s);
string myPow(int n);
string multiple2(string s);
string plusNumInStr(string a, string b);
void Add(int bits1[], int bits2[], int result[]);
void Sub(int bits1[], int bits2[], int result[]);
void ConvertTwoComplement(int bitsSource[], int bitsDes[]);
void DichPhaiTrenMang(int arrSource[],int arrDes[], int k); 
void DichTraiTrenMang(int arrSource[], int arrDes[], int k);

vector<string> Parse(string line);
