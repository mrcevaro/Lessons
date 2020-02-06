#pragma once
#include <iostream>

bool IsDivisionWithout(int seacrh_number, int cur_number)
{
	if (cur_number % seacrh_number == 0)
	{
		return true;
	}

	return false;
}

void TaskDivision(std::ostream& os, std::istream& is)
{
	int n_number = 0;
	int m_number = 0;
	os << "Input value 1,2" << std::endl;
	is >> n_number;
	is >> m_number;

	int cur_number = 1;

	while (true)
	{
		if (IsDivisionWithout(n_number, cur_number) && IsDivisionWithout(m_number, cur_number))
		{
			os << cur_number << std::endl;
			return;
		}
		cur_number++;

	}
}