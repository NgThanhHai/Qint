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
		array[i] = 1 & (_arrayBits[i] >> tranBit);
		if (tranBit == 32)
		{
			tranBit = 0;
			arraySize--;
		}
	}
	string returnStr;
	for (int i = 128; i >= 0; i--)
	{
		returnStr += array[i];
	}
	return returnStr;
}