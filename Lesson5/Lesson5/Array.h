//Hello Unicode World ☺. ☻.
#pragma once

#include <cassert>

class Array
{
	int _size = 0;
	int* _array = nullptr;

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
	Array(int size)
	: _size(size)
	{
		_array = new int[_size];
	}

	//1.1.Конструктор, который принимает размер массива n и число v.Создает массив размера n, все элементы которого
	//заполнены значением v.
	Array(int size, int value)
	: _size(size)
	{
		_array = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = value;
		}
	}

	//1.2.Конструктор, который принимает размер массива n и два числа min, max.Создает массив размера n
	//который заполнен случайными  числами в джиапазоне [min, max].
	Array(int size, int min, int max)
	: _size(size)
	{
		_array = new int[_size];

		for (int i = 0; i < _size; i++)
		{
			_array[i] = std::rand() % (max - min + 1) + min; // Сейчас генерируются числа из [min, min + max)
		}
	}

	Array(const Array& rhs)
	: _size(rhs._size)
	{
		_array = new int[_size];
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

	int& operator[](int index)
	{
		return _array[index];
	}

	int Size() const { return _size; }

	void SetValue(int index, int value)
	{
		CheckIndexInRange(index);
		_array[index] = value;
	}

	int GetValue(int index) const
	{
		CheckIndexInRange(index);
		return _array[index];
	}

	bool IsSorted() const
	{
		for (int i = 0; i < _size - 1; i++) 
		{
			if (_array[i] > _array[i + 1])
			{
				return false;
			}
		}	
		return true;
	}
};







