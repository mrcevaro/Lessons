#pragma once
#include <iostream>

int GetReturnMaxElement(int* arr, int n)
{
	int max_element = 0;

	for (int i = 0; i < n; i++)
	{
		const int cur_max = arr[i] > arr[i + 1] ? arr[i] : arr[i + 1];
		if (cur_max > max_element)
		{
			max_element = cur_max;
		}
	}
	return max_element;
}

void SearchMaxElement()
{
	const int array_size = 5;
	int array[array_size] = { 20, 1, 7, 6, 28 };

	std::cout << GetReturnMaxElement(array, array_size) << std::endl;
}