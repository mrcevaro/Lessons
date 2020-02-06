#pragma once
#include <iostream>

void TaskJumpNumberOrder(std::ostream& os, std::istream& is)
{
	int number_of_operation = 10;
	int up_counter = number_of_operation;
	
	for (int down_counter = number_of_operation; down_counter > 0; )
	{
		os << down_counter << std::endl;
		down_counter--;
		up_counter++;
		os << up_counter << std::endl;
	}
}