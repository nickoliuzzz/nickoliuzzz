#pragma once
#include "struct.cpp"
#include "function.cpp"
#include "exeption.h"
template  <class T>
class Iterator
{
	kol<T> *kolia;
public:
	Iterator()
	{
		kolia = NULL;
	}
	Iterator(kol<T>* node) : kolia(node)
	{
		cout << "\nIterator();";
	}
	Iterator(const Iterator<T>& temp)
	{
		//cout << "\nCOPYIterator();";
		kolia = temp.kolia;
	}
	~Iterator()
	{
		//cout << "\n~Iterator();";
	}
	T getValue()
	{
		return kolia->info;
	}

	kol<T>* getCurrent()
	{
		return kolia;
	}
	Iterator<T>& operator++ ()
	{
		kolia = kolia->right;
		return *this;
	}
	Iterator<T>& operator-- ()
	{
		kolia = kolia->left;
		return *this;
	}

	Iterator<T>& operator= (Iterator<T>& temp)
	{
		if (this != &temp)
			kolia = temp.kolia;
		return *this;
	}
	Iterator<T>& operator= (kol<T> *temp)
	{
		if (kolia != temp)
			kolia = temp;
		return *this;
	}
	bool operator!= (kol<T>* comp)
	{
		return (this->current->getValue() != comp->getValue());
	}
	bool operator!= (Iterator<T>& comp)
	{
		return (kolia->info != comp.kolia->info);
	}
	bool operator== (Iterator<T>& comp)
	{
		return (kolia->info == comp.kolia->info);
	}
	T operator* ()
	{
		/*cout << endl << getValue();*/
		return kolia->info;

	}
	friend ostream& operator<<(ostream &my, Iterator<T>& tmp)
	{
		if (tmp.getCurrent() == NULL)
			throw exeption("Нечего выводить");
		kol<T> fe;
		fe = *tmp.getCurrent();
		my << fe.info;
	}
};
