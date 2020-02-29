#pragma once
#include <iostream>

/*1.4.Дан массив размера n.В массиве могут быть только числа 0, 1, 2, 3, 4. Вывести сколько раз встречается каждое число.
		Привем ввода : 3 2 3 4 0 0 0 2 4 3
		Вывод :
		0 - 3
		1 - 0
		2 - 2
		3 - 3
		4 - 2

	*/

void SimpleRealize(int* arr, int n)
{
	// { 1, 1`000`000, 1`000`000,2 }
	/*
		1 - 1
		1000000 - 2
		2 - 1
	*/
	int counts[5] = { 0 };
	//O(n);
	// n

	for (int i = 0; i < n; i++)
	{
		const int z = arr[i];
		counts[z]++;
	}

	for (int i = 0; i < 5; i++)
	{
		if (counts[i] != 0)
		{
			std::cout << i << " - " << counts[i] << std::endl;
		}
	}
}