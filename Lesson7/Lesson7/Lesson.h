#pragma once
#include <iostream>

class Shape // Абстрактный класс ( класс у которого есть чистая функция)
{
public:
	virtual double Area() = 0; // Чистая функция.
	virtual ~Shape() = default;
};

class Circle : public Shape
{
	double _r;
public:
	Circle(double r) :_r(r) {}

	double Area()
	{
		return 3.14 * _r * _r;
	}
};

class Rectangle : public Shape
{
	int _a;
	int _b;
public:
	Rectangle(int a, int b) :_a(a), _b(b) {}

	double Area()
	{
		return _a * _b;
	}
};



void f()
{
	//A a;
	//B b;
	//C c;
	//
	//a.Print();
	//b.Print();
	//c.Print();
	//
	//std::cout << std::endl;
	//
	//A* pa = &a;
	//B* pb = &b;
	//
	////pa->Print();
	////pb->Print();
	//
	//A* paa = &b;
	//paa->Print();

	const int n = 10;
	Shape* arr[n];

	for (int i = 0; i < n; i++)
	{
		if (std::rand() % 2 == 0)
		{
			arr[i] = new Circle(std::rand() % 10 + 1000);
		}
		else
		{
			arr[i] = new Rectangle(std::rand() % 10 + 1 , std::rand() % 10 + 1);
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i]->Area() << std::endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	
}