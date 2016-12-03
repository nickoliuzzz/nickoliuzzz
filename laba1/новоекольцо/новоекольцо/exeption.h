#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class exeption
{
	char ms2[30];
public:
	exeption(char * ms1)
	{
		strcpy_s(ms2, ms1);
	}
	friend ostream& operator<<(ostream &my, const exeption& tmp)
	{
		cout << tmp.ms2;
		return my;
	}
};

