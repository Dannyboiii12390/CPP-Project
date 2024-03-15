#pragma once

#include "Lists.h"
#include <iostream>

template<class T>
class Queue
{
private:
	List<T> list;

public:
	void Append(T pItem)
	{
		list.Add(pItem);
	}
	T Peek()
	{
		return list.GetElement(0);
	}
	T Pop()
	{
		T item = Peek();
		list.RemoveItem(item);

		return item;
	}
};

template<class T>
inline ostream& operator<<(ostream& os, Queue<T>& list)
{
	os << list.Peek() << endl;

	return os;
}
