#pragma once
#include <iostream>


void SwapElement(int* arr, int n)
{
	for (int i = 0; i < n; i++) 
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout  << std::endl;


	int max_element = 0;
	int min_element = 0;

	int index_min_element = 0;
	int index_max_element = 0;

	for (int i = 0; i < n-1; i++)
	{
			const int cur_max = arr[i] > arr[i + 1] ? arr[i] : arr[i + 1];

			if (max_element == 0)
			{
				max_element = cur_max;
			}

			if (cur_max > max_element)
			{
				max_element = cur_max;
				index_max_element = arr[i] > arr[i + 1] ? i : i + 1;
			}

			const int cur_min = arr[i] < arr[i + 1] ? arr[i] : arr[i + 1];
			
			if (min_element == 0) 
			{
				min_element = cur_min;
			}

			if (cur_min < min_element )
			{
				min_element = cur_min;
				index_min_element = arr[i] < arr[i + 1] ? i : i + 1;
			}
	}
	
	const int temp = arr[index_min_element];
    arr[index_min_element] = arr[index_max_element];
	arr[index_max_element] = temp;

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void SwapMaxMinElement()
{
	const int array_size = 5;
	int array[array_size] = { 20, 28, 7, 6, 1 }; //  { 20, 28, 7, 6, 1 } { -4, -6, -3, -8, -9 }

	SwapElement(array, array_size);

	//std::cout << SwapElement(array, array_size) << std::endl;
}