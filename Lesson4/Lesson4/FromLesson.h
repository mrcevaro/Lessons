#pragma once

struct ListNode
{
	int _value = 0;
	ListNode* _next = nullptr;
};

struct Date
{
	int _year = 0;
	int _month = 0;
	int _day = 0;
};

struct Student
{
	int _id;
	const Date _birth_date;
	double _mark;

	Student(Date date)
		: _id(0),
		_birth_date(date),
		_mark(5)
	{}

	Student(Date date, double mark)
		: _id(0),
		_birth_date(date),
		_mark(mark)
	{}
};

void TaskFromLesson4()
{
	int a = 3;
	double b;

	int arr[3];

	Date date;
	Date date1{ 2020, 2, 13 };

	date._year = 2019;

	date._month = date1._month + 1;

	Date dates[10];
	for (int i = 0; i < 10; i++)
	{
		dates[i]._year = 2020;
	}

	Student student{ Date{2000, 3, 14} };

	//student._birth_date._year = 1999;

	Student* student2 = new Student{ Date{1980,12,1} };

	Student* student3 = new Student(Date{ 1800, 2, 12 }, 3);

	Student* student4 = new Student{ Date{ 1800, 2, 12 }, 3 };

	Student student5{ Date{ 1800, 2, 12 }, 3 };

	Date date2{ 2020, 2, 13 };

	delete student2;
	delete student3;
	delete student4;

	ListNode listnode;
	listnode._next = new ListNode;
	listnode._next->_next = new ListNode;
	listnode._next->_next->_next = &listnode;
}