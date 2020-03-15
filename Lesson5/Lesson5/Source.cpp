#include <string>
#include <iostream>
#include "Array.h"
#include "List.h"
#include "DynamicArray.h"
#include "SortedArray.h"
#include "SortedContainerBench.h"
#include "Tree.h"

enum class Gender
{
	Male,
	Famale
};

class Student
{
	std::string _name;
	double _avg_mark = 0;
	int _marks_count = 0;
	const Gender _gender;

public:
	Student(std::string name, Gender _gender)
	: _name(name),
	  _gender(_gender)
	{}

	std::string Name() { return _name; }
	Gender Gender()    { return _gender; }
	double AvgMark()   { return _avg_mark; }

	void AddMark(int mark)
	{
		_marks_count++;
		_avg_mark = (_avg_mark + mark) / _marks_count;
	}

	void Print()
	{
		std::cout << _name << ' ' << _avg_mark << ' ' << std::endl;
	}
};
//Hello Unicode World ☺. ☻.


void Lesson5Function1()
{
	Student student1("Andrey", Gender::Male);
	Student student2("Vasya", Gender::Male);

	student1.AddMark(4);
	student1.AddMark(3);
	student1.AddMark(3);

	student2.AddMark(5);
	student2.AddMark(5);
	student2.AddMark(5);

	std::cout << student1.AvgMark() << ' ' << student2.AvgMark() << std::endl;


	{
		Array arr(10);
		// Array arr(10, 3);
		// Array arr(10, 0, 10);

		Array arr1 = arr;
		arr.Size();
		arr.SetValue(3, 190);
		arr1.SetValue(4, 100);

		std::cout << arr.GetValue(2) << std::endl;
	}

	int arr[5];

	int* p = arr;
	int* q = p;
	q++;

	int diff1 = q - p;
	int diff2 = p - q;

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	for (int* p = arr; p < arr + 5; p++)
	{
		std::cout << *p << std::endl;
	}
}


void Lesson5Function2()
{
	Array arr0(10, 0);
	Array arr1 = arr0; // Конструктор копирования


	arr1 = arr0; // Оператор присваивания

	arr1.SetValue(3, 12);

	arr1[3] = 12; // Оператор индексации

	arr1.operator[](3) = 12;

	std::cout << arr0[3] << std::endl;
	std::cout << arr1[3] << std::endl;


}

void Lesson5Function3()
{
	SortedArray sa(6);
	sa.AddValue(1);
	sa.AddValue(2);
	sa.AddValue(3);
	sa.AddValue(5);
	sa.AddValue(4);

	sa.Print();

	/*
	DynamicArray dm(1);
	dm.PushBack(10);

	dm.Print();*/
	//dm.AddValue(1);
	//dm.Print();
	//dm.AddValue(2);
	//dm.Print();
	//dm.AddValue(3);
	//dm.Print();
	//dm.AddValue(5);
	//dm.Print();
	//dm.AddValue(6);
	//dm.Print();
	//dm.AddValue(4);
	//dm.Print();
	/*SortedList list;

	    list.AddValue(4);
		list.Print();
		list.AddValue(5);
		list.Print();
		list.AddValue(3);
		list.Print();
		list.AddValue(2);
		list.Print();
		list.AddValue(1);
		list.Print();*/

	//list.Print(); // 1 2
	//list.PushFront(6);
	//list.Print(); // 1 2
	//list.PushFront(5);
	//list.Print(); // 1 2
	//list.PushFront(3);
	//list.Print(); // 1 2
	//list.PushFront(2);
	//list.Print(); // 1 2

	//list.AddValue(1);
	//list.Print();
	///*SortedList list;
	//list.Print();*/
	//list.PushBack(9);
	//list.Print(); 
	//list.PushBack(10);
	//list.Print();
	//list.PushBack(16);
	//list.Print();
	//list.PushBack(17);
	//list.Print();
	//list.PushBack(21);
	//list.Print();
	//list.PushBack(7);
	//list.Print();

	//list.AddAfterIfExist(22, 14);
	//list.Print();

	//list.AddBeforeIfExist(16, 15);
	//list.Print();

	//list.PrintNextIfExist(10);
	//list.PrintPrevIfExist(10);
	////list.IsExist(1);
	////std::cout << list.IsExist(1) << std::endl;
	//std::cout << std::endl;

	//std::cout << "ElementsIsSorted: " << list.IsSorted() << std::endl;
	//std::cout << std::endl;
/*
	list.Print();
	list.SortList();
	list.Print();
	*/



}

struct ListElem
{
	int value;
	ListElem* _next;
	ListElem* _prev;
}

class List
{
	ListElem* _first;


	void Erase(int value)
	{
		// 4 3 8 5 4 2 3
		                  p
		//  4 3 <-> 8 <-> 5 <-> 4 <-> 2
		//  4 3 <-> 8 <->       4 <-> 2

		for (auto p = _first; p != nullptr; p = p->_next)
		{
			if (p->value == value)
			{
				p->_prev->_next = p->_next;
			}
		}
	}
};



void f(int a)
{
	std::cout << a << std::endl;
	if (a > 0) 
	{
		f(a - 1);
	}
}

// Считает факториал числа
int Factorial(int value)
{
	if (value == 1)
	{
		return 1;
	}
	// value! = value * (value - 1)!
	return value * Factorial(value - 1);
}

int main()
{
	/*Tree tree;

	for (int i = 0; i < 100; i++)
	{
		tree.AddValue(std::rand() % 100);
	}

	tree.Print();*/


	// 10!  = 10*9*8*7*6*5*4*3*2*1
    // 10!  = 10*9!
	//int a = 1;
	//for (int i = 1; i < 11; i++)
	//{
	//	a *= i;
	//}

	//std::cout << Factorial(10) << std::endl;
/*
	for (int i = 0; i < 1000000; i++)
	{
		SortedList list;
		for (int j = 0; j < 10000; j++)
		{
			list.PushFront(j);
		}

	}
*/
	//TestContainersSquared();

	Lesson5Function3();


	//Date date;
	//date.year = 3;
	//
	//Date* p = &date;
	//p->year = 4;

	std::system("pause");
}