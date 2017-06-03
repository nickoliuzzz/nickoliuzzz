#pragma once
//#include <iostream>
//#include <iomanip>
//using namespace std;

#include "exeption.h"
//#include "struct.cpp"
#include "iterators.h"

template <class T>
class ring
{
private:
	char ms[20];
	kol<T> *begin, *end, *temp;		
	Iterator<T> beginer, ender, temper;
	int n;//
public:
	//------------
	kol<T>* endf()
	{
		return end;
	}
	kol<T>* tempf()
	{
		return temp;
	}
	kol<T>* beginf()
	{
		return begin;
	}
	void setbegin(kol<T> *m)
	{
		begin = m;
		beginer = m;
	}
	void settemper(kol<T> *m)
	{
		temp = m;
		temper = m;
	}
	void setend(kol<T> *m)
	{
		end = m;
		ender = m;
	}

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
	~ring() { while (pop()); }//
//-------
	bool pushrig(T inf);					//
	bool pushend(T inf);					//
	bool pushbegin(T inf);					//
	bool pushlef(T inf);			//
	//-------
	void gorig() { temp = temp->right; }//
	void golef() { temp = temp->left; }//
	void goend() { temp = end; }//
	void gobegin() { temp = begin; }//
//---------
	bool popend();		//
	bool pop();			//
	void cleanall();			//
//--------
	void printall();	//
	void printtemp() { cout << endl << temp->info << endl; }//
//-----------
	bool operator <(const ring &tmp);
/*	bool operator ==(const ring &tmp);
	bool operator !=(const ring &tmp);
	bool operator >(const ring &tmp);*/
//-----------
	T  gettemp() { if (begin == NULL) throw exeption("Нечего возвращать",16); return temp->info; }//
	int  getsize() { return n; }
	void swap(kol<T> *tmp1, kol<T> *tmp2);//
	void sort();

	char* getname()
	{
		return ms;
	}
	bool search(T inf);
	bool comp(char *ms1);
	friend ostream& operator<<(ostream &my, ring& tmp)
	{
		if (tmp.end == NULL)
			throw exeptshablon("Нечего выводить",14);
		tmp.temp = tmp.begin;
		while (tmp.temp != tmp.end)
		{
			my << tmp.temp->info;
			tmp.temp = tmp.temp->right;
		} ;
		my << tmp.temp->info;
		return my;
	}

	friend fstream& operator<<(fstream& inf, ring& obj)
	{

		if (inf.is_open())
			inf.close();
		inf.open(obj.getname(), ios::binary | ios::out);
		inf.write((char*)&obj.n, sizeof(obj.n));
		for (int i = 0; i < obj.n; i++)
		{
			inf << obj.temp->info;
			obj.temp = obj.temp->right;
			
		}
		inf.close();
		return inf;
	}
	friend fstream& operator>>(fstream& inf, ring& obj)
	{
		T info;
		if (inf.is_open())
		{
			inf.close();
		}
		inf.open(obj.getname(), ios::binary | ios::in);
		if (!inf.is_open())
		{
			throw exeptfile("Файл не существует", 405);
		}
		inf.read((char*)&obj.n, sizeof(obj.n));
		for (int i = 0; i < obj.getsize(); i++)
		{
			inf >> info;
			//obj.pushend(info);

			kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
			if (!tmp)
			{
				bad_alloc exept;
				throw exept;
			}
			if (obj.begin == NULL)
			{
				tmp->right = tmp;
				tmp->left = tmp;
				obj.temp = tmp;
				obj.begin = tmp;
				obj.end = tmp;
				tmp->info = info;
				obj.beginer = obj.begin;
				obj.ender = obj.end;
				obj.temper = obj.temp;
			}
			else {
				tmp->right = obj.begin;
				tmp->left = obj.end;
				obj.begin->left = tmp;
				obj.end->right = tmp;
				obj.end = tmp;
				tmp->info = info;
				obj.beginer = obj.begin;
				obj.ender = obj.end;
				obj.temper = obj.temp;
			}
		}
		inf.close();
		return inf;
	}
};
//-----------------------------------



//------------------------------------

template <class T>
bool ring<T>::search(T inf)
{
	for (int i = 0; i < n; i++)
	{
		if (temp->info == inf)
			return true;
		temp = temp->left
	}
	throw exeptshablon("Нет таких елементов",12);
}

