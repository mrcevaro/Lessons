#pragma once
#include <iostream>

void TaskJumpNumberOrder(std::ostream& os, std::istream& is)
{
	static const int kNumberOfOperation = 10;

	os << 10 << std::endl;
	for (int i = 1; i < 9; i++)
	{
		os << 10 + i << std::endl;
		os << 10 - i << std::endl;
	}
	os << 20 << std::endl;
}
