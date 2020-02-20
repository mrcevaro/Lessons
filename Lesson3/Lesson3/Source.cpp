#include "Sorts/BubbleSort.h"
#include "Sorts/ArrayTask.h"
#include "Sorts/Arrays.h"
#include <iostream>
int main()
{
	//int arr[12] = { 2,7,4,8,5,6,3,9,14,1,10,12 };
	//Sort::BubbleSort(arr, std::size(arr));
	//for (int i = 0; i < std::size(arr); i++)
	//{
	//	std::cout << arr[i] << std::endl;
	//}
	//std::cout << GetThirdMax(arr, 12) << std::endl;
	//
	//std::cout << GetCountOfMax(arr, 12) << std::endl;
	//std::cout << GetPenultimateMax(arr, 12) << std::endl;

	//int arr1[6] = { 1, -2, 2, 3, -2, 4 };

	int arr1[11] = { 2, 1, 2,-1,3,-1,-1,4,5,-1,6 };

	for (int i = 0; i < std::size(arr1); i++)
	{
		std::cout << arr1[i] << ", ";
	}

	std::cout  << std::endl;

	Task_2_2_RemoveAndShrink(arr1, std::size(arr1));

	for (int i = 0; i < std::size(arr1); i++)
	{
		std::cout << arr1[i] << ", ";
	}
	std::cout << std::endl;

	std::system("pause");
}