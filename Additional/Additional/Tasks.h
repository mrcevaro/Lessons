#pragma once
#include <iostream>

void PrintArr(int* arr, int n) 
{

	for (int i = 0 ; i < n; i++)
	{
		std::cout << arr[i] << ' ' ;
	}
}

void Task1() 
{
	const int length = 5;
	int arr[length] = { 0, 1, 2, 3, 4 };

	PrintArr(arr, length);

	std::cout << std::endl;
}
