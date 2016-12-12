#pragma once
template <class T>
struct kol
{
	T info;
	kol *right, *left;
	~kol()
	{
		cout << endl << "Pizdec,che" << T;
	}

};