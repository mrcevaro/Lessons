#pragma once
#include <iostream>


int GetIndexFour(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 4)
		{
			return i;
		}
		
	}
	return -1;
}

void IndexFour()
{
	const int array_size = 7;
	int array[array_size] = { 3, 9, 5, 4, 5, 8, 5 }; 

	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << GetIndexFour(array, array_size) << std::endl;
}


void PrintZeroingElementsAfterFive(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 5)
		{
			for (int j = i + 1; j < n; j++)
			arr[j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void ZeroingElementsAfterFive()
{
	const int array_size = 7;
	int array[array_size] = { 3, 8, 4, 5, 7, 3, 3 };


	PrintZeroingElementsAfterFive(array, array_size);
}


int GetCountZero(int* arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			count++;
		}

	}
	return count;
}

void CoutZeroElements()
{
	const int array_size = 7;
	int array[array_size] = { 0, 1, 0, 1, 1, 1, 0 };

	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << GetCountZero(array, array_size) << std::endl;
}

int GetCountTransformZeroToOne(int* arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0 && arr[i+1] == 1)
		{
			count++;
		}

	}
	return count;
}

void CountTransformZeroToOne()
{
	const int array_size = 8;
	int array[array_size] = { 0, 0, 1, 0, 1, 1, 0, 1 };

	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << GetCountTransformZeroToOne(array, array_size) << std::endl;
}