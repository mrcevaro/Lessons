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

	 Human(std::string name, int age, Gender gender) 
		: _name(name),
		  _age(age),
		  _gender(gender)
	 {}
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

	Student(){}

	Student(std::string name, int age, Gender gender, double mark, int group)
		:  Human(name, age, gender),
		  _mark(mark),
		  _group(group)
	{}
    
};

struct Employee : Human
{
	int	   _id;
	int	   _salary;
	
	Employee(std::string name, int age, Gender gender, int id, int salary)
		: Human(name, age, gender),
		  _id(id),
		  _salary(salary)
	{}
};

struct TaxiDriver : Employee
{
	int	   _taxi_id;

	TaxiDriver(std::string name, int age, Gender gender, int id, int salary, int taxi_id)
		: Employee(name, age, gender, id, salary),
		  _taxi_id(taxi_id)
	{}
};

struct Seller : Employee
{
	int	   _market_id;
	Seller(std::string name, int age, Gender gender, int id, int salary, int _market_id)
		: Employee(name, age, gender, id, salary),
		_market_id(_market_id)
	{}
};

//void F1()
//{
//	Student student;
//	student._name = "Vasa";
//	student._age = 36;
//	student._gender = Male;
//	student._mark = 5.5;
//	student._group = 3;
//
//	Employee employee;
//	employee._name = "Pety";
//	employee._age = 32;
//	employee._gender = Female;
//	employee._id = 5;
//	employee._salary = 3000;
//
//	std::cout << GetOlder(employee, student)._name << std::endl;
//}

//void F2()
//{
//	Student* student = new Student;
//	student->_name = "Vasa";
//	student->_age = 36;
//	student->_gender = Male;
//	student->_mark = 5.5;
//	student->_group = 3;
//
//	Employee* employee = new Employee;
//	employee->_name = "Pety";
//	employee->_age = 32;
//	employee->_gender = Female;
//	employee->_id = 5;
//	employee->_salary = 3000;
//
//	Human* p = student;
//
//	Human* humans[2];
//	humans[0] = student;
//	humans[1] = employee;
//
//	std::cout << GetOlder(*employee, *student)._name << std::endl;
//	delete employee;
//	delete humans[0];
//}


Gender GetRandomGender()
{
	
	switch (std::rand() % (1 - 0 + 1) + 0)
	{
	case 0:
		return Gender::Male;
		break;
	case 1:
		return Gender::Female;
		break;
	}
}

void F3()
{
	std::string kNames[5] = { "Andrey", "Egor", "Vasya", "Petya", "Igor" };
	
	Student* students = new Student[10];
	for (int i = 0; i < 10; i++)
	{
		students[i]._name = kNames[0];//kNames[std::rand() % (5 - 0 + 1) + 0];
		students[i]._age = std::rand() % (45 - 17 + 1) + 17;
		students[i]._gender = Gender::Female;//GetRandomGender();
		students[i]._mark = 2.2;// double(std::rand() % (10 - 0 + 0));
		students[i]._group = std::rand() % 10 + 1;
	}

	
	for (int i = 0; i < 10; i++)
	{
		std::cout << students[i]._name  << " ";
		std::cout << students[i]._age   << " ";
		std::cout << students[i]._gender<< " ";
		std::cout << students[i]._mark  << " ";
		std::cout << students[i]._group << " ";
		std::cout << std::endl;
	}
		delete [] students;
}