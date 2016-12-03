//#pragma once
//#include "korzina.h"
//
//
//
//template <class T>
//void meh(ring<T> prod, kartochka mem)
//{
//	T tmp1;
//	while (1)
//	{
//		cout << "\n1- add\n2- pop \n3- cleanall \nr- next\nq- back\n6- showall\n7- sort\n4- show temp\n";
//		switch (_getch())
//		{
//		case '1':
//			cin >> tmp1;
//			prod.pushend(tmp1);
//			break;
//		case '2':
//			prod.pop();
//			break;
//		case '3':
//			prod.cleanall();
//			break;
//		case '4':
//			try
//			{
//				cout << prod.gettemp();
//			}
//			catch (exeption over)
//			{
//				cout << "Ошибка " << over;
//			}
//			break;
//		case 'r':
//			prod.gorig();
//			break;
//		case 'q':
//			prod.golef();
//			break;
//		case '6':
//			cout << prod;
//			break;
//		case '7':
//			//if (prod.gettemp() < prod.gettemp());
//			//cout << "prp";
//			prod.sort();
//			break;
//		case 27:
//			return;
//		default:
//			break;
//		}
//	}
//}
//
//
//
//
//
//
//
//void menu(ring<product> &prod, ring<milk> &mil, ring<baton> &bat,kartochka mem)
//{
//	while (1)
//	{
//		int s = 1;
//		cout << "\n\n1- Продукты\n2- Молоко\n3- Хлеб \nEsc- для выхода" << endl;
//		switch (_getch())
//		{
//		case '1':
//		{
//			meh(prod, mem);
//			break;
//		}
//		case '2':
//		{
//			meh(mil, mem);
//			break;
//		}
//		case '3':
//		{
//			meh(bat, mem);
//			break;
//		}
//		case 27:
//			cout << endl << "Отлично поработали\n";
//			return;
//
//		default:
//			break;
//		}
//	}
//
//}
