#pragma once
#include <iostream>


void PrintZeroingElements(int* arr, int n)
{
	for (int i = 0; i < n ; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < n ; i++)
	{
		if (arr[i] > 0) 
		{
			arr[i] = 0;
		}
		std::cout << arr[i] << std::endl;
	}
}

void ZeroingElements()
{
	const int array_size = 5;
	int array[array_size] = { 12, -4, 1, 2, -5 }; //  { 5, 1, 2, 3, 4 }

	PrintZeroingElements(array, array_size);
}