template <class T>
bool ring<T>::comp(char *ms1)
{
	if (strcmp(ms1, ms) == 0) return true;
	return false;
}


template <class T>
bool ring<T>::operator<(const ring<T> &tmp)
{
	int i = 0;
	while (ms[i] == tmp.ms[i])
	{
		i++;
	}
	if (ms[i] < tmp.ms[i])
		return true;
	return false;
}
//--------------------------------------




template <class T>
void ring<T>::printall()
{
	if (end == NULL)
		throw exeptshablon("Нечего выводить",11);
	cout << endl << "Вот ваше кольцо" << endl;
	temp = begin;
	do
	{
		cout << temp->info << endl;
		temp = temp->right;
	} while (temp != end);
	cout << temp->info;
}



template <class T>
ring<T>::ring(T inf)
{
	n = 1;
	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
	if (!tmp)	
	{
		bad_alloc exept;
		throw exept;
	}
	tmp->right = tmp;
	tmp->left = tmp;
	temp = tmp;
	begin = tmp;
	end = tmp;
	tmp->info = inf;
	cout << inf;
}

template <class T>
ring<T>::ring()
{
	n = 0;
	temp = NULL;
	begin = temp;;
	end = temp;
	beginer = begin;
	ender = end;
	temper = temp;
}
//---------------------------

template <class T>
void ring<T>::cleanall()
{
	if (begin == NULL) return;// throw exeption("Всё и так было отчищено");
	while (pop());
	cout << endl << "Пусто" << endl;
}

template <class T>
bool ring<T>::popend()
{
	if (end == NULL)
		throw exeptshablon("Тут было пусто",9);
	if (begin != end)
	{
		kol<T> *tmp = end;
		end = end->left;
		end->right = begin;
		free(tmp);
		n--;
		beginer = begin;
		ender = end;
		temper = temp;
		return true;
	}
	free(temp);
	temp = NULL;
	end = NULL;
	begin = NULL;
	n--;
	beginer = begin;
	ender = end;
	temper = temp;
	return true;
}

template <class T>
bool ring<T>::pop()
{
	if (begin == NULL)
		return false;
	if (begin == end)
	{
		free(temp);
		end = NULL;
		begin = NULL;
		temp = NULL;
		n--;
		beginer = begin;
		ender = end;
		temper = temp;
		return true;
	}
	kol<T> *tmp = temp->right;
	if (temp == begin)
		begin = tmp;
	else if (temp == end)
		end = temp->left;
	temp->left->right = temp->right;
	temp->right->left = temp->left;
	free(temp);
	temp = tmp;
	n--;
	beginer = begin;
	ender = end;
	temper = temp;
	return true;
}
//-------------------------------------



template <class T>
bool ring<T>::pushrig(T inf)
{
	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
	if (!tmp)
	{
		bad_alloc exept;
		throw exept;
	}
	if (begin == NULL)
	{
		tmp->right = tmp;
		tmp->left = tmp;
		temp = tmp;
		begin = tmp;
		end = tmp;
		tmp->info = inf;
		n++;
		beginer = begin;
		ender = end;
		temper = temp;
		return true;
	}

	tmp->right = temp->right;
	tmp->left = temp;
	temp->right->left = tmp;
	temp->right = tmp;
	tmp->info = inf;
	if (tmp == end->right)
		end = tmp;
	n++;
	beginer = begin;
	ender = end;
	temper = temp;
	return true;
}

template <class T>
bool ring<T>::pushlef(T inf)
{
	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
	if (!tmp)	
	{
		bad_alloc exept;
		throw exept;
	}
	if (begin == NULL)
	{
		tmp->right = tmp;
		tmp->left = tmp;
		temp = tmp;
		begin = tmp;
		end = tmp;
		tmp->info = inf;
		n++;
		beginer = begin;
		ender = end;
		temper = temp;
		return true;
	}

	tmp->right = temp;
	tmp->left = temp->left;
	temp->left->right = tmp;
	temp->right = tmp;
	tmp->info = inf;
	if (tmp == begin->left)
		begin = tmp;
	n++;
	beginer = begin;
	ender = end;
	temper = temp;
	return true;
}

