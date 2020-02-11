//Hello Unicode World ☺. ☻.
#pragma once

namespace Sort
{
	int GetIndexOfMin(int* arr, int n, int start_index)
	{
		int min = arr[start_index];
		int min_index = start_index;
		for (int i = start_index; i < n; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				min_index = i;
			}
		}
		return min_index;
	}

	void swap(int& a, int& b)
	{
		const int temp = a;
		a = b;
		b = temp;
	}

	// Сортировка выбором. 
	void SelectionSort(int* arr, int n)
	{
		// 3 5 2 9 0 1    0  [0,6-1]
		// 0  5 2 9 3 1   1	 [1,6-1]
		// 0 1  2 9 3 5   2	 [2,6-1]
		// 0 1 2  9 3 5   3	 [3,6-1]	
		// 0 1 2 3  9 5   4	 [4,6-1]	
		// 0 1 2 3 5  9		 [5,6-1]


		// 3 5 2 9 0 1
		// 0 5 2 9 3 1 
		// 0 1 2 9 3 5 

		for (int i = 0; i < n; i++)
		{
			const int index_of_min = GetIndexOfMin(arr, n, i);
			swap(arr[i], arr[index_of_min]);
		}
		// 0 1 2 3 5 9
	}
}