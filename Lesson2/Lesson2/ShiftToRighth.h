#pragma once
#include <iostream>


void ShiftElements(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;

	int count = n-1;
	int temp = 0;
	int temp2 = 0;

	
	for (int i = 0; i < n - 1 ; i++)
	{
	
		for (int j = n - 1; j >= 0; j--) 
		{
arr[j] = arr[i];		
temp2 =  arr[j];
			
		}
		
		
		arr[i] = temp2;

	}		


	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void ShiftToRightElements()
{
	const int array_size = 5;
	int array[array_size] = { 1, 2, 3, 4, 5 }; //  { 5, 1, 2, 3, 4 }

	ShiftElements(array, array_size);
}