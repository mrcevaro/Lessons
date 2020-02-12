#pragma once

int GetFirstMax(int* arr, int n)
{
	int max_elements = arr[0];
	int index_max_elements = 0;

	for (int i = 0; i < n; i++) 
	{
		if (arr[i] > max_elements)
		{
			 max_elements = arr[i];
			 index_max_elements = i;
		}
	}
	return index_max_elements;
}

int GetLastMax(int* arr, int n)
{
	int max_elements = arr[0];
	int index_max_elements = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max_elements)
		{
			max_elements = arr[i];
			index_max_elements = i;
		}
		if (arr[i] == max_elements)
		{
			index_max_elements = i;
		}
	}
	return index_max_elements;
}


int GetThirdMax(int* arr, int n)
{
	int max_elements = arr[0];
	int index_max_elements = 0;
	int count_max = 0;
	int max_count_of_max = 3;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max_elements)
		{
			max_elements = arr[i];
			index_max_elements = i;
		}
		if (arr[i] == max_elements && count_max != max_count_of_max)
		{
			index_max_elements = i;
			count_max++;
		}
		
	}
	if (count_max == max_count_of_max)
	{
		return index_max_elements;
	}else
		return -1;
}