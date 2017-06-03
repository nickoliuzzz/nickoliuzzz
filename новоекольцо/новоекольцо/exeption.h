#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
static int nak = 0;
using namespace std;

class exeption
{
	char ms2[30];
	int n;
public:
	exeption(char * ms1,int k)
	{
		n = k;
		strcpy_s(ms2, ms1);
	}
	int re() { return n; }
	friend ostream& operator<<(ostream &my, const exeption& tmp)
	{
		cout << "Ошибка" << tmp.ms2 << " номер " << tmp.n << endl;
		return my;
	}
};

class exeptfile : public exeption
{
public :
	exeptfile(char * ms1, int k) : exeption(ms1, k) {};

};

class exeptkorzina : public exeption
{
public:
	exeptkorzina(char * ms1, int k) : exeption(ms1, k) {};
};

class exeptshablon :public exeption
{
public:
	exeptshablon(char * ms1, int k) : exeption(ms1,k) {};
};


class exeptfiles :public exeption
{
public:
	exeptfiles(char * ms1, int k) : exeption(ms1, k) {};
};
class exeptionkart : public exeption
{
public:
	exeptionkart(char * ms1, int k) : exeption(ms1, k) {};
	int ret() { return re(); }
};