#include <iostream>
#include "list1.h"
using namespace std;

template <typename T>
void show_list(list1_elem<T>* list)
{
	auto curr = list;
	while (curr)
	{
		cout << curr->data << " -> ";
		curr = curr->next;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	size_t sz = 7;
	int* a = new int[]{ 1, 3, 3, 4, 5, 4, 9 };
	list1_elem<int>* list = nullptr;
	for (int i = 0; i < sz; i++)
	{
		add(list, a[i]);
	}
	show_list(list);
	insert(list, -2, -100);
	insert(list, 2, 0);
	insert(list, -2,4);
	insert(list, -2, 100);
	show_list(list);
	clear(list);
	delete[] a;
}