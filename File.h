#pragma once

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Lists.h"

using namespace std;

template<class T>
class FileIO
{
private:

	string Path;

public:

	FileIO(const string& pPath)
	{
		Path = pPath;
	}
	List<List<T>> Read(const int NumValuesPerLine, const int NumLines)
	{
		ifstream file(Path);
		List<List<T>> list;

		for (int i = 0; i < NumLines; i++)
		{
			List<T> tempList;
			for (int k = 0; k < NumValuesPerLine; k++)
			{
				T x;
				file >> x;
				tempList.Add(x);
			}
			list.Add(tempList);
		}
		return list;


	}
	void Write(List<List<T>>& pList)
	{
		ofstream file(Path);
		stringstream ss;

		for (int i = 0; i < pList.Count; i++)
		{
			List<T> tempList = pList.GetElement(i);
			for (int k = 0; k < tempList.Count; k++)
			{
				ss << tempList[k] << " ";
			}
			ss << endl;
		}
		file << ss.str();
	}

};