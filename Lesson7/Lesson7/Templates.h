#pragma once

#include <vector>
#include <algorithm>
#include <iostream>


//int Sqr(int a)
//{
//	return a * a;
//}
//
//double Sqr(double a)
//{
//	return a * a;
//}

template <class T>
T Sqr(T a)
{
	return a * a;
}


void Swap(int& a, int& b)
{
	const int temp = a;
	a = b;
	b = temp;
}

template <class T>
void Swap(T& a, T& b)
{
	const T temp = a;
	a = b;
	b = temp;
}


template <class T>
class Array
{
	int _size = 0;
	T* _array = nullptr;

	bool IsOutOfRange(int index) const
	{
		return index < 0 || index >= _size;
	}

	void CheckIndexInRange(int index) const
	{
		if (IsOutOfRange(index))
		{
			exit(1);
		}
	}

public:
	// КОнструктор по умолчанию
	Array()
	: Array(10)
	{}

	Array(int size)
		: _size(size)
	{
		_array = new T[_size];
	}

	//1.1.Конструктор, который принимает размер массива n и число v.Создает массив размера n, все элементы которого
	//заполнены значением v.
	Array(int size, T value)
		: _size(size)
	{
		_array = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = value;
		}
	}

	//1.2.Конструктор, который принимает размер массива n и два числа min, max.Создает массив размера n
	//который заполнен случайными  числами в джиапазоне [min, max].
	//Array(int size, T min, T max)
	//	: _size(size)
	//{
	//	_array = new T[_size];
	//
	//	for (int i = 0; i < _size; i++)
	//	{
	//		_array[i] = std::rand() % (max - min + 1) + min; // Сейчас генерируются числа из [min, min + max)
	//	}
	//}

	Array(const Array& rhs)
		: _size(rhs._size)
	{
		_array = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = rhs._array[i];
		}
	}

	~Array()
	{
		delete[] _array;
	}

	void operator=(const Array& rhs)
	{
		assert(_size == rhs._size);

		for (int i = 0; i < _size; i++)
		{
			_array[i] = rhs._array[i];
		}
	}

	T& operator[](int index) const
	{
		return _array[index];
	}

	int Size() const { return _size; }

	void SetValue(int index, T value)
	{
		CheckIndexInRange(index);
		_array[index] = value;
	}

	T GetValue(int index) const
	{
		CheckIndexInRange(index);
		return _array[index];
	}

	void Print() const
	{
		for (int i = 0; i < _size; i++)
		{
			std::cout << _array[i] << " ";
		}
		std::cout << std::endl;
	}

	//bool IsSorted() const
	//{
	//	for (int i = 0; i < _size - 1; i++)
	//	{
	//		if (_array[i] > _array[i + 1])
	//		{
	//			return false;
	//		}
	//	}
	//	return true;
	//}
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array)
{
	for (int i = 0; i < array.Size(); i++)
	{
		os << array[i] << ' ';
	}
	os << std::endl;
	return os;
}

struct MyStruct
{
	int a;
	std::string s;
};

std::ostream& operator<<(std::ostream& os, const MyStruct& s)
{
	os << s.a << ' ' << s.s;
	return os;
}




namespace Templates
{
	void f()
	{
		short  short_value = 15;

		int    sq1 = Sqr(3);
		double sq2 = Sqr(3.5);
		double sq3 = 3;

		Swap(sq2, sq3);

		std::string s1 = "ss";
		std::string s2 = "s1";
		Swap(s1, s2);
	}

	void g()
	{
		Array<int> array_of_ints(10,30);
		Array<int> array_of_ints1;
		Array<std::string> array_of_strings(10,"Andrey");

		Array<Array<int>> array_of_array_of_int(20);
		Array<Array<std::string>> array_of_array_of_string(20);
		Array<Array<Array<int>>> array_3x(2);

		array_3x[6][4][5] = 0;

		//array_of_ints.Print();
		//array_of_strings.Print();
		//array_of_array_of_int.Print();
		//array_of_array_of_string.Print();
		array_3x.Print();
	}


	void h()
	{
		MyStruct s{ 1, "Hello" };
		std::cout << s << std::endl;



		//int a = 2;
		//double d = 1;
		//std::cout << a << " " << d << "Hello" << std::endl;
		//
		//std::cout.operator<<(a).operator<<(" ").operator<<(d).operator<<("Hello").operator<<(std::endl);
		//
		//operator<<(operator<<(std::cout, s),(" "))
		//void.operator<<(" ")
		//std::cout.operator<<(" ")
		//std::cout << s << " ";
	}


	void tt()
	{
		std::vector<std::string> v;
		
		for (int i = 0; i < 20; i++)
		{
			v.push_back(std::to_string(std::rand() % 10));
			std::cout << v[i] << " " << v.size() << " " << v.capacity() << std::endl;
		}

		std::sort(v.begin(), v.end());

		for (int i = 0; i < 20; i++)
		{
			std::cout << v[i] << ' ';
		}

	}
}