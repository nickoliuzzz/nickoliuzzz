#pragma once
//#include <iostream>
//#include <iomanip>
//using namespace std;

#include "exeption.h"

template <class T>
struct kol
{
	T info;              
	kol *right, *left;

};

template <class T>
class ring
{
private:
	char ms[20];
	kol<T> *begin, *end, *temp;		
	int n;//
public:
	ring(T inf);//
	ring(char *ms1)
	{
		strcpy(ms, ms1);
	};
	void  setname(char *ms1)
	{
		strcpy_s(ms, ms1);
	};
	/*friend istream& operator>>(istream &my, ring<T>& tmp)
	{
		T tmp1;
		my >> tmp1;
		pushend(tmp1);
		return my;
	}*/

	ring();//
	~ring() { /*cleanall();*/ };//
	bool pushrig(T inf);					//
	bool pushend(T inf);					//
	bool pushbegin(T inf);					//
	bool pushlef(T inf);					//
	void gorig() { temp = temp->right; }//
	void golef() { temp = temp->left; }//
	bool popend();		//
	bool pop();			//
	void goend() { temp = end; }//
	void gobegin() { temp = begin; }//
	T  gettemp() { if (begin == NULL) throw exeption("Нечего возвращать"); return temp->info; }//
	int  getsize() { return n; }
	void printall();	//
	void printtemp() { cout << endl << temp->info << endl; }//
	void cleanall();			//
	void swap(kol<T> *tmp1, kol<T> *tmp2);//
	void sort();
	bool operator <(const ring &tmp);
	bool search(T inf);
	bool comp(char *ms1);
	friend ostream& operator<<(ostream &my, ring& tmp)
	{
		if (tmp.end == NULL)
			return my;
		tmp.temp = tmp.begin;
		while (tmp.temp != tmp.end)
		{
			my << tmp.temp->info << endl;
			tmp.temp = tmp.temp->right;
		} ;
		my << tmp.temp->info;
		return my;
	}
};

