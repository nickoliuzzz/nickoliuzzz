#pragma once
//#include "function.cpp"
#include <locale.h>
#include "korzina.h"
#include "algorithm.cpp"
template <class T>
void meh(ring<T> *prod, kartochka *mem);
void menu(kartochka *mem);

void skrin()
{
	cout << "\n1- add\n2- pop \n3- cleanall \ns- addtemp to korzina\ne- show temp\nr- next\nq- back\n6- showall\n7- sort\n8- show list\nESC - �����\n";
}
void my_term()
{
	cout << "\n�� � ��� ��������(� ���������� ���������� ������)\n";
	exit(1);
	return;
}
void my_unexpected()
{
	cout << "���, ����� ����������� �����";
	throw 'c';
}


int main()
{
	set_terminate(my_term);
	setlocale(LC_ALL, "rus");
	//in ik;
	//ring<in> kek;
	/*while(1)
	{
		for (int i = 0; i < 6; i++)
		{
			cin >> ik.i;
			kek.pushend(ik);
		}
		cout << endl << endl;
		cout<<kek;
		kek.sort();
		cout << endl << endl;
		kek.printall();
		cout << endl;
		kek.cleanall();
	}
	*/
	set_unexpected(my_unexpected);
	try {
		product tmp1;
		milk tmp2;
		baton tmp3;
		kartochka mem;
		try
		{
			while (1)
			{
				try
				{
					cout << endl << "1 - �������� ������� ������� \n2 - �������� �������� ������� \n3 - �������� ������� �������";
					cout << "\n4 - ����������� ������\n5 - ������������ \n6 - �������� �������\n7- ���������� � ���������\n Esc - ��� ������\n";
					switch (_getch())
					{
					case '1': 
					{
						try 
						{
							cin >> tmp1;
							mem.add(tmp1); 
							break;
						}
						catch (bad_alloc exept)
						{
							cout << "\n������ " << exept.what() << "\n��� ��� �� ���� ������ ����������";
							exit(1);
						}
					}
					case '2':
					{
						try 
						{ 
							cin >> tmp2; 
							mem.add(tmp2); 
							break; 
						}
						catch (bad_alloc exept)
						{
							cout << "\n������ " << exept.what() << "\n��� ��� �� ���� ������ ����������";
							exit(1);
						}
					}
					case '3':
					{
						try { cin >> tmp3; mem.add(tmp3); break; }
						catch (bad_alloc exept)
						{
							cout << "\n������ " << exept.what() << "\n��� ��� �� ���� ������ ����������";
							exit(1);
						}
					}
					case '4':
					{
						try 
						{
							int fere;
							fere = mem.balans();
							cout << "� ��� �� ����� " << fere << endl;
							break;
						}
						catch (exeptionkart over)
						{
							cout << endl << over << endl;
							if (over.ret() == 13)
							{
								cout << "��� ��� ��� ������ ����������";
								exit(1);
							}
						}
						break;
					}
					case '5':
					{
						try
						{
							mem.unlock();
						}
						catch (exeptionkart over)
						{
							cout << endl << over << endl;
							if (over.ret() == 13)
							{
								cout << "��� ��� ��� ������ ����������";
								exit(1);
							}
						}
						break;
					}
					case '6':
						cout << mem;
						cout << setw(45) << "����� " << setw(10) << mem.raschet();
						break;
					case '7':
					{
						try {
							menu(&mem);
						}
						catch (exeptshablon over)
						{
							cout << "\n������ ������� " << over;
							exit(1);
						}
						catch (exeptfiles over)
						{
							cout << "\n���-�� � ��������� �� ��" << over;
						}
						break;
					}
					case '8':
						throw 1.;
					case 27:
						throw exeption("�� ���������\n������ ����� ", 3);
						break;
					default:
						break;
					}
				}
				catch (char *ms3)
				{
					cout << ms3;
				}

			}

		}
		catch (exeption over)
		{
			cout << endl << "������ " << over << endl;
		}
	}
	catch (char)
	{
		cout << "\n�� �� �� ������";
	}
}
template <class T>
void meh(ring<T> *prod, kartochka *mem)
{
	T tmp1;
	Iterator<T> it;
	skrin();
	while (1)
	{
		switch (_getch())
		{
		case '1':
			cin >> tmp1;
			try
			{
				(*prod).pushend(tmp1);
			}
			catch (bad_alloc exept) 
			{           
				cout << "�������� ����������   " << exept.what() << endl;
			}
			it = (*prod).tempf();
			skrin();
			break;
		case '2':
			(*prod).pop();
			cout << endl << "OK" << endl;
			break;
		case '3':
			(*prod).cleanall();
			cout << endl << "OK" << endl;
			break;
		case 'e':
			try
			{
				//cout << prod.gettemp();
				cout << *it;
			}
			catch (exeption over)
			{
				cout << "������ " << over;
			}
			cout << "\n������ ����������\n";
			break;
		case 'r':
			//prod.gorig();
			try
			{
				++it;
				cout << endl << "-------------OK--------------" << endl;
			}
			catch (exeptshablon ever)
			{
				cout << ever;
			}
			break;
		case 'q':
			//prod.golef();
			try
			{
			--it;
			cout << "\n-------------OK--------------\n";
			}
			catch (exeptshablon ever)
			{
				cout << ever;
			}
			break;
		case 's':
			//mem.add(prod.gettemp());
			try{
			(*mem).add(*it);
			cout << "\n���������\n";
			}
			catch (exeption ever)
			{
				cout << ever;
			}
			break;
		case '6':
			try{
				cout << *prod;
			}
			catch (exeptshablon ever)
			{
				cout << ever;
			}
			skrin();
			break;
		case '7':
		{
			//prod.sort();
			try{
			sort<T> fef(prod, (*prod).beginf(), (*prod).endf());
			cout << "\n-------------OK--------------\n";
			}
			catch (exeption ever)
			{
				cout << ever;
			}
			break;
		}
		case '8':
			skrin();
			break;
		case 27:
			cout << "\n�������\n";
			return;
		default:
			cout << "\n�� �� ������\n";
			skrin();
			break;
		}
	}
}


void menu(kartochka *mem)
{
	ring<product> prod;
	ring<milk> mil;
	ring<baton> bat;
	bat.setname("�����");
	mil.setname("������");
	prod.setname("��������");
	fstream f;
	f >> prod;
	f >> mil;
	f >> bat;
	while (1)
	{
		int s = 1;
		cout << "\n\n1- ��������\n2- ������\n3- ���� \nEsc- ��� ������" << endl;
		switch (_getch())
		{
		case '1':
		{
			meh(&prod, mem);
			break;
		}
		case '2':
		{
			meh(&mil, mem);
			break;
		}
		case '3':
		{
			meh(&bat, mem);
			break;
		}
		case 27:
			cout << endl << "������� ����������\n";
			f << prod;
			f << mil;
			f << bat;
			return;

		default:
			break;
		}
	}

}

	class in
	{
	public:
		in() {};
		~in() {};
		int i;
		friend ostream& operator<<(ostream &my, in& tmp)
		{
			my << tmp.i;
			return my;
		};
		friend istream& operator>>(istream &my, in& tmp)
		{
			int j;
			my >> j;
			tmp.i = j;
			return my;
		}
		bool operator<(const in& tmp)
		{
			if (i<tmp.i)
				return true;
			return false;
		}
	};
