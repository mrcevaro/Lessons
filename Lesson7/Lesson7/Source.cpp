
//#include "Lesson.h"
#include "Inheritance.h"
//#include "Templates.h"

#include <vector>

double g(int a)
{
	if (a == 0)
	{
		throw 1; // 1 - имеет тип int
	}

	return 4 / a;
}

void f(int a)
{
	// ...
	const auto res = g(a);
	

	// ...
}

template <int kSomeConst>
void f()
{
	std::cout << kSomeConst;
}

template <class T>
void f1(T t)
{
	// ...........
	if constexpr (std::is_same_v<T, double>)
	{
		std::cout << "double: " << t << std::endl;
	}
	else
	{
		std::cout << t << std::endl;
	}
	// ...........
}

//template <>
//void f1<double>(double t)
//{
//	// ...........
//	std::cout << "Double: " << t << std::endl;
//	// ...........
//}



void main()
{
	f1(3);
	f1("Hello");
	f1(3.4);
	std::system("pause");

	return;

	f<4>();
	f<3>();
	f<2>();

	int a;
	std::cin >> a;
	
	std::vector<int> v;
	//v[3] = 3;
	try
	{
		v.at(3) = 3;
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}


	try
	{
		f(a);
	}
	catch (int ex)
	{
	std::cout << "Divide by zero" << std::endl;
	}

	//Templates::tt();
	//f();
	F3();
	std::system("pause");
	
}
