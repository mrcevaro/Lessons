//Hello Unicode World ☺. ☻.
#pragma once
#include <iostream>

void TestDynamicMemory()
{
	int n; // Переменная выделенная на стеке
	std::cin >> n;
	
	int* v = new int; // Просим у ОС выделить нам память под один инт в куче
	int* arr = new int[n]; // Просим у ОС выделить в куче 10000 интов

	for (int i = 0; i < n; i++)
	{
		arr[i] = std::rand() % 10;
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 3)
		{
			return; // Беда! Будет утечка памяти, т.к. мы не сделали delete
		}
	}

	//..

	for (int i = 0; i < n; i++)
	{
		arr[i] = std::rand() % 10;
	}

	// Освобождаем память, отдавая ее ОС
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