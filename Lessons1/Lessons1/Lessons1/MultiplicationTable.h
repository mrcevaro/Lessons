#pragma once
#include <iostream>

void TaskMultiplicationTable(std::ostream& os, std::istream& is)
{
	for (int i = 1; i <= 9; i++)
	{
		for (int y = 1; y <= 9; y++)
		{
			int z = y * i;
			os << i << " * " << y << " = " << z << std::endl;
			if (y == 9) os << std::endl;
		}
	}
}