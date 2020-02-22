//Hello Unicode World ☺. ☻.
#pragma once
#include <iostream>
void Task_2_2_RemoveAndShrink(int* arr, int n)
{
	//arr[0] = arr[1];
	//arr[1] = arr[2];
	//arr[2] = arr[3];
	//arr[3] = arr[4];
	//test.ExpectEq({ 0, 1, 2,-1,-2,-1,-1,4,5,-1,6 }, {1,2,3,4,5,6,0,0,0,0,0});
	//test.ExpectEq({ 0, 1, 2,-1,-2,-1,-1,4,5,-1,6 }, {1,2,3,4,5,6,0,0,0,0,0});
	//test.ExpectEq({ 0, 1, 2,-2,-1,-1,4,5,-1,6, 0 }, {1,2,3,4,5,6,0,0,0,0,0});
	//test.ExpectEq({ 0, 1, 2,-1,-1,4,5,-1,6, 0, 0 }, {1,2,3,4,5,6,0,0,0,0,0});
	//test.ExpectEq({ 0, 1, 2,-1,4,5,-1,6, 0, 0, 0 }, {1,2,3,4,5,6,0,0,0,0,0});
	int count_of_shrinks = 0;
	for (int i = 0; i < n - count_of_shrinks; i++)
	{
		if (arr[i] <= 0)
		{
			for (int j = i; j < n - 1; j++)
			{
 				arr[j] = arr[j + 1];
			}
			arr[n - 1] = 0;
			i--;
			count_of_shrinks++;
		}
	}
}

// Задача 2.4. Вытащить максимум
// На вход функции подается массив и его размер
// Гарантируется что в массиве нет повторяющихся элементов.
// Необходимо поместить максимум в конец массива, с сохранением порядка остальных элементов
void Task_2_4_MoveMaxElement(int* arr, int n)
{
	int max_element = arr[0];
	int index_max_element = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max_element)
		{
			max_element = arr[i];
			index_max_element = i;
		}
	}

	for (int i = index_max_element; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = max_element;
}

int Task_2_3_MaxSegment(int* arr, int n)
{
	int length = 1;
	int max_element = arr[0];
	int prev_length = 0;
	for (int i = 0; i < n; i++) 
	{
		
		if (max_element == arr[i])
		{
			length++;
		}else if (arr[i] > max_element)
		{
			prev_length = length;
			max_element = arr[i];
			length = 1;
		}
		
		

	
	}
	return length > prev_length ? length : prev_length;
}