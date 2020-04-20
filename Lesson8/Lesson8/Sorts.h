#pragma once

#include <iostream>

namespace Sorts
{
	int arr_base[8];

	// Сортирует указанный массив начния с start_i, заканчивая end_i
	void MergeSort(int* arr, int start_i, int end_i)
	{
		if (start_i == end_i)
		{
			return;
		}

		const int middle_i = (start_i + end_i) / 2 + 1;

		MergeSort(arr, start_i, middle_i - 1);
		MergeSort(arr, middle_i, end_i);

		// Имеем 2 отсортированные половинки, надо их слить

		int* temp_arr = new int[end_i - start_i + 1];
		int* arr_1 = arr + start_i;
		int* arr_2 = arr + middle_i;
		int size_1 = middle_i - start_i;
		int size_2 = end_i - middle_i + 1;

		// У тебя есть 2 отсортированных массива arr_1 и arr_2, нодо их слить в массив temp_arr;
		// ...
		// 1 3 4 7 7      2 2 3 5 6 6
		// 1 2 2 3 3 4 5 6 6 7

		// 1 1 1 1 1   2 2 2 2 2 
		// 1 1 1 1 1 
		int ind_1 = 0;
		int ind_2 = 0;
		int temp_ind = 0;

		while (ind_1 < size_1 && ind_2 < size_2)
		{
			if (arr_1[ind_1] < arr_2[ind_2])
			{
				temp_arr[temp_ind] = arr_1[ind_1];
				ind_1++;
			}
			else
			{
				temp_arr[temp_ind] = arr_2[ind_2];
				ind_2++;
			}
			temp_ind++;
		}

		while (ind_1 < size_1)
		{
			temp_arr[temp_ind] = arr_1[ind_1];
			temp_ind++;
			ind_1++;
		}

		while (ind_2 < size_2)
		{
			temp_arr[temp_ind] = arr_2[ind_2];
			temp_ind++;
			ind_2++;
		}


		for (int i = 0; i <= end_i - start_i; i++)
		{
			arr[start_i + i] = temp_arr[i];
		}
		delete[] temp_arr;
	}


	void f()
	{
		
		for (int i = 0; i < 8; i++)
		{
			arr_base[i] = std::rand() % 10;
		}

		MergeSort(arr_base, 0, 7);

		for (int i = 0; i < 8; i++)
		{
			std::cout << arr_base[i] << ' ';
		}
	}


	void g()
	{
		uint64_t a;
		uint64_t b;
		// 0000001
		// 0100000
		// 0011111
		// 1111100
		// ((1 << 5) - 1) << 2 ==  1111100
		// c 2 по 7

		//uint64_t c = a & (((1 << 5) - 1) << 2);

		//c = c >> 2;



		// 0101010101010101000101
		// 0000000000000011111000
		// 0000000000000001000000
		// 01000 = 8

	}
}