//
//template <class T>
//bool ring<T>::search(T inf)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (temp->info == inf)
//			return true;
//		temp = temp->left
//	}
//	throw exeption("Нет таких елементов");
//}
//
//template <class T>
//bool ring<T>::comp(char *ms1)
//{
//	if (strcmp(ms1, ms) == 0) return true;
//	return false;
//}
//
//
//template <class T>
//bool ring<T>::operator<(const ring<T> &tmp)
//{
//	int i = 0;
//	while (ms[i] == tmp.ms[i])
//	{
//		i++;
//	}
//	if (ms[i] < tmp.ms[i])
//		return true;
//	return false;
//}
//
//
//template <class T>
//ring<T>::ring(T inf)
//{
//	n = 1;
//	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
//	if (!tmp)	throw exeption("Память не выделалась");
//	tmp->right = tmp;
//	tmp->left = tmp;
//	temp = tmp;
//	begin = tmp;
//	end = tmp;
//	tmp->info = inf;
//	cout << inf;
//}
//
//template <class T>
//ring<T>::ring()
//{
//	n = 0;
//	temp = NULL;
//	begin = temp;;
//	end = temp;
//}
//
//template <class T>
//void ring<T>::cleanall()
//{
//	if (begin == NULL) return;// throw exeption("Всё и так было отчищено");
//	while (pop());
//	cout << ms << " пусто" << endl;
//}
//
//template <class T>
//bool ring<T>::popend()
//{
//	if (end == NULL)
//		throw exeption("Тут было пусто");
//	if (begin != end)
//	{
//		kol<T> *tmp = end;
//		end = end->left;
//		end->right = begin;
//		free(tmp);
//		n--;
//		return true;
//	}
//	free(temp);
//	temp = NULL;
//	end = NULL;
//	begin = NULL;
//	n--;
//	return true;
//}
//
//template <class T>
//bool ring<T>::pop()
//{
//	if (begin == NULL)
//		return false;
//	if (begin == end)
//	{
//		free(temp);
//		end = NULL;
//		begin = NULL;
//		temp = NULL;
//		n--;
//		return true;
//	}
//	kol<T> *tmp = temp->right;
//	if (temp == begin)
//		begin = tmp;
//	else if (temp == end)
//		end = temp->left;
//	temp->left->right = temp->right;
//	temp->right->left = temp->left;
//	free(temp);
//	temp = tmp;
//	n--;
//	return true;
//}
//
//template <class T>
//bool ring<T>::pushrig(T inf)
//{
//	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
//	if (!tmp)	throw exeption("Память не выделалась");
//	if (begin == NULL)
//	{
//		tmp->right = tmp;
//		tmp->left = tmp;
//		temp = tmp;
//		begin = tmp;
//		end = tmp;
//		tmp->info = inf;
//		n++;
//		return true;
//	}
//
//	tmp->right = temp->right;
//	tmp->left = temp;
//	temp->right->left = tmp;
//	temp->right = tmp;
//	tmp->info = inf;
//	if (tmp == end->right)
//		end = tmp;
//	n++;
//	return true;
//}
//
//template <class T>
//bool ring<T>::pushlef(T inf)
//{
//	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
//	if(!tmp)	throw exeption("Память не выделалась");
//	if (begin == NULL)
//	{
//		tmp->right = tmp;
//		tmp->left = tmp;
//		temp = tmp;
//		begin = tmp;
//		end = tmp;
//		tmp->info = inf;
//		n++;
//		return true;
//	}
//
//	tmp->right = temp;
//	tmp->left = temp->left;
//	temp->left->right = tmp;
//	temp->right = tmp;
//	tmp->info = inf;
//	if (tmp == begin->left)
//		begin = tmp;
//	n++;
//	return true;
//}
//
//template <class T>
//bool ring<T>::pushbegin(T inf)
//{
//	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
//	if (!tmp)	throw exeption("Память не выделалась");
//	if (begin == NULL)
//	{
//		tmp->right = tmp;
//		tmp->left = tmp;
//		temp = tmp;
//		begin = tmp;
//		end = tmp;
//		tmp->info = inf;
//		n++;
//		return true;
//	}
//
//	tmp->right = begin;
//	tmp->left = end;
//	begin->left = tmp;
//	end->right = tmp;
//	begin = tmp;
//	tmp->info = inf;
//	n++;
//	return true;
//}
//
//template <class T>
//bool ring<T>::pushend(T inf)
//{
//	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
//	if (!tmp)	throw exeption("Память не выделалась");
//	if (begin == NULL)
//	{
//		tmp->right = tmp;
//		tmp->left = tmp;
//		temp = tmp;
//		begin = tmp;
//		end = tmp;
//		tmp->info = inf;
//		n++;
//		return true;
//	}
//
//	tmp->right = begin;
//	tmp->left = end;
//	begin->left = tmp;
//	end->right = tmp;
//	end = tmp;
//	tmp->info = inf;
//	n++;
//	return true;
//}
//
//template <class T>
//void ring<T>::printall()
//{
//	if (end == NULL)
//		throw exeption("Нечего выводить");
//	cout << endl << "Вот ваше кольцо" << endl;
//	temp = begin;
//	do
//	{
//		cout << temp->info << endl;
//		temp = temp->right;
//	} while (temp != end);
//	cout << temp->info;
//}
//
//template <class T>
//void ring<T>::swap(kol<T> *tmp1, kol<T> *tmp2)
//{
//	if (begin == NULL)
//		return;
//	if (tmp1 == tmp2)
//		return;
//	if (tmp1->left == tmp1->right)
//	{
//		if (tmp1 == end)
//		{
//			tmp2 = end;
//			tmp1 = begin;
//			temp = temp->right;
//			return;
//		}
//		begin = tmp2;
//		end = tmp1;
//		temp = temp->right;
//		return;
//	}
//	if (tmp1 == end)
//		end = tmp2;
//	else if (tmp2 == end)
//		end = tmp1;
//	if (tmp2 == begin)
//		begin = tmp1;
//	else if (tmp1 == begin)
//		begin = tmp2;
//	if (tmp1 == temp)
//		temp = tmp2;
//	else if (tmp2 == temp)
//		temp = tmp1;
//	if (tmp1->left == tmp2)
//	{
//		tmp1->left = tmp2->left;
//		tmp2->right = tmp1->right;
//		tmp2->left->right = tmp1;
//		tmp1->right->left = tmp2;
//		tmp1->right = tmp2;
//		tmp2->left = tmp1;
//		return;
//	}
//	if (tmp1->right == tmp2)
//	{
//		tmp2->left = tmp1->left;
//		tmp1->right = tmp2->right;
//		tmp1->left->right = tmp2;
//		tmp2->right->left = tmp1;
//		tmp2->right = tmp1;
//		tmp1->left = tmp2;
//		return;
//	}
//	kol<T> *tmp;
//	tmp = tmp1->left;
//	tmp1->left = tmp2->left;
//	tmp2->left = tmp;
//	tmp1->left->right = tmp1;
//	tmp2->left->right = tmp2;
//	tmp = tmp1->right;
//	tmp1->right = tmp2->right;
//	tmp2->right = tmp;
//	tmp1->right->left = tmp1;
//	tmp2->right->left = tmp2;
//	return;
//}
//
//template <class T>
//void ring<T>::sort()
//{
//	if (begin == NULL)
//		throw exeption("Нечего сортировать");
//	temp = begin;
//	kol<T> *tmp, *min;
//	do
//	{
//		min = temp;
//		tmp = temp;
//		do
//		{
//			if (tmp->info < min->info)
//				min = tmp;
//			tmp = tmp->right;
//		} while (tmp != begin);
//		swap(temp, min);
//		temp = temp->right;
//	} while (temp != begin);
//}
