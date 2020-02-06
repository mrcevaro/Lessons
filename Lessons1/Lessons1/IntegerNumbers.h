#pragma once
#include <iostream>

void TaskIntegerNumbers(std::ostream& os, std::istream& is)
{
	int value1 = 0;
	int value2 = 0;
	is >> value1;
	is >> value2;
	
	const int end_value   = value1 > value2 ? value1 : value2;
	const int start_value = value1 > value2 ? value2 : value1;

	for (int i = start_value; i <= end_value; i++) 
	{
		os << i << std::endl;
	}
}