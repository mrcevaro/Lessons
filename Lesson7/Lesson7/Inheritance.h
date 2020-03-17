#pragma once
#include <iostream>
#include <string>

//Задания на наследование.
//
//Испльозуем структуру человека, студента, сотрудника, таксиста и продавца.
//
//1. Сделать для всех структур констукторы (c параметрами).
//
//2. Все задние 2 делаем в одной функции :
//2.1.Создать массив из 10 случайных студентов. (сами студенты должны храниться в динамической памяти)
//2.2.Создать массив из 10 случайных таксистов. (сами таксисты должны храниться в динамической памяти)
//2.3.Создать массив из 10 случайных продавцов. (сами продавцы должны храниться в динамической памяти)
//2.4.Создать массив из сотрудников(размера 20).В него записать  сгенерированных таксистов и продавцов.
//2.5.Создать массив из людей(размера 30).В него записать всех сгенерированных людей.
//2.6.Вывести имя самого старшего человека.
//2.7.Вывести имена и id сотрудников, у которых самая большая зарплата.
//2.8.Вывести средний возвраст студентов мальчиков.
//2.9.Вывести всех сотрудников, у которых зарплата больше чем самая большая зарплата у таксистов.
//2.10.Вывести самого старшего студента, таксиста и продавца.
//2.11. ...
//Не забыть очистить память.

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

	 Human() {}
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

	Student() {}
};

struct Employee : Human
{
	int	   _id;
	int	   _salary;
	
	Employee() {}
};

struct TaxiDriver : Employee
{
	int	   _taxi_id;

	TaxiDriver(){}
};

struct Seller : Employee
{
	int	   _market_id;
	Seller() {}
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

void F3()
{
	std::string kNames[5] = { "Andrey", "Egor", "Vasya", "Petya", "Igor" };
	Student* students = new Student[10];
	for (int i = 0; i < 10; i++)
	{

	}
}