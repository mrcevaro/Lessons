#pragma once
#include <iostream>


void PrintSumElements(int* arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	std::cout << sum << std::endl;
}

void SumElements()
{
	const int array_size = 5;
	int array[array_size] = { 12, 1, 1, 1, 1 }; //  { 5, 1, 2, 3, 4 }

	PrintSumElements(array, array_size);
}
