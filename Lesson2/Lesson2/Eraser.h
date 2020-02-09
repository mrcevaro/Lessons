#pragma once
#include <iostream>


void Erase(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;


	int max_element = 0;
	int min_element = 0;

	int index_min_element = 0;
	int index_max_element = 0;

	for (int i = 0; i < n - 1; i++)
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

		if (cur_min < min_element)
		{
			min_element = cur_min;
			index_min_element = arr[i] < arr[i + 1] ? i : i + 1;
		}
	}


	const int A = (max_element + min_element) / 2;

	for (int i = 0; i < n; i++)
	{
		
		if (arr[i] > A) 
		{
			arr[i] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}


void EraserElements()
{
	const int array_size = 7;
	int array[array_size] = { 3, 9, 5, 8, 2, 1, 9 }; //  { 20, 28, 7, 6, 1 } { -4, -6, -3, -8, -9 }

	Erase(array, array_size);

	//std::cout << SwapElement(array, array_size) << std::endl;
}