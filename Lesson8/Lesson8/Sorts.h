#pragma once

#include <iostream>

namespace Sorts
{
	void MergeSort(int* arr, int start_i, int end_i)
	{
		if (start_i == end_i)
		{
			return;
		}

		const int middle_i = (start_i + end_i) / 2;

		MergeSort(arr, start_i, middle_i - 1);
		MergeSort(arr, middle_i, end_i);

		int* temp_arr = new int[end_i - start_i + 1];
		int* arr_1 = arr + start_i;
		int* arr_2 = arr + middle_i;

		// У тебя есть 2 отсортированных массива arr_1 и arr_2, нодо их слить в массив temp_arr;
		// ...

		for (int i = 0; i <= end_i - start_i; i++)
		{
			arr[start_i + i] = temp_arr[i];
		}
		delete[] temp_arr;
	}


	void f()
	{
		int arr[10];
		for (int i = 0; i < 10; i++)
		{
			arr[i] = std::rand() % 10;
		}

		MergeSort(arr, 0, 9);

		for (int i = 0; i < 10; i++)
		{
			std::cout << arr[i] << ' ';
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

		uint64_t c = a & (((1 << 5) - 1) << 2);

		c = c >> 2;



		// 0101010101010101000101
		// 0000000000000011111000
		// 0000000000000001000000
		// 01000 = 8

	}
}