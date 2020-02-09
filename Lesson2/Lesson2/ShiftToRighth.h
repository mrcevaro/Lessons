#pragma once
#include <iostream>


void ShiftElements(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;

	int count = 0;
	int temp = 0;
	int temp2 = 0;

	int* arr2 = arr;
	for (int i = n - 1; i > 0 ;i--)
	{
		
		arr2[count]= arr[i];
		count++;
	}		


	for (int i = 0; i < n; i++)
	{
		std::cout << arr2[i] << std::endl;
	}
}

void ShiftToRightElements()
{
	const int array_size = 5;
	int array[array_size] = { 1, 2, 3, 4, 5 }; //  { 5, 1, 2, 3, 4 }

	ShiftElements(array, array_size);
}