#pragma once
#include <iostream>



void TaskAngle(std::ostream& os, std::istream& is)
{
	int value = 0;
	os << " Input value" << std::endl;
	is >> value;

	for (int column = 0; column <= value; column++)
	{
		for (int amount = 0; amount <= column; amount++)
		{
			os << "*";
		}
		os << std::endl;

	}

}

//void TaskAngle(std::ostream& os, std::istream& is)
//{
//	int value = 0;
//	os << " Input value" << std::endl;
//	is >> value;
//	int column = 1;
//	for (int row = 0; row <= value; row++)
//	{
//		for (; column <= row / column; column++) {
//
//
//			os << " ";
//
//		}
//		for (int amount = 0; amount <= row; amount++)
//		{
//			os << "*";
//		}
//		os << std::endl;
//
//	}
//
//}