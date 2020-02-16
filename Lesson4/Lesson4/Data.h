#pragma once
//Создать структуру дата(Date), в которой 3 интовских поля.Год, месяц, день.Допустим минимальная дата это 2000 - 01 - 01. Т.е.меньше дата быть не может.
//1. Функция принимает на вход дату, а возвращает дату вчерашнего дня.
//2. Функция принимает на вход 2 даты.Возвращает 0, если они равны, -1 если первая дата меньше второй. 1, если первая дата больше второй.
//3. Функция принимает на вход дату, вернуть время года этой даты.
//4. Принимает на вход дату, вернуть количество дней прошедших с 2000 - 01 - 01.
//Создать структуру «временной отрезок»(TimeSegment).Структура содержит 2 даты._start_date, _end_date.Старт должен быть всегда меньше чем энд.
//4. Сделать конструктор, который принимает две даты, но сетает в поле старт меньшую из них, а в энд большую.
//5. Функция принимает на вход отрезок, а возвращает  количество дней между end и start.Считаем что в феврале всегда 28 дней.
//6. Функция принимает на вход дату и число n.Вернуть отрезок, где стартовой является указанная дата, а end - это указанная дата плюс n дней.

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

//весна начинается 1 марта, лето — 1 июня, осень — 1 сентября, а зима — 1 декабря.

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