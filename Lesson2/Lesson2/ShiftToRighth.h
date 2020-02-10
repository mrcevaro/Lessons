#pragma once
#include <iostream>


void ShiftElements(int* arr, int n)
{
	const int last_element = arr[n - 1];
	
	// 1 2 3 4 5
	for (int i = n - 1; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	// 1 0 1 2 3

	arr[0] = last_element;

	// 5 0 1 2 3
}


void swap(int& a, int& b)
{
	const int temp = a;
	a = b;
	b = temp;
}


void Reverse(int* arr, int n)
{
	const int last_element = arr[n - 1];

	// 0 1 2 3 4
	// 4 3 2 1 0

	// 0 <-> 4
	// 1 <-> 3
	// 2 <-> 2
	//swap(arr[0], arr[4]);
	//swap(arr[1], arr[3]);
	//swap(arr[2], arr[2]);

	for (int i = 0; i < n / 2; i++)
	{
		swap(arr[i], arr[n - i - 1]);
	}
}

void ShiftToRightElements()
{
	const int array_size = 5;
	int array[array_size] = { 1, 2, 3, 4, 5 }; //  { 5, 1, 2, 3, 4 }

	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << std::endl;

//	ShiftElements(array, array_size);
	
	Reverse(array, array_size);

	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << ' ' ;
	}
}