/*#pragma once 
#include "list.h"
#include "korzina.h"
template <class T>
class File
{
	char ms[20];
	int n;
	fstream *fil;
public:
	File(char *filename);
	~File();
	int Open();                     // �������� ������ �����
	const char* GetName();
	int Read(T &);             // �������� ������ �� �����
	void Remote();              // ������� � ������ �����
	void Add(T);               // ���������� ������ � ����
	int Del(int pos);
	int Read(ring<T> &);
};


template <class T>
File<T>::File(char * m)
{
	strcpy_s(ms, m);
	fil = new fstream();
}

template <class T>
*/
