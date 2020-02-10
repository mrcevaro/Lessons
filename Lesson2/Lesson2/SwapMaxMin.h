#pragma once
#include <iostream>


void SwapElement(int* arr, int n)
{
	if (n == 0)
	{
		return;
	}

	int max_element = arr[0];
	int min_element = arr[0];

	int index_min_element = 0;
	int index_max_element = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max_element)
		{
			max_element = arr[i];
			index_max_element = i;
		}

		if (arr[i] < min_element)
		{
			min_element = arr[i];
			index_min_element = i;
		}
	}
	
	const int temp = arr[index_min_element];
    arr[index_min_element] = arr[index_max_element];
	arr[index_max_element] = temp;


}

void SwapMaxMinElement()
{
	const int array_size = 5;
	int array[array_size] = { 20, 28, 7, 6, 1 }; //  { 20, 28, 7, 6, 1 } { -4, -6, -3, -8, -9 }

	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << std::endl;

	SwapElement(array, array_size);
	
	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << std::endl;
	}
	//std::cout << SwapElement(array, array_size) << std::endl;
}