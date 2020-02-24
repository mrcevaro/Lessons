#pragma once

//������� ��������� ����(Date), � ������� 3 ��������� ����.���, �����, ����.�������� ����������� ���� ��� 2000 - 01 - 01. �.�.������ ���� ���� �� �����.
//1. ������� ��������� �� ���� ����, � ���������� ���� ���������� ���.
//2. ������� ��������� �� ���� 2 ����.���������� 0, ���� ��� �����, -1 ���� ������ ���� ������ ������. 1, ���� ������ ���� ������ ������.
//3. ������� ��������� �� ���� ����, ������� ����� ���� ���� ����.
//4. ��������� �� ���� ����, ������� ���������� ���� ��������� � 2000 - 01 - 01. ������� ��� � ������� ������ 28 ����.
//������� ��������� ���������� �������(TimeSegment).��������� �������� 2 ����._start_date, _end_date.����� ������ ���� ������ ������ ��� ���.
//4. ������� �����������, ������� ��������� ��� ����, �� ������ � ���� ����� ������� �� ���, � � ��� �������.
//5. ������� ��������� �� ���� �������, � ����������  ���������� ���� ����� end � start.������� ��� � ������� ������ 28 ����.
//6. ������� ��������� �� ���� ���� � ����� n.������� �������, ��� ��������� �������� ��������� ����, � end - ��� ��������� ���� ���� n ����.

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

	// ������� ��������� �� ���� 2 ����.���������� 0, ���� ��� �����, -1 ���� ������ ���� ������ ������. 1, ���� ������ ���� ������ ������.
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

	// ������� ��������� �� ���� 2 ����.���������� 0, ���� ��� �����, -1 ���� ������ ���� ������ ������. 1, ���� ������ ���� ������ ������.
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
	// ������� ��������� �� ���� ����, � ���������� ���� ���������� ���.
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

	//����� ���������� 1 �����, ���� � 1 ����, ����� � 1 ��������, � ���� � 1 �������.

	enum class Season
	{
		Winter = 0,
		Spring = 1,
		Summer = 2,
		Autumn = 3
	};
	// ������� ��������� �� ���� ����, ������� ����� ���� ���� ����.
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
	// ������� ��������� �� ���� ����, ������� ���������� ���� ��������� � 2000 - 01 - 01. ������� ��� � ������� ������ 28 ����.
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
		// % - ������� �� �������
		// / - ������� � �����������
		// 2  - 2000-01-02
		// 32 - 2000-02-02

	// 0 - 2000-01-01
	}

}