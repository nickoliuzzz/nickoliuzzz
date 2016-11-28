#include "list.h"
#include "korzina.h"
#include <locale.h>
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

void menu(ring<product> &prod, ring<milk> &mil, ring<baton> &bat)
{
	product tmp1;
	milk tmp2;
	baton tmp3;

	int k=1;
	while (k)
	{
		int s = 1;
		cout << "\n\n1- Продукты\n2- Молоко\n3- Хлеб \nEsc- для выхода" << endl;
		switch (_getch())
		{
		case '1':
		{
			while (s)
			{
				cout << "\n1- add\n2- pop \n3- cleanall \nr- next\nq- back\n6- showall\n7- sort\n4- show temp\n";
				switch (_getch())
				{
				case '1':
					cin >> tmp1;
					prod.pushend(tmp1);
					break;
				case '2':
					prod.pop();
					break;
				case '3':
					prod.cleanall();
					break;
				case '4':
					try
					{
						cout << prod.gettemp();
					}
					catch (exeption over)
					{
						cout << "Ошибка " << over;
					}
					break;
				case 'r':
					prod.gorig();
					break;
				case 'q':
					prod.golef();
					break;
				case '6':
					cout << prod;
					break;
				case '7':
					//if (prod.gettemp() < prod.gettemp());
						//cout << "prp";
					prod.sort();
					break;
				case 27:
					s = 0;
				default:
					break;
				}
			}

		}
		case '2':
		{
			while (1)
			{
				cout << "\n1- add\n2- pop \n3- cleanall \nr- next\nq- back\n6- showall\n7- sort\n4- show temp\n";
				switch (_getch())
				{
				case '1':
					cin >> tmp2;
					mil.pushend(tmp2);
					break;
				case '2':
					mil.pop();
					break;
				case '3':
					mil.cleanall();
					break;
				case '4':
					try
					{
						cout << mil.gettemp();
					}
					catch (exeption over)
					{
						cout << "Ошибка " << over;
					}
					break;
				case 'r':
					mil.gorig();
					break;
				case 'q':
					mil.golef();
					break;
				case '6':
					cout << mil;
					break;
				case '7':
					mil.sort();
					break;
				case 27:
					s=0;
				default:
					break;
				}
			}

		}
		case '3':
		{
			while (1)
			{
				cout << "\n1- add\n2- pop \n3- cleanall \nr- next\nq- back\n6- showall\n7- sort\n4- show temp\n";
				switch (_getch())
				{
				case '1':
					cin >> tmp3;
					bat.pushend(tmp3);
					break;
				case '2':
					bat.pop();
					break;
				case '3':
					bat.cleanall();
					break;
				case '4':
					try
					{
						cout << bat.gettemp();
					}
					catch (exeption over)
					{
						cout << "Ошибка " << over;
					}
					break;
				case 'r':
					bat.gorig();
					break;
				case 'q':
					bat.golef();
					break;
				case '6':
					cout << bat;
					break;
				case '7':
					bat.sort();
					break;
				case 27:
					s = 0;
				default:
					break;
				}
			}

		}
		case 27: 
			cout << endl << "Отлично поработали\n";
			return;

		default:
			break;
		}
	}

}
int main()
{
	setlocale(LC_ALL, "rus");
	in ik;
	ring<in> kek;
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
	ring<product> prod;
	ring<milk> mil;
	ring<baton> bat;
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
				cout << endl << "1 - добавить обычный продукт \n2 - добавить молочный продукт \n3 - добавить хлебный продукт";
				cout << "\n4 - просмотреть баланс\n5 - расчитатться \n6 - просмотр корзину\n7- поработать с магазином\n Esc - для выхода\n";
				switch (_getch())
				{
				case '1': cin >> tmp1; mem.add(tmp1); break;
				case '2': cin >> tmp2; mem.add(tmp2); break;
				case '3': cin >> tmp3; mem.add(tmp3); break;
				case '4':
					int fere;
					fere = mem.balans();
					cout << "У вас на счету " << fere << endl;
					break;
				case '5':
					mem.unlock();
					break;
				case '6': 
					cout << mem;
					cout << setw(45) << "Итого " << setw(10) << mem.raschet();
					break;
				case '7':
					menu(prod ,mil,bat);
					break;
				case 27:
					throw exeption("Всё нормально\nПросто вышли ");
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
		cout << endl << "Ошибка " << over << endl;
	}

	/*	//cin >> bat;
		prod.pushbegin(product("moloko", 4));
		milk fee("milkiway", 3, "yogurt", 10500);
		milk fef("milki", -1, "sblrok", 3800);
		baton net(300, 15, "bulki");
		baton ne(1500.7, 4, "s povidlom");
		prod.printtemp();
		cout << prod;
		cout << endl << fee;
		cout << endl;
		cout << fef << endl;
		cout << net << endl;
		cout << ne;
		cout << endl << endl << endl;
		kartochka mem;
		mem.add(fee);
		int fere = mem.balans();
		if(fere != -1)
			cout << "У вас на счету " << fere << endl;
		else cout << "Не удалось узнать баланс";
		mem.add(net);
		mem.add(prod.gettemp());
		cout << endl << endl << endl;
		cout << mem;
		mem.unlock();
		mem.popall();
		mem.popmil();
	}
	catch (exeption over)
	{
		cout << endl << "Ошибка" << over << endl;
	}
	*/
}
