#include "Data.h"
#include <iostream>

int main()
{
	////  Yeastreday Date
	//Date date = {};
	//std::cin >> date._year;
	//std::cin >> date._month;
	//std::cin >> date._day;

	//GetYeasterdayDate(date);
	//std::cout << date._year << "-" << date._month << "-" << date._day;
	//std::cout << std::endl;

	//// Compare Date
	//Date date1 = {};
	//Date date2 = {};

	//std::cin >> date1._year;
	//std::cin >> date1._month;
	//std::cin >> date1._day;

	//std::cin >> date2._year;
	//std::cin >> date2._month;
	//std::cin >> date2._day;

	//std::cout << CompareDate(date1, date2);
	//
	//std::cout << std::endl;

	//Season Date

	std::cout << Dates::GetCountDay({ 2020,2,1 }) << std::endl;

	//Dates::Date date3 = {};
	//std::cin >> date3._year;
	//std::cin >> date3._month;
	//std::cin >> date3._day;

	//const auto season = Dates::GetSeason(date3);
	//if (season == Dates::Season::Summer)
	//{
	//}
	//std::cout << 

	/*Dates::Date date4 = {};
	std::cin >> date4._year;
	std::cin >> date4._month;
	std::cin >> date4._day;

	std::cout << Dates::GetCountDay(date4);

*/

	std::cout << std::endl;
	std::system("pause");
}