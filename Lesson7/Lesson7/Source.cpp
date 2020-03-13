#include <iostream>
#include <string>
enum Gender
{
	Male,
	Female
};

struct Human
{
	std::string _name;
	int			_age;
	Gender		_gender;
};

Human GetOlder(Human h1, Human h2)
{
	if (h1._age > h2._age)
	{
		return h1;
	}
	else if (h1._age < h2._age)
	{
		return h2;
	}
	else
	{
		return h1;
	}
}

struct Student : Human
{
	double _mark;
	int	   _group;
};

struct Employee : Human
{
	int	   _id;
	int	   _salary;
};

struct TaxiDriver : Employee
{
	int	   _taxi_id;
};

struct Seller : Employee
{
	int	   _market_id;
};

void F1()
{
	Student student;
	student._name = "Vasa";
	student._age = 36;
	student._gender = Male;
	student._mark = 5.5;
	student._group = 3;

	Employee employee;
	employee._name = "Pety";
	employee._age = 32;
	employee._gender = Female;
	employee._id = 5;
	employee._salary = 3000;

	std::cout << GetOlder(employee, student)._name << std::endl;
}

void F2()
{
	Student* student = new Student;
	student->_name = "Vasa";
	student->_age = 36;
	student->_gender = Male;
	student->_mark = 5.5;
	student->_group = 3;

	Employee* employee = new Employee;
	employee->_name = "Pety";
	employee->_age = 32;
	employee->_gender = Female;
	employee->_id = 5;
	employee->_salary = 3000;

	Human* p = student;

	Human* humans[2];
	humans[0] = student;
	humans[1] = employee;

	std::cout << GetOlder(*employee, *student)._name << std::endl;
	delete employee;
	delete humans[0];
}

#include "Lesson.h"

void main()
{
	f();
	std::system("pause");
}
