#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Div2(string s);
string MyPow(int n);
string Mulp2(string s);
string AddStr(string a, string b);
void Add(char bits1[], char bits2[], char result[]);
void Sub(char bits1[], char bits2[], char result[]);
void ConvertTwoComplement(char bitsSource[], char bitsDes[]);
void DichPhaiTrenMang(char arrSource[], char arrDes[], int k);
void DichTraiTrenMang(char arrSource[], char arrDes[], int k);

vector<string> Parse(string line, string seperator);

