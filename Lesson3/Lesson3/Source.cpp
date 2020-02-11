#include "Sorts/BubbleSort.h"
#include <iostream>
int main()
{	
	int arr[5] = { 1, 4, 3, 2, 5 };
	
	Sort::BubbleSort(arr, 3);
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i];
	}
	
	std::system("pause");
}