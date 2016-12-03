#pragma once
//#include "function.cpp"
#include "men.h"
#include <locale.h>
#include "korzina.h"
#include "algorithm.cpp"
template <class T>
void meh(ring<T> *prod, kartochka *mem);
void menu(kartochka *mem);

void skrin()
{
	cout << "\n1- add\n2- pop \n3- cleanall \ns- addtemp to korzina\ne- show temp\nr- next\nq- back\n6- showall\n7- sort\n8- show list\n";
}


int main()
{
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
					menu(&mem);
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
			(*prod).pushend(tmp1);
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
				cout << "Ошибка " << over;
			}
			cout << "\nМожете продолжать\n";
			break;
		case 'r':
			//prod.gorig();
			++it;
			cout << endl << "-------------OK--------------" << endl;
			break;
		case 'q':
			//prod.golef();
			--it;
			cout << "\n-------------OK--------------\n";
			break;
		case 's':
			//mem.add(prod.gettemp());
			(*mem).add(*it);
			cout << "\nДобавлено\n";
			break;
		case '6':
			cout << *prod;
			skrin();
			break;
		case '7':
		{
			//prod.sort();
			sort<T> fef(prod, (*prod).beginf(), (*prod).endf());
			cout << "\n-------------OK--------------\n";
			break;
		}
		case '8':
			skrin();
			break;
		case 27:
			cout << "\nВыйдено\n";
			return;
		default:
			cout << "\nНе те кнопки\n";
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
	while (1)
	{
		int s = 1;
		cout << "\n\n1- Продукты\n2- Молоко\n3- Хлеб \nEsc- для выхода" << endl;
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
			cout << endl << "Отлично поработали\n";
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
