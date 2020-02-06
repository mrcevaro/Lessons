#pragma once
#include <iostream>

void TaskIntegerNumbers(std::ostream& os, std::istream& is)
{
	int value1 = 0;
	int value2 = 0;
	os << " Input 2 values " << std::endl;
	is >> value1;
	is >> value2;
	
	int  end_value = 0;
	int  start_value = 0;
	if (value1 > value2)
	{
		start_value = value2;
		end_value = value1;
	}
	else
	{
		start_value = value1;
		end_value = value2;
	}
	

	for (int i = start_value; i <= end_value; i++) 
	{
		os << i << std::endl;
	}
}