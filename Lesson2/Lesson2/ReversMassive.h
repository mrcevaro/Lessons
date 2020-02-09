#pragma once
#include <iostream>


void PrintReversElements(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = n - 1; i >= 0; i--)
	{
		std::cout << arr[i] << std::endl;
	}
}

void ReversElements()
{
	const int array_size = 5;
	int array[array_size] = { 1, 2, 3, 4, 5 }; //  { 5, 1, 2, 3, 4 }

	PrintReversElements(array, array_size);
}