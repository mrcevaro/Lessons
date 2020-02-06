#pragma once
#include <iostream>

bool IsDivisionWithoutRemainder(int cur_number, int seacrh_number)
{
	return (cur_number % seacrh_number) == 0;
}


/*
Вводятся 2 числа N M. Вывести первое число, которое делится без остатка и на N и на M.
Пример ввода: 3 5. Вывод: 15
*/

void TaskDivision(std::ostream& os, std::istream& is)
{
	int n_number = 0;
	int m_number = 0;
	is >> n_number;
	is >> m_number;

	int cur_number = 1;

	while (true)
	{
		if (IsDivisionWithoutRemainder(cur_number, n_number) && IsDivisionWithoutRemainder(cur_number, m_number))
		{
			os << cur_number << std::endl;
			return;
		}
		cur_number++;
	}
}