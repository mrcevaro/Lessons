#pragma once
#include <iostream>

void TaskNumberOrder(std::ostream& os, std::istream& is)
{
	int value = 0;
	is >> value;

	//for (int i = 1; i <= value; i++)
	//{
	//	os << i << std::endl;
	//}
	//for (int i = value*2; i >= value; i--)
	//{
	//	os << i << std::endl;
	//}

	for (int i = 0; i <= 2*value + 1; i++)
	{
		if (i <= value)
		{
			os << i << std::endl;
		}
		else
		{
			os << 3 * value - i + 1 << std::endl;
		}
	}
}