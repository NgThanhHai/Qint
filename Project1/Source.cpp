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
				vector<string> tokens = Parse(line);

				if (tokens.size() == 3)
				{
					//Xu li cac dong co 3 tham so
					if (tokens[1] == "~") //not
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[2], base);
						~x;
						fileOut << x.Out(base) << endl;
					}
					else if (tokens[1] == "ror")
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[2], base);
						x.ror();
						fileOut << x.Out(base) << endl;
					}
					else if (tokens[1] == "rol")
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[2], base);
						x.rol();
						fileOut << x.Out(base) << endl;
					}
					else //Chuyen co so
					{
						QInt x;
						int base1 = stoi(tokens[0]);
						int base2 = stoi(tokens[1]);
						fileOut << x.Convert(tokens[2], base1, base2) << endl;

					}
				}
				else if (tokens.size() == 4)
				{
					//Xu li cac dong co 4 tham so
					if (tokens[2] == "+")
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a + b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "-")
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a - b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "*")
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a * b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "/")
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a / b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "^")
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a ^ b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "|")
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a | b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "&")
					{
						QInt a, b;
						int base = stoi(tokens[0]);
						a.In(tokens[1], base);
						b.In(tokens[3], base);
						QInt result = a & b;
						fileOut << result.Out(base) << endl;
					}
					else if (tokens[2] == "<<")
					{
						QInt x;
						int base = stoi(tokens[0]);
						x.In(tokens[1], base);
						int sBit = stoi(tokens[3]);
						x << sBit;
						fileOut << x.Out(base) << endl;
					}
					else if (tokens[2] == ">>")
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
