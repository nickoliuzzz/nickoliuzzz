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
	int Open();                     // открытие нового файла
	const char* GetName();
	int Read(T &);             // счивание записи из файла
	void Remote();              // переход в начало файла
	void Add(T);               // добавление записи в файл
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
