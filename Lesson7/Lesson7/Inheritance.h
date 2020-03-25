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
	
	Employee () {}

	Employee(std::string name, int age, Gender gender, int id, int salary)
		: Human(name, age, gender),
		  _id(id),
		  _salary(salary)
	{}
};

struct TaxiDriver : Employee
{
	int	   _taxi_id;

	TaxiDriver() {}

	TaxiDriver(std::string name, int age, Gender gender, int id, int salary, int taxi_id)
		: Employee(name, age, gender, id, salary),
		  _taxi_id(taxi_id)
	{}
};

struct Seller : Employee
{
	int	   _market_id;
	
	Seller() {}

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
	switch (std::rand() % 2)
	{
	case 0: return Gender::Male;   break;
	case 1: return Gender::Female; break;
	}
}

std::string PrintRandomGender(Gender gd)
{
	switch (gd)
	{
	case Gender::Male:  return "Male"; break;
	case Gender::Female:return "Female"; break;
	}
}

void F3()
{
	static const std::string kNames[5] = { "Andrey", "Egor", "Vasya", "Petya", "Igor" };

	//Student* students_dyn[10];
	//int count = 10;
	//for (int i = 0; i < 10; i++)
	//{
	//	students_dyn[i] = new Student(kNames[std::rand() % 5],
	//					  std::rand() % (45 - 17 + 1) + 17,
	//					  GetRandomGender(),
	//					  (double)(rand() % 100) / 10,
	//					  std::rand() % 100);
	//}
	//
	//// 4
	//delete students_dyn[4];
	//students_dyn[4] = students_dyn[count - 1];
	//count--;
	

	Student* students = new Student[10];
	for (int i = 0; i < 10; i++)
	{
		students[i]._name = kNames[std::rand() % std::size(kNames)];
		students[i]._age = std::rand() % (45 - 17 + 1) + 17;
		students[i]._gender = GetRandomGender();
		students[i]._mark = (double)(rand() % 100) / 10;
		students[i]._group = std::rand() % 100;
	}

	std::cout << " Students: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << students[i]._name << " ";
		std::cout << students[i]._age << " ";
		std::cout << PrintRandomGender(students[i]._gender) << " ";
		std::cout << students[i]._mark << " ";
		std::cout << students[i]._group << " ";
		std::cout << std::endl;
	}
	

	TaxiDriver* taxidrivers = new TaxiDriver[10];

	for (int i = 0; i < 10; i++)
	{
		taxidrivers[i]._name = kNames[std::rand() % 5];
		taxidrivers[i]._age = std::rand() % (45 - 17 + 1) + 17;
		taxidrivers[i]._gender = GetRandomGender();
		taxidrivers[i]._taxi_id = std::rand() % 100;
	}
	std::cout << " TaxiDrivers: " << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << taxidrivers[i]._name << " ";
		std::cout << taxidrivers[i]._age << " ";
		std::cout << PrintRandomGender(taxidrivers[i]._gender) << " ";
		std::cout << taxidrivers[i]._taxi_id << " ";
		std::cout << std::endl;
	}
	

	Seller* sellers = new Seller[10];
	for (int i = 0; i < 10; i++)
	{
		sellers[i]._name = kNames[std::rand() % 5];
		sellers[i]._age = std::rand() % (45 - 17 + 1) + 17;
		sellers[i]._gender = GetRandomGender();
		sellers[i]._salary = std::rand() % 100;
		sellers[i]._market_id = std::rand() % 100;
	}
	std::cout << "Sellers: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << sellers[i]._name << " ";
		std::cout << sellers[i]._age << " ";
		std::cout << PrintRandomGender(sellers[i]._gender) << " ";
		std::cout << sellers[i]._salary << " ";
		std::cout << sellers[i]._market_id << " ";
		std::cout << std::endl;
	}

	//TaxiDriver td;
	//Employee e;
	//
	//e = td;
	//
	//TaxiDriver* ptd;
	//Employee* pe;
	//
	//pe = ptd;
	
	Employee employeers[20];
	
	for (int i = 0; i < 20; i++) 
	{
		if (i < 10)
		{
			employeers[i] = taxidrivers[i]; // Копируешь
		}
		else
		{
			employeers[i] = sellers[i - 10];
		}
	}

	

	// taxidrivers[3]._age++;
	// employeers[3]

	for (int i = 0; i < 20; i++)
	{

	}

	delete[] students;
	delete[] taxidrivers;
	delete[] sellers;
}