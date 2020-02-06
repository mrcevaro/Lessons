#pragma once
#include <iostream>

void TaskNumberOrder(std::ostream& os, std::istream& is)
{
	int value = 0;
	os << "Input value" << std::endl;
	is >> value;

	int count1 = 0;
	int count2 = 0;
	int out_value = 0;
	int revers_out_value = value*2;

	while (true)
	{
		if(count1 <= value)
		{
			os << out_value << std::endl;
			out_value++;
			count1++;
		}
		else if(count2 <= value)
		{
			os << revers_out_value << std::endl;
			revers_out_value--;
			count2++;
		}
	}
}