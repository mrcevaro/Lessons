#pragma once
#include <iostream>

static void Task0_ArrayIncrease(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] *= 2;
		}
		else
		{
			arr[i] *= 3;
		}
	}
}

static void HomeWork1()
{
	int a = 0;

	static const int kArraySize = 10;
	int arr[kArraySize] = { 0 };

	for (int i = 0; i < kArraySize; i++)
	{
		arr[i] = std::rand() % 10 + 10;
	}

	Task0_ArrayIncrease(arr, kArraySize);

	for (int i = 0; i < kArraySize; i++)
	{
		std::cout << arr[i] << ' ';
	}

	std::cout << std::endl;
}