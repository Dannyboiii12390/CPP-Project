// CPPProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lists.h"
#include "Sort.h"

int main()
{
	List<int> list;
	list.Add(34);
	list.Add(42);
	list.Add(321);
	list.Add(1);
	list.Add(3);
	list.Add(-4);

	IntSort sorter;
	list = sorter.BubbleSort(list);

	cout << list;
}
