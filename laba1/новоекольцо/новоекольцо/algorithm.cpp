//#include "iterators.h"
//#include "function.cpp"
#include "list.h"
//#include "swap.cpp"

template <class T>
void swp(ring<T> *bat, kol<T> *tmp1,kol<T> *tmp2)
{
	if ((*bat).beginf() == NULL)
		throw exeption("?????? ??????");
	if (tmp1 == tmp2)
		return;
	if (tmp1->left == tmp1->right)
	{
		if (tmp1 ==(*bat).endf())
		{
			tmp2 = (*bat).endf();
			tmp1 = (*bat).beginf();
			(*bat).settemper((*bat).tempf()->right);
			return;
		}
		(*bat).setbegin(tmp2);
		(*bat).setend(tmp1);
		(*bat).settemper((*bat).tempf()->right);
		return;
	}
	if (tmp1 == (*bat).endf())
		(*bat).setend(tmp2);
	else if (tmp2 == (*bat).endf())
		(*bat).setend(tmp1);
	if (tmp2 == (*bat).beginf())
		(*bat).setbegin(tmp1);
	else if (tmp1 == (*bat).beginf())
		(*bat).setbegin(tmp2);
	if (tmp1 == (*bat).tempf())
		(*bat).settemper(tmp2);
	else if (tmp2 == (*bat).tempf())
		(*bat).settemper(tmp1);
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
class algorithm
{


};

template <class T>
class sort : public algorithm<T>
{
public:
	sort(ring<T> *bat, Iterator<T> st, Iterator<T> ed)
	{
		if (st.getCurrent() == NULL)
			throw exeption("?????? ??????????");
		kol<T> *temp = st.getCurrent();
		T  tmp1;
		T tmp2;
		int n = (*bat).getsize();
		kol<T> *tmp, *min;
		for (int i = 0; i < n-1; i++)
		{
			min = temp;
			tmp = min;
			for (int j = i; j < n;j++)
			{
				tmp1 = tmp->info;
				tmp2 = min->info;
				if (tmp1 < tmp2)
				{
					min = tmp;
				}
				tmp = tmp->right;
			}
			swp(bat, temp, min);
			temp=min->right;
		}
	}
};