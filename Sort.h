#pragma once
#include "Lists.h"

template<class T>
class Sorting
{
public:

	List<T>& BubbleSort(List<T>& pList);
	List<T>& InsertionSort(List<T>& pList);
	List<T>& MergeSort(List<T>& pList);
	List<T>& QuickSort(List<T>& pList);

};
class FloatSort : Sorting<float>
{
	
};

class DoubleSort : Sorting<double>
{

};

class IntSort : Sorting<int>
{
public:
	List<int>& BubbleSort(List<int>& pList)
	{
		for (int k = 0; k < pList.Count - 1; k++)
		{
			for (int i = 0; i < pList.Count-1; i++)
			{
				int num1 = pList[i];
				int num2 = pList[i + 1];
				if (num1 > num2)
				{
					pList.Swap(num1, num2);
				}
			}
		}
		return pList;
	}

	List<int>& InsertionSort(List<int>& pList)
	{
		return pList;
	}
	List<int>& MergeSort(List<int>& pList)
	{
		return pList;
	}
	List<int>& QuickSort(List<int>& pList)
	{
		return pList;
	}
};