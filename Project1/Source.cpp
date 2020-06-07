#include <iostream>
#include <vector>
#include "Qint.h"
using namespace std;

void main()
{
	
	string bin = "-4647";
	QInt a;
	a.In(bin, 10);
	cout << a.Out(10) << endl;
	cout << "*" << endl;
	QInt b;
	b.In("4302371896916613314517792614108589", 10);
	cout << b.Out(10) << endl;
	QInt d = b * a;
	cout<<d.Out(10);
}