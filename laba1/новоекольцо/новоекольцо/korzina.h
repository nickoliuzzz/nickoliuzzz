#pragma once
#include "C:\Users\�\documents\visual studio 2015\Projects\�����������\�����������\function.cpp"
#include <conio.h>
char pas[5] = { '1','2','3','4' };
int f = 0;
int bablo = 763300;						//��� �������
class product
{
protected:
	char ms[15];
	int stoim, kod;
public:
	product() {};
	product& operator=(const product &tmp)
	{
		strcpy_s(ms, tmp.ms);
		stoim = tmp.stoim;
		kod = tmp.kod;;
		return *this;
	}
	virtual bool operator<(const product& tmp)
	{
		if (stoim < tmp.stoim)
		{
			return true;
		}
		return false;
	}
	int getstoim() { return stoim; }
	void setkod(int k)
	{
		kod = k;
	}

	virtual void koder() { setkod(25 * 10000 + f++); }

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
		my << setw(10) << tmp.kod << setw(15) << tmp.ms << setw(30) << tmp.stoim << endl;
		return my;
	}
	friend istream& operator>>(istream &my,product &tmp)
	{
		cout << "������� �������� ��������:    ";
		my >> tmp.ms;
		cout << "������� ��������� ��������:    ";
		my >> tmp.stoim;
		tmp.kod = 25 * 10000 + f++;
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
	milk& operator=(const milk &tmp)
	{
		strcpy_s(ms, tmp.ms);
		stoim = tmp.stoim;
		kod = tmp.kod;
		srok = tmp.srok;
		strcpy_s(firma, tmp.firma);
		return *this;
	}

	milk(char * ms, int sr,char * naz, int cena)	: product (naz)
	{
		strcpy_s(firma, ms);
		srok = sr;
		koder();
		if (sr > 0) setstoim(cena);
		else setstoim(0);
	}
	~milk() {};
	bool goden()
	{
		if (srok > 0) return true;
		return false;
	}
	milk() { koder(); }
	friend ostream& operator<<(ostream &my, milk& tmp)
	{
		my << setw(10) << tmp.kod << setw(15) << tmp.ms << setw(10) << tmp.firma << setw(20) << tmp.stoim << endl;
		return my;
	}
	friend istream& operator>>(istream &my, milk& tmp)
	{
		cout << "������� �������� ��������:    ";
		my >> tmp.ms;
		cout << "������� ��������� ��������:    ";
		my >> tmp.stoim;
		cout << "�������� �����:    ";
		char ms3[10];
		my >> ms3;
		strcpy_s(tmp.firma,ms3);
		cout << "������� c������� ���� ����� �������� ��������:    ";
		my >> tmp.srok;
		if (tmp.srok < 0)
			tmp.stoim = 0;
		tmp.kod = (25 * 10000 + 100 + f++);
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
	baton& operator=(const baton &tmp)
	{
		strcpy_s(ms, tmp.ms);
		stoim = tmp.stoim;
		kod = tmp.kod;
		mass = tmp.mass;
		number = tmp.number;
		narazves = tmp.narazves;
		sps = tmp.sps;
		return *this;
	}
	bool getnarazves() { return narazves; }
	double getmass() { return mass; }
	int getnumber() { return number; }
	void koder() { setkod(25 * 10000 + 200 + f++); }
	baton(double mas, int stoimo, char *naz)
	{
		mass = mas;
		sps = stoimo;
		changename(naz);
		setves(true);
		int f = int(sps*mas + 0.5);
		setstoim(f);
		koder();
	};
	baton(int kol, int sp, char *naz)
	{
		number = kol;
		sps = sp;
		changename(naz);
		setves(false);
		setstoim(sp*kol);
		koder();
	};
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
		//if(tmp.getnarazves())
		//	my << setw(10) << tmp.kod << setw(15) << tmp.ms << setw(20) << tmp.getmass() <<setw(10)<< tmp.sps<< setw(10) << tmp.stoim;
		//else 
		my << setw(10) << tmp.kod << setw(15) << tmp.ms << setw(20) << tmp.sps << setw(10) << tmp.stoim;
		cout << endl;
		return my;
	}
	friend istream& operator>>(istream &my,baton& tmp)
	{
		char c;
		cout << "������� �������� ��������:    ";
		my >> tmp.ms;
		cout << "�������� ������� ��������(y|n):    ";
		do
		{
			c = _getch();
		} while (c != 'y' && c != 'n');
		cout << c;
		if (c == 'y')
		{
			cout << endl << "������� ��������� �������� �� �����:    ";
			my >> tmp.sps;
			tmp.narazves = true;
			cout << "������� ����� ��������:    ";
			my >> tmp.mass;
			tmp.stoim = int(tmp.mass*tmp.sps + 0.5);
			return my;
		}
		cout << endl << "������� ��������� �������� �� �����:    ";
		my >> tmp.sps;
		cout << "������� ���������� ��������� � ��������:    ";
		my >> tmp.number;
		tmp.narazves = false;
		tmp.stoim = tmp.sps * tmp.number;
		tmp.kod = (25 * 10000 + 200 + f++);
		return my;
	}
};





