#include <iostream>
#include <vector>
#include <fstream>
#include "Qint.h"
using namespace std;

void main(int argc, char* argv[])
{
	
	ifstream fileIn;
	ofstream fileOut;

	fileIn.open(argv[1], ios::in);
	fileOut.open(argv[2], ios::out);

	if (!fileIn)
		cout << "Khong tim thay file input" << endl;
	else
		cout << "Doc thanh cong" << endl;

	if (!fileOut)
		cout << "Khong tim thay file output" << endl;
	else
		cout << "Doc thanh cong" << endl;

	if (fileIn && fileOut)
	{
		while (!fileIn.eof())
		{
			string line;
			char lineTemp[255];
			fileIn.getline(lineTemp, 255);

			if (strcmp(lineTemp, "") != 0)
			{
				line = lineTemp;
				vector<string> tokens = Parse(line," ");

				if (tokens.size() == 3)
				{
					//Xử lí các dòng có 3 tham số
					if (tokens[1] == "~") //not
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[2], base);
						~x;
						fileOut << x.Out(base) << endl;
					}
					else if (tokens[1] == "ror") //quay phải
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[2], base);
						x.Ror();
						fileOut << x.Out(base) << endl;
					}
					else if (tokens[1] == "rol") //quay trái
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[2], base);
						x.Rol();
						fileOut << x.Out(base) << endl;
					}
					else //Chuyển đổi cơ số
					{
						QInt x;
						int base1 = stoi(tokens[0]);
						int base2 = stoi(tokens[1]);
						fileOut << x.Convert(tokens[2], base1, base2) << endl;

					}
				}
				else if (tokens.size() == 4)
				{
					//Xử lí các dòng có 4 tham số
					if (tokens[2] == "+") //+
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a + b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "-") //-
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a - b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "*") //*
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a * b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "/") // /
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a / b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "^") // ^ XOR
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a ^ b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "|") // | OR
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a | b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "&") // & AND
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a & b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "<<") // << dịch trái
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[1], base);
						int sBit = stoi(tokens[3]);
						x << sBit;
						fileOut << x.Out(base) << endl;
					}
					else if (tokens[2] == ">>") // >> dịch phải số học
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[1], base);
						int sBit = stoi(tokens[3]);
						x >> sBit;
						fileOut << x.Out(base) << endl;
					}
				}
			}
		}

		fileIn.close();
		fileOut.close();
	}

	
}
