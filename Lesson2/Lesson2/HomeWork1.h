#pragma once
#include <iostream>

void ItArr(int* arr, int n)
{
	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << arr[i] << ' ';
	//}
	//
	//std::cout << std::endl;
	//
	//for (int i = n - 1; i >= 0; i--)
	//{
	//	std::cout << arr[i] << ' ';
	//}

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

void HomeWork1() 
{
	int a = 0;

	static const int kArraySize = 10;
	int arr[kArraySize] = { 0 };

	for (int i = 0; i < kArraySize; i++)
	{
		arr[i] = std::rand() % 10 + 10;
	}

	ItArr(arr, kArraySize);

	for (int i = 0; i < kArraySize; i++)
	{
		std::cout << arr[i] << ' ';
	}

	std::cout << std::endl;
}