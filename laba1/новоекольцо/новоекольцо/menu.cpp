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
	prod.pushbegin(product("moloko", 4));
	milk fee("milkiway", 3, "yogurt", 10500);
	milk fef("milki", -1, "sblrok", 3800);
	baton net(300, 15, "bulki");
	baton ne(1500.7, 4, "s povidlom");
	prod.printtemp();
	cout << endl <<fee;
	cout << endl;
	cout << fef << endl;
	cout << net << endl;
	cout << ne;
}