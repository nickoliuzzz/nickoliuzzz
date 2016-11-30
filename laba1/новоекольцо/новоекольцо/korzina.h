#pragma once
#include "list.h"

int f = 0;
class product
{
protected:
	char ms[15];
	int stoim, kod;
public:
	product() {};

	virtual bool operator<(const product& tmp)
	{
		if (stoim < tmp.stoim) return true;
		return false;
	}
	int getstoim() { return stoim; }
	void setkod(int k)
	{
		kod = k;
	}

	virtual void koder() { setkod(25 * 100000 + f++); }

	product(char *naz)
	{
		strcpy_s(ms, naz);
		koder();
	}

	product(char *naz, int st)
	{
		strcpy_s(ms, naz);
		stoim = st;
		koder();
	}


	~product() {};
	void changename(char *str)
	{
		strcpy_s(ms, str);
	}

	friend ostream& operator<<(ostream &my, product& tmp)
	{
		my << setw(10) << tmp.kod << setw(25) << tmp.ms << setw(10) << tmp.stoim;
		return my;
	}

	void setstoim(int i)
	{
		stoim = i;
	}
};




class milk :public product
{
	char firma[20];
	int srok;							//srok godnosti
public:
	void koder() { setkod(25 * 10000 + 100 + f++); }
	bool operator<(const milk& tmp)
	{
		if (stoim < tmp.stoim) return true;
		return false;
	}
	milk(char * ms, int sr,char * naz)	: product (naz)
	{
		strcpy_s(firma, ms);
		srok = sr;
		koder();
	}
	~milk() {};
	bool goden()
	{
		if (srok > 0) return true;
		return false;
	}
	friend ostream& operator<<(ostream &my, milk& tmp)
	{
		my << setw(10) << tmp.kod << setw(15) << tmp.ms << setw(10) << tmp.firma << setw(10) << tmp.stoim;
		return my;
	}
};






class baton :public product 
{
	double mass;
	int number;
	bool narazves;
	int sps;        //stoim per shtuka ili za kilogramm
public:
	void koder() { setkod(25 * 10000 + 200 + f++); }
	baton(double mas, int stoimo,char *naz);
	baton(int kol, int sps,char *naz);
	baton() { koder(); };
	bool operator<(const baton& tmp)
	{
		if (stoim < tmp.stoim) return true;
		return false;
	}
	~baton() {};
	void setmass(double gramm) { mass = gramm; }
	void setnumber(int numb) { number = numb; }
	void setves(bool ifer) { narazves = ifer; }
	void setsps(int ss) { sps = ss; }
	friend ostream& operator<<(ostream &my, baton& tmp)
	{
		my << setw(10) << tmp.kod << setw(25) << tmp.ms << setw(10) << tmp.stoim;
		return my;
	}
};





class korzina
{

	ring<product> prod;
	ring<baton> bat;
	ring<milk> mil;
public:
	korzina();
	void add(product ms1);
	void add(baton ms1);
	void add(milk ms1);
	int raschet();
};






class kartochka :public korzina
{
	int money;
	char pass[5];
	int tryes;
	int stoim;
	bool transakciia;
public:
	void setpass(char *pass1) { pass[0] = pass1[0], pass[1] = pass1[1], pass[2] = pass1[2], pass[3] = pass1[3], pass[4] = '\0'; tryes = 3; }
	bool unlock();
	int balans();
};
