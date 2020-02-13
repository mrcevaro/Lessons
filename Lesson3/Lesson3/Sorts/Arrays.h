#pragma once

int GetFirstMax(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	int last_max_element = 0;
	int index_max_element = 0;

	for (int i = 0; i < n; i++)
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
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > last_max_element)
		{
			last_max_element = arr[i];
			index_last_max_element = i;
		}
		if (arr[i] == last_max_element)
		{
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

	int last_max_element = 0;
	int count_last_max_element = 1;
	int search_element = 3;

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
		if (count_last_max_element == search_element)
		{
			return i;
		}
	}
	return -1;
}

int GetPenultimateMax(int* arr, int n)
{
	if (n == 0)
	{
		return -1;
	}

	int count_max = 0;
	int index_last_max_element = 0;
	int index_first_max_element = 0;
	int index_cur_max_element = 0;

	int count_last_max_element = 1;
	int last_max_element = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == last_max_element)
		{
			count_last_max_element++;

			if (count_last_max_element == 1)
			{
				index_first_max_element = i;
			}
			index_last_max_element = i;
		}
		if (arr[i] > last_max_element)
		{
			last_max_element = arr[i];
			count_last_max_element = 1;
		}
	}
	return index_last_max_element;
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