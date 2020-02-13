#include "Sorts/BubbleSort.h"
#include "Sorts/Arrays.h"
#include <iostream>
int main()
{	
	int arr[12] = { 2,7,4,8,5,6,8,3,1,8,8,4 };
	
	//Sort::BubbleSort(arr, 3);
	std::cout << GetThirdMax(arr, 12) << std::endl;

	std::cout << GetCountOfMax(arr, 12) << std::endl;
	std::cout << GetPenultimateMax(arr, 12) << std::endl;

	/*for (int i = 0; i < 12; i++)
	{
		std::cout << arr[i];
	}*/
	
	std::system("pause");
}