#pragma once
#include <stdint.h>

template <typename T>
struct list1_elem
{
	T data;
	list1_elem<T>* next;
};

template <typename T>
void insert(list1_elem<T>*& first, T value, int index)
{
	list1_elem<T>* new_el = new list1_elem<T>;
	new_el->data = value;
	if (!first || index <= 0) 
	{
		new_el->next = first;
		first = new_el;
	}
	else
	{
		auto* curr = first;
		int curr_i = 0;
		while (curr->next && ++curr_i < index) curr = curr->next;
		new_el->next = curr->next;
		curr->next = new_el;
	}
}

template <typename T>
void add(list1_elem<T>*& first, T value)
{
	insert(first, value, INT_FAST32_MAX);
}

template <typename T>
bool get(list1_elem<T>* first, int index, T& result)
{
	if (index < 0 || !first) return false;
	auto curr = first;
	auto i = 0;
	while (curr && i++ < index)
	{
		curr = curr->next;
	}
	if (!curr) return false;
	result = curr->data;
	return true;
}

template <typename T>
void remove(list1_elem<T>*& first, T value)
{
	if (!first) return;
	auto curr = first;
	if (first->data == value)
	{
		first = first->next;
		delete curr;
	}
	else
	{
		while (curr->next && curr->next->data != value)
		{
			curr = curr->next;
		}
		if (curr->next)
		{
			auto del = curr->next;
			curr->next = curr->next->next;
			delete del;
		}
	}
}

template <typename T>
void removeAll(list1_elem<T>*& first, T value)
{
	if (!first) return;
	auto curr = first;
	while (first && first->data == value)
	{
		first = first->next;
		delete curr;
		curr = first;
	}
	do {
		while (curr->next && curr->next->data != value)
		{
			curr = curr->next;
		}
		if (curr->next)
		{
			auto del = curr->next;
			curr->next = curr->next->next;
			delete del;
		}
	} while (curr->next);
}

template <typename T>
void removeAt(list1_elem<T>*& first, int index)
{
	if (index < 0 || !first) return;
	auto curr = first;
	auto i = 0;
	if (index == 0)
	{
		auto del = first;
		first = first->next;
		delete del;
	}
	else {
		while (curr->next && ++i < index)
		{
			curr = curr->next;
		}
		if (!curr->next) return;
		auto del = curr->next;
		curr->next = curr->next->next;
		delete del;
	}
}

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