template <class T>
bool ring<T>::pushbegin(T inf)
{
	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
	if (!tmp)	
	{
		bad_alloc exept;
		throw exept;
	}
	if (begin == NULL)
	{
		tmp->right = tmp;
		tmp->left = tmp;
		temp = tmp;
		begin = tmp;
		end = tmp;
		tmp->info = inf;
		n++;
		beginer = begin;
		ender = end;
		temper = temp;
		return true;
	}

	tmp->right = begin;
	tmp->left = end;
	begin->left = tmp;
	end->right = tmp;
	begin = tmp;
	tmp->info = inf;
	n++;
	beginer = begin;
	ender = end;
	temper = temp;
	return true;
}

template <class T>
bool ring<T>::pushend(T inf)
{
	kol<T> *tmp = (kol<T>*) malloc(sizeof(kol<T>));
	if (!tmp)
	{
		bad_alloc exept;
		throw exept;
	}
	if (begin == NULL)
	{
		tmp->right = tmp;
		tmp->left = tmp;
		temp = tmp;
		begin = tmp;
		end = tmp;
		tmp->info = inf;
		n++;
		beginer = begin;
		ender = end;
		temper = temp;
		return true;
	}

	tmp->right = begin;
	tmp->left = end;
	begin->left = tmp;
	end->right = tmp;
	end = tmp;
	tmp->info = inf;
	n++;
	beginer = begin;
	ender = end;
	temper = temp;
	return true;
}


//---------------------



template <class T>
void ring<T>::swap(kol<T> *tmp1, kol<T> *tmp2)
{
	if (begin == NULL)
		return;
	if (tmp1 == tmp2)
		return;
	if (tmp1->left == tmp1->right)
	{
		if (tmp1 == end)
		{
			tmp2 = end;
			tmp1 = begin;
			temp = temp->right;
			beginer = begin;
			ender = end;
			temper = temp;
			return;
		}
		begin = tmp2;
		end = tmp1;
		temp = temp->right;
		beginer = begin;
		ender = end;
		temper = temp;
		return;
	}
	if (tmp1 == end)
	{
		end = tmp2;
		ender = end;
	}
	else if (tmp2 == end)
	{
		end = tmp1;
		ender = end;
	}
	if (tmp2 == begin)
	{
		begin = tmp1;
		beginer = begin;
	}
	else if (tmp1 == begin)
	{
		begin = tmp2;
		beginer = begin;
	}
	if (tmp1 == temp)
	{
		temp = tmp2;
		temper = temp;
	}
	else if (tmp2 == temp)
	{
		temp = tmp1;
		temper = temp;
	}
	if (tmp1->left == tmp2)
	{
		tmp1->left = tmp2->left;
		tmp2->right = tmp1->right;
		tmp2->left->right = tmp1;
		tmp1->right->left = tmp2;
		tmp1->right = tmp2;
		tmp2->left = tmp1;
		return;
	}
	if (tmp1->right == tmp2)
	{
		tmp2->left = tmp1->left;
		tmp1->right = tmp2->right;
		tmp1->left->right = tmp2;
		tmp2->right->left = tmp1;
		tmp2->right = tmp1;
		tmp1->left = tmp2;
		return;
	}
	kol<T> *tmp;
	tmp = tmp1->left;
	tmp1->left = tmp2->left;
	tmp2->left = tmp;
	tmp1->left->right = tmp1;
	tmp2->left->right = tmp2;
	tmp = tmp1->right;
	tmp1->right = tmp2->right;
	tmp2->right = tmp;
	tmp1->right->left = tmp1;
	tmp2->right->left = tmp2;
	return;
}

template <class T>
void ring<T>::sort()
{
	if (begin == NULL)
		throw exeption("Нечего сортировать",16);
	temp = begin;
	T tmp1;
	T tmp2;
	kol<T> *tmp, *min;
	do
	{
		min = temp;
		tmp = temp;
		do
		{
			tmp1 = tmp->info;
			tmp2 = min->info;
			if (tmp1 < tmp2)
			{
				min = tmp;
			}
			tmp = tmp->right;
		} while (tmp != begin);
		swap(temp, min);
		temp = temp->right;
	} while (temp != begin);
}



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
