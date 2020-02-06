#pragma once

#include <iostream>

void TaskAngle(std::ostream& os, std::istream& is)
{
	int value = 0;
	is >> value;

	for (int row = 0; row <= value; row++)
	{
		for (int amount = 0; amount <= row; amount++)
		{
			os << "*";
		}
		os << std::endl;
	}
}




void TaskAngleReverse(std::ostream& os, std::istream& is)
{
	int value = 0;
	is >> value;
		
	for (int row = 0; row < value; row++)
	{
		for (int i = 0; i < value - row - 1; i++)
		{
			os << " ";
		}
		for (int i = 0; i <= row; i++)
		{
			os << "*";
		}
		os << std::endl;
	}
}