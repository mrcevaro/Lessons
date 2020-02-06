#pragma once
#include <iostream>

void TaskMultiplicationTable(std::ostream& os, std::istream& is)
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			os << i << " * " << j << " = " << i * j << std::endl;
		}
		os << std::endl;
	}
}