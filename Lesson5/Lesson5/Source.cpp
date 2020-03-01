#include <string>
#include <iostream>
#include "Array.h"
#include "List.h"

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

	int a;

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
	SortedList list;
	list.Print(); // 1 2
	list.PushFront(3);
	list.Print(); // 1 2
	list.PushFront(2);
	list.Print(); // 1 2
	list.PushFront(1);
	list.Print(); // 1 2

	/*SortedList list;
	list.Print();*/
	list.PushBack(9);
	list.Print(); 
	list.PushBack(10);
	list.Print();
	list.PushBack(16);
	list.Print();
	list.PushBack(17);
	list.Print();
	list.PushBack(21);
	list.Print();
	list.PushBack(18);
	list.Print();

	list.PrintNextIfExist(21);
	list.PrintPrevIfExist(16);
	//list.IsExist(1);
	//std::cout << list.IsExist(1) << std::endl;
}

int main()
{
	Lesson5Function3();

	//Date date;
	//date.year = 3;
	//
	//Date* p = &date;
	//p->year = 4;

	std::system("pause");
}