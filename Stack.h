#pragma once
#include "Lists.h"

template<class T>
class Stack
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
		int length = list.Count - 1;
		return list.GetElement(length);
	}
	T Pop()
	{
		T item = Peek();
		list.RemoveItem(item);
		return item;
	}
};

template<class T>
inline ostream& operator<<(ostream& os, Stack<T>& list)
{
	os << list.Peek() << endl;

	return os;
}
