#pragma once
#include <iostream>

int GetReturnMaxElement(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	int max_element = arr[0];

	for (int i = 1; i < n - 1; i++)
	{
		if (arr[i] > max_element)
		{
			max_element = arr[i];
		}
	}
	return max_element;
}

void SearchMaxElement()
{
	const int array_size = 5;
	int array[array_size] = { -3, -6, -4, -7, -9 };

	std::cout << GetReturnMaxElement(array, array_size) << std::endl;
}