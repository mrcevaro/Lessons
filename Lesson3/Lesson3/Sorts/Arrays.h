#pragma once

int Task_1_1_GetFirstMax(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	int last_max_element = arr[0];
	int index_max_element = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > last_max_element)
		{
			last_max_element = arr[i];
			index_max_element = i;
		}
	}
	return index_max_element;
}

int GetLastMax(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	int last_max_element = arr[0];
	int index_last_max_element = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= last_max_element)
		{
			last_max_element = arr[i];
			index_last_max_element = i;
		}
	}
	return index_last_max_element;
}


int GetThirdMax(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	static const int kSearchMaxCount = 3;

	int max_element = arr[0];
	int count_max_element = 1;
	int index_search_max_element = -1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] ==max_element)
		{
			count_max_element++;
		}
		else if (arr[i] > max_element)
		{
			max_element = arr[i];
			count_max_element = 1;
		}
		if (count_max_element == kSearchMaxCount)
		{
			index_search_max_element = i;
		}
	}
	return index_search_max_element;
}

int GetPenultimateMax(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	int index_max_element = 0;
	int index_penultimate_max_element = -1;
	int max_element = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == max_element)
		{
			// гарантированно имеешь индекс последнего максимума на данный момкент index_last_max_element
			index_penultimate_max_element = index_max_element;
			index_max_element = i;
		}
		if (arr[i] > max_element)
		{
			max_element = arr[i];
			index_penultimate_max_element = -1;
			index_max_element = i;
		}
	}
	return index_penultimate_max_element;
}

int GetCountOfMax(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	int count_last_max_element = 1;
	int last_max_element = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == last_max_element)
		{
			count_last_max_element++;
		}
		if (arr[i] > last_max_element)
		{
			last_max_element = arr[i];
			count_last_max_element = 1;
		}
	}
	return count_last_max_element;
}



int Task_1_6_AlmostMax(int* arr, int n)
{
	// Задача 1.6. Почти максимум
		// Функция получает на вход массив и его размер.
		// Вернуть число которое было бы максимальным, если бы не было максимального.
		// Иными словами, предмаксимум
		//	test.ExpectEq({ 2,9,9,4,7,5,6,9,3,1,9,7,4 }, 7); // Максимум тут 9, следом за ним идет число 7
	//test.ExpectEq({ 1,2,3,4,3,2,1 }, 3);

	if (n == 0)
	{
		return -1;
	}

	int index_max_element = 0;
	int index_prev_max_element = -1;
	int max_element = arr[0];

	int prev_max_element = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max_element)
		{
			max_element = arr[i];
		}
		if (arr[i] < max_element)
		{
			if (arr[i] > prev_max_element)
			{
				prev_max_element = arr[i];
			}
		}
	}
	return prev_max_element;
}

