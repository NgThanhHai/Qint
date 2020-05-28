#include <iostream>
#include <vector>
#include "Qint.h"
using namespace std;

void main()
{
	const char* inputFile = "input.txt";
	freopen(inputFile, "r+", stdin);

	string s1;
	string s2;
	string s3;
	string s4;
	vector <string> result;
	while (cin >> s1)
	{
		cin >> s2;
		if (s2 == "2" || s2 == "10" || s2 == "16")
		{
			cin >> s3;
			if (s1 == "10")
			{
				if (s2 == "2")
				{
					// dec to bin
					// push back
				}
				if (s2 == "16")
				{
					// dec to hex
					// pushback
				}
				if (s2 == "10")
				{
					// push back
				}
			}
			if (s1 == "2")
			{
				if (s2 == "10")
				{
					// bin to dec
					// push back
				}
				if (s2 == "16")
				{
					// bin to hex
					// pushback
				}
				if (s2 == "2")
				{
					// push back
				}
			}
			if (s1 == "16")
			{
				if (s2 == "2")
				{
					// hex to bin
					// push back
				}
				if (s2 == "10")
				{
					// hex to dec
					// pushback
				}
				if (s2 == "16")
				{
					// pushback
				}
			}
		}
		else if (s2 != "~")
		{
			cin >> s3;
			cin >> s4;
			if (s1 == "2")
			{
				if (s2 == "ror")
				{
					// ror
					// push back
				}
				else if (s2 == "rol")
				{
					// rol
					// push back
				}
				else if (s3 == "+")
				{
					// bin plus
					// push back
				}
				if (s3 == "-")
				{
					// bin minus
					// push back
				}
				if (s3 == "*")
				{
					// bin multiplied
					// push back
				}
				if (s3 == "/")
				{
					// bin divided
					// push back
				}

				else if (s3 == ">")
				{
					// greater
					// push back
				}
				else if (s3 == "<")
				{
					// less
					// push back
				}
				else if (s3 == "==")
				{
					// equal
					// push back
				}
				else if (s3 == "<=")
				{
					// less or equal
					// push back
				}
				else if (s3 == ">=")
				{
					// greater or equal
					// push back
				}
				else if (s3 == ">>")
				{
					// right 
					// push back
				}
				else if (s3 == "<<")
				{
					// left
					// push back
				}
				else if (s3 == "&")
				{
					// and
					// push back
				}
				else if (s3 == "|")
				{
					// or
					// push back
				}
				else if (s3 == "^")
				{
					// xor
					// push back
				}
			}
			if (s1 == "10")
			{
				if (s2 == "ror")
				{
					// ror
					// push back
				}
				else if (s2 == "rol")
				{
					// rol
					// push back
				}
				else if (s3 == "+")
				{
					// dec plus
					// push back
				}
				if (s3 == "-")
				{
					// dec minus
					// push back
				}
				if (s3 == "*")
				{
					// dec multiplied
					// push back
				}
				if (s3 == "/")
				{
					// dec divided
					// push back
				}

				else if (s3 == ">")
				{
					// greater
					// push back
				}
				else if (s3 == "<")
				{
					// less
					// push back
				}
				else if (s3 == "==")
				{
					// equal
					// push back
				}
				else if (s3 == "<=")
				{
					// less or equal
					// push back
				}
				else if (s3 == ">=")
				{
					// greater or equal
					// push back
				}
				else if (s3 == ">>")
				{
					// right 
					// push back
				}
				else if (s3 == "<<")
				{
					// left
					// push back
				}
				else if (s3 == "&")
				{
					// and
					// push back
				}
				else if (s3 == "|")
				{
					// or
					// push back
				}
				else if (s3 == "^")
				{
					// xor
					// push back
				}
			}
			if (s1 == "16")
			{
				if (s2 == "ror")
				{
					// ror
					// push back
				}
				else if (s2 == "rol")
				{
					// rol
					// push back
				}
				else if (s3 == "+")
				{
					// hex plus
					// push back
				}
				else if (s3 == "-")
				{
					// hex minus
					// push back
				}
				else if (s3 == "*")
				{
					// hex multiplied
					// push back
				}
				else if (s3 == "/")
				{
					// hex divided
					// push back
				}
				else if (s3 == ">")
				{
					// greater
					// push back
				}
				else if (s3 == "<")
				{
					// less
					// push back
				}
				else if (s3 == "==")
				{
					// equal
					// push back
				}
				else if (s3 == "<=")
				{
					// less or equal
					// push back
				}
				else if (s3 == ">=")
				{
					// greater or equal
					// push back
				}
				else if (s3 == ">>")
				{
					// right 
					// push back
				}
				else if (s3 == "<<")
				{
					// left
					// push back
				}
				else if (s3 == "&")
				{
					// and
					// push back
				}
				else if (s3 == "|")
				{
					// or
					// push back
				}
				else if (s3 == "^")
				{
					// xor
					// push back
				}
			}
			

		}
		else if (s2 == "~")
		{
			cin >> s3;
			if (s1 == "10")
			{
				// not hec
				// push back
			}
			else if (s1 == "2")
			{
				// not bin
				// push back
			}
			else if (s1 == "16")
			{
				// not hex
				// push back
			}
		}
	}
}