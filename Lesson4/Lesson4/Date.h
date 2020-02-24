#pragma once

//Создать структуру дата(Date), в которой 3 интовских поля.Год, месяц, день.Допустим минимальная дата это 2000 - 01 - 01. Т.е.меньше дата быть не может.
//1. Функция принимает на вход дату, а возвращает дату вчерашнего дня.
//2. Функция принимает на вход 2 даты.Возвращает 0, если они равны, -1 если первая дата меньше второй. 1, если первая дата больше второй.
//3. Функция принимает на вход дату, вернуть время года этой даты.
//4. Принимает на вход дату, вернуть количество дней прошедших с 2000 - 01 - 01. Считаем что в феврале всегда 28 дней.
//Создать структуру «временной отрезок»(TimeSegment).Структура содержит 2 даты._start_date, _end_date.Старт должен быть всегда меньше чем энд.
//4. Сделать конструктор, который принимает две даты, но сетает в поле старт меньшую из них, а в энд большую.
//5. Функция принимает на вход отрезок, а возвращает  количество дней между end и start.Считаем что в феврале всегда 28 дней.
//6. Функция принимает на вход дату и число n.Вернуть отрезок, где стартовой является указанная дата, а end - это указанная дата плюс n дней.

namespace Dates
{
	struct Date
	{
		static const int kDefaultMonth = 1;
		static const int kDefaultYear = 2000;
		static const int kDefaultDay = 1;
		static const int count_days_year = 365;

		static const int kMaxDay = 31;
		static const int kMinDay = 1;
		static const int kMaxMonth = 12;
		static const int kMinMonth = 1;

		int _year = kDefaultYear;
		int _month = kDefaultMonth;
		int _day = kDefaultDay;
	};


	int CountDayOfMonth(int month)
	{
		static const int kDayOfMonth[12]{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return kDayOfMonth[month - 1];
	}

	// Функция принимает на вход 2 даты.Возвращает 0, если они равны, -1 если первая дата меньше второй. 1, если первая дата больше второй.
	int CompareDate(const Date& date1, const Date& date2)
	{
		if (date1._year == date2._year)
		{
			if (date1._month == date2._month)
			{
				if (date1._day == date2._day)
				{
					return 0;
				}
				return date1._day > date2._day ? 1 : -1;
			}
			else
			{
				return date1._month > date2._month ? 1 : -1;
			}
		}
		else
		{
			return date1._year > date2._year ? 1 : -1;
		}

	}

	int DateToNumber(Date date)
	{
		return date._year * 10000 + date._month * 100 + date._day;
	}

	int CompareDate2(Date &date1, Date &date2)
	{
		const auto number_date_1 = DateToNumber(date1);
		const auto number_date_2 = DateToNumber(date2);

		if (number_date_1 == number_date_2)
		{
			return 0;
		}
		return number_date_1 > number_date_2 ? 1 : -1;
	}

	// 2020 2 17 = 20200217
	// 2020 03 18 = 20200218
	// 2020 03 18 = 20200318
	// 2022 03 18 = 20220318

	// Функция принимает на вход 2 даты.Возвращает 0, если они равны, -1 если первая дата меньше второй. 1, если первая дата больше второй.
	int CompareDate1(Date &date1, Date &date2)
	{
		if (date1._year != date2._year)
		{
			return date1._year > date2._year ? 1 : -1;
		}

		if (date1._month != date2._month)
		{
			return date1._month > date2._month ? 1 : -1;
		}

		if (date1._day != date2._day)
		{
			return date1._day > date2._day ? 1 : -1;
		}

		return 0;
	}
	// Функция принимает на вход дату, а возвращает дату вчерашнего дня.
	Date GetYeasterdayDate(const Date& date)
	{
		if (date._day == 1 && date._month == 1)
		{
			return Date{ date._year - 1, Date::kMaxMonth, Date::kMaxDay };
		}
		else
		{
			if (date._day == 1)
			{
				return Date{ date._year, date._month - 1, CountDayOfMonth(date._month - 1) };
			}
			else
			{
				return Date{ date._year, date._month, date._day - 1 };
			}
		}
	}

	//весна начинается 1 марта, лето — 1 июня, осень — 1 сентября, а зима — 1 декабря.

	enum class Season
	{
		Winter = 0,
		Spring = 1,
		Summer = 2,
		Autumn = 3
	};
	// Функция принимает на вход дату, вернуть время года этой даты.
	Season GetSeason(const Date &date)
	{
		if (date._month == 12 || date._month < 3)
		{
			return Season::Winter;
		}
		else if (date._month >= 3 || date._month <= 5)
		{
			return Season::Spring;
		}
		else if (date._month >= 6 || date._month <= 8)
		{
			return Season::Summer;
		}
		else if (date._month >= 9 || date._month <= 11)
		{
			return Season::Autumn;
		}
	}
	// Функция принимает на вход дату, вернуть количество дней прошедших с 2000 - 01 - 01. Считаем что в феврале всегда 28 дней.
	int GetCountDay(const Date &date)
	{
		const int difference_years = date._year - Date::kDefaultYear;
		const int difference_days = date._day - Date::kDefaultDay;
		int general_count_days_for_months = 0;

		for (int i = 1; i < date._month; i++)
		{
			general_count_days_for_months += CountDayOfMonth(i);
		}

		return difference_years * Date::count_days_year + general_count_days_for_months + difference_days;
	}

	Date GetDateByDays(int days)
	{
		// % - остаток от деления
		// / - частное с округлением
		// 2  - 2000-01-02
		// 32 - 2000-02-02

	// 0 - 2000-01-01
	}

}