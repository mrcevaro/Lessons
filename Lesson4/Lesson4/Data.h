#pragma once
//������� ��������� ����(Date), � ������� 3 ��������� ����.���, �����, ����.�������� ����������� ���� ��� 2000 - 01 - 01. �.�.������ ���� ���� �� �����.
//1. ������� ��������� �� ���� ����, � ���������� ���� ���������� ���.
//2. ������� ��������� �� ���� 2 ����.���������� 0, ���� ��� �����, -1 ���� ������ ���� ������ ������. 1, ���� ������ ���� ������ ������.
//3. ������� ��������� �� ���� ����, ������� ����� ���� ���� ����.
//4. ��������� �� ���� ����, ������� ���������� ���� ��������� � 2000 - 01 - 01.
//������� ��������� ���������� �������(TimeSegment).��������� �������� 2 ����._start_date, _end_date.����� ������ ���� ������ ������ ��� ���.
//4. ������� �����������, ������� ��������� ��� ����, �� ������ � ���� ����� ������� �� ���, � � ��� �������.
//5. ������� ��������� �� ���� �������, � ����������  ���������� ���� ����� end � start.������� ��� � ������� ������ 28 ����.
//6. ������� ��������� �� ���� ���� � ����� n.������� �������, ��� ��������� �������� ��������� ����, � end - ��� ��������� ���� ���� n ����.

struct Date
{
	int _year = 2000;
	int _month = 1;
	int _day = 1;
};

static const int kMaxDay = 31;
static const int kMinDay = 1;
static const int kMaxMonth = 12;
static const int kMinMonth = 1;

int CountDayOfMonth(int month) {
	static const int kDayOfMonth[12]{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return kDayOfMonth[month - 1];
}


int CompareDate(Date &date1, Date &date2)
{
	int callback_value = 0;
	if (date1._year == date2._year) 
	{
		if (date1._month == date2._month) 
		{
			return callback_value = date1._day > date2._day ? 1 : -1;
		}
		else 
		{
			return callback_value = date1._month > date2._month ? 1 : -1;
		}
	}
	else
	{
		return callback_value = date1._year > date2._year ? 1 : -1;
	}

}

void GetYeasterdayDate(Date &date) 
{
	if (date._day == 1 && date._month == 1) {
		date._day = kMaxDay;
		date._month = kMaxMonth;
		date._year -= 1;
		return;
	}
	else {
		if (date._day == 1) {
			date._month -= 1;
			date._day = CountDayOfMonth(date._month);
			date._year = date._year;
		}
		else {
			date._day -= 1;
			date._month = date._month;
			date._year = date._year;
		}
	}
}

//����� ���������� 1 �����, ���� � 1 ����, ����� � 1 ��������, � ���� � 1 �������.

const char* GetSeason(Date &date)
{
	const char* season = "";

	if (date._month == 12 || date._month < 3) 
	{
		return	season = "Winter";
	}
	if (date._month == 3 || date._month < 6)
	{
		return season = "Spring";
	}
	if (date._month == 6 || date._month < 9)
	{
		return season = "Summer";
	}
	if (date._month == 9 || date._month < 12)
	{
		return season = "Autumn ";
	}
}

int GetCountDay(Date &date) 
{
	const int min_month = 1;
	const int min_year = 2000;
	const int min_day = 1;
	const int count_days_year = 365;

	const int difference_years = date._year - min_year;
	const int difference_days = date._day - min_day;
	int general_count_days_for_months = 0;

	for (int i = 1; i < date._month; i++)
	{
		general_count_days_for_months += CountDayOfMonth(i);
	}

	return difference_years * count_days_year + general_count_days_for_months + difference_days;
}