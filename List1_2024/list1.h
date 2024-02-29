#pragma once

template <typename T>
struct list1_elem
{
	T data;
	list1_elem<T>* next;
};

template <typename T>
void add(list1_elem<T>*& first, T value)
{
	list1_elem<T>* new_el = new list1_elem<T>;
	new_el->data = value;
	if (!first) first = new_el;
	else
	{
		auto* curr = first;
		while (curr->next) curr = curr->next;
		curr->next = new_el;
	}
}

template <typename T>
void insert(list1_elem<T>*& first, T value, int index);

template <typename T>
T get(list1_elem<T>* first, int index);

template <typename T>
void remove(list1_elem<T>*& first, T value);

template <typename T>
void removeAll(list1_elem<T>*& first, T value);

template <typename T>
void removeAt(list1_elem<T>*& first, int index);

template <typename T>
void clear(list1_elem<T>*& first)
{
	auto* curr = first;
	while (curr)
	{
		const auto* del = curr;
		curr = curr->next;
		delete del;
	}
	first = nullptr;
}

