#pragma once
#include <iostream>

void f()
{
	int n;

	int* v = new int; // Выделяешь один инт
	int* arr = new int[10000]; // Просим у ОС памяти на n интов

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

	// Память нам больше не нужна, надо ее вернуть ОС
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