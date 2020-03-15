#pragma once
#include "DynamicArray.h"

class SortedArray
{
	DynamicArray _dm;

public:

	void AddValue(int value) // �������� �������, ����� ������ ������� ��������������
	{
		_dm.PushBack(value);

		
	}

	void Print()
	{
		_dm.Print();
	}

	SortedArray(int size)
		: _dm(size) {}
		
	~SortedArray() {}

};

