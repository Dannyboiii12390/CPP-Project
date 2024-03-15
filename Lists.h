// Lists.h
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#pragma once

using namespace std;

template <class T>
class List
{
	// variables
private:
	int Length = 4;
	T* arr = new T[Length];

public:
	int Count = 0;

	// methods
private:
	inline void ExtendLength()
	{
		int extended = Length << 1;

		T* tempOriginal = new T[extended];

		for (int i = 0; i < Length; i++)// copy old array to new array
		{
			tempOriginal[i] = arr[i];
		}

		delete[] arr; // delete old array
		arr = tempOriginal; // point old array to new array
		Length = extended;
	}
	

public:

	inline T operator[] (int i)
	{
		return GetElement(i);
	}
	inline List<T> operator+ (List<T>& pList)
	{
		List<T> newList;

		for (int i = 0; i < Count; i++)
		{
			newList.Add(GetElement(i));
		}

		for (int i = 0; i < pList.Count; i++)
		{
			newList.Add(pList.GetElement(i));
		}

		return newList;
	}
	inline List<T> Copy()
	{
		List<T> newList;
		for (int i = 0; i < Count; i++)
		{
			newList.Add(GetElement(i));
		}
		return newList;
	}
	inline T GetElement(int index)
	{
		if (Count > index && index > -1)
		{
			T value = arr[index];
			return value;
		}
		throw invalid_argument("Index Out of Range Exception");
	}
	inline int GetIndexFromValue(T item)
	{
		for (int i = 0; i < Count; i++)
		{
			T element = GetElement(i);
			if (element == item)
			{
				return i;
			}

		}
		return -1;
	}
	inline void Add(T item)
	{
		if (Length == Count)
		{
			ExtendLength();
		}

		arr[Count] = item;
		Count++;
	}
	inline void RemoveItem(T item)
	{
		int index = GetIndexFromValue(item);
		RemoveAtIndex(index);
	}
	inline void RemoveAtIndex(int index)
	{
		for (int i = index; i < Count - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		Count--;
	}
	void Swap(T& pItem1, T& pItem2)
	{
		T temp = pItem1;
		pItem1 = pItem2;
		pItem2 = temp;
	}

};
template<class T>
inline ostream& operator<<(ostream& os, List<T>& list)
{
	for (int i = 0; i < list.Count; i++)
	{
		cout << list[i] << ' ';
	}
	cout << endl;
	return os;
}
