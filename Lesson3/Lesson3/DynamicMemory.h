#pragma once
#include <iostream>

void f()
{
	int n;

	int* v = new int; // ��������� ���� ���
	int* arr = new int[10000]; // ������ � �� ������ �� n �����

	return;

	for (int i = 0; i < n; i++)
	{
		arr[i] = std::rand() % 10;
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 3)
		{
			return;
		}
	}

	//..

	for (int i = 0; i < n; i++)
	{
		arr[i] = std::rand() % 10;
	}

	// ������ ��� ������ �� �����, ���� �� ������� ��
	delete  v;
	delete[] arr;
}

void DynamicTask()
{
	for (int i = 0; i < 1000000; i++)
	{
		f();
	}
	std::cout << "AAA" << std::endl;
}