class korzina
{

	ring<product> prod;
	ring<baton> bat;
	ring<milk> mil;
public:
	korzina() 
	{
		prod.setname("��������");
		bat.setname("������� �����");
		mil.setname("�������� �����");
	};
	void add(product ms1) { prod.pushend(ms1); }
	void popprod() { prod.gettemp(); prod.pop(); }
	void goprod() { prod.gorig(); }
	void add(baton ms1) { bat.pushend(ms1); }
	void popbat() { bat.gettemp(); bat.pop(); }
	void gobat() { bat.gorig(); }
	void add(milk ms1) { mil.pushend(ms1); }
	void popmil() 
	{ 
		mil.gettemp();
		mil.pop(); 
	}
	void gomil() { mil.gorig(); };
	void popall() 
	{
		prod.cleanall(); 
		bat.cleanall(); 
		mil.cleanall(); 
	}
	int raschet() ;
	void sort()
	{
		bat.sort();
		mil.sort();
		prod.sort();
	}
	friend ostream& operator<<(ostream &my, korzina& tmp)
	{
		my << setw(10) << "��� ������." << setw(15) << "����. ������." << setw(10) << "�����  " << setw(10) << "�/(��|��)";
		my << setw(10) << "���������" << endl;
		my << tmp.prod;
		cout << tmp.mil;
		cout << tmp.bat;
		return my;
	}
};

int korzina::raschet()
{
	int n,sum=0;
	n = prod.getsize();
	for (int i = 0; i < n; i++)
	{
		sum += prod.gettemp().getstoim();
		prod.gorig();
	}
	n = mil.getsize();
	for (int i = 0; i < n; i++)
	{
		sum += mil.gettemp().getstoim();
		mil.gorig();
	}
	n = bat.getsize();
	for (int i = 0; i < n; i++)
	{
		sum += bat.gettemp().getstoim();
		bat.gorig();
	}
	return sum;
}




class kartochka :public korzina
{
	int money;
	char pass[5];
	int tryes;
	bool transakciia;
public:
	kartochka()
	{
		strcpy_s(pass, pas);
		money = bablo;
		tryes = 3;
		transakciia = true;
	}
	void setpass(char *pass1) { pass[0] = pass1[0], pass[1] = pass1[1], pass[2] = pass1[2], pass[3] = pass1[3], pass[4] = '\0'; tryes = 3; }
	bool unlock();
	int balans();
};



int kartochka::balans()
{
	char ms[5];
	char c;
	cout << endl << "Vvedite parol:  ";
	for (int i = 0; i < 4; i++)
	{
		do
		{
			c = _getch();
		} while (c > '9' || c < '0' );
		ms[i] = c;
		cout << "*";
	}
	ms[4] = '\0';
	if (strcmp(ms, pass) == 0)
	{
		money -= raschet();
		cout << endl << "Vse OK" << endl;
		tryes = 3;
		return money;
	}
	cout << endl << "BAD TRY";
	throw "�� ������� ������ ������";
}

bool kartochka::unlock()
{
	if (!transakciia)
	{
		cout << endl << "Kartochka 3ablokirovana";
		return false;
	}
	if (money < raschet())
		throw "������������ �������";
	char ms[5];
	char c;
	for (tryes; tryes; tryes--)
	{
		cout << endl << "Vvedite parol:  ";
		for (int i = 0; i < 4; i++)
		{
			do
			{
				c= _getch();
			} while (c > '9' || c < '0');
			ms[i] = c; 
			cout << "*";
		}
		ms[4] = '\0';
		if (strcmp(ms, pass) == 0)
		{
			money -= raschet();
			cout << endl << "Vse OK" << endl;
			cout << "� ��� � ����� ����� " << raschet() << endl;
			tryes = 3;
			popall();
			return true;
		}
		cout << endl << "BAD TRY";
	}
	cout << endl << "Blokirovka kartochki" << endl;
	transakciia = false;
	throw exeption("����� ������ �������������");
}