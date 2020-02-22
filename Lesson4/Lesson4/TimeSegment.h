#pragma once

#include "Date.h"

//Создать структуру «временной отрезок»(TimeSegment).Структура содержит 2 даты._start_date, _end_date.Старт должен быть всегда меньше чем энд.
//4. Сделать конструктор, который принимает две даты, но сетает в поле старт меньшую из них, а в энд большую.
//5. Функция принимает на вход отрезок, а возвращает  количество дней между end и start.Считаем что в феврале всегда 28 дней.
//6. Функция принимает на вход дату и число n.Вернуть отрезок, где стартовой является указанная дата, а end - это указанная дата плюс n дней.

struct TimeSegment
{
	Dates::Date _start_date;
	Dates::Date _end_date;

	TimeSegment (Dates::Date date1, Dates::Date date2) 
	{
		if (Dates::CompareDate1(date1, date2) == -1)
		{
			_start_date = date1;
			_end_date = date2;
		}
		else
		{
			_start_date = date2;
			_end_date = date1;
		}
	}
};


int CountDayTimeSegment(const TimeSegment &time_segment) 
{
	return GetCountDay(time_segment._end_date) - GetCountDay(time_segment._start_date);

	const int segment_years = time_segment._end_date._year - time_segment._start_date._year;
	const int segment_days = time_segment._end_date._day - time_segment._start_date._day;
	const int segment_month = time_segment._end_date._month - time_segment._start_date._month;

	int count_days_months = 0;

	for (int i = 1; i < segment_month; i++)
	{
		count_days_months += Dates::CountDayOfMonth(i);
	}

	return segment_years * 365 + count_days_months + segment_days;
}