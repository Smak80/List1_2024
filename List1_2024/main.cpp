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
	int value;
	int index = 0;
	if (get(list, index, value)) cout << "list[" << index << "]=" << value << endl;
	index = -1;
	if (get(list, index, value)) cout << "list[" << index << "]=" << value << endl;
	index = 5;
	if (get(list, index, value)) cout << "list[" << index << "]=" << value << endl;
	index = 100;
	if (get(list, index, value)) cout << "list[" << index << "]=" << value << endl;
	removeAt(list, 0);
	show_list(list);
	removeAt(list, 5);
	show_list(list);
	removeAt(list, 100);
	show_list(list);
	remove(list, -2);
	show_list(list);
	remove(list, 555);
	show_list(list);
	removeAll(list, -2);
	show_list(list);
	remove(list, 1);
	show_list(list);
	removeAll(list, 3);
	show_list(list);
	clear(list);
	show_list(list);
	delete[] a;
}