//Hello Unicode World ☺. ☻.
#pragma once

class Array
{
	int _size = 0;
	int _value = 0;
	int _min = 0;
	int _max = 0;
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
		: _size(size), _value(value)
	{
		_array = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = _value;
		}
	}

	//1.2.Конструктор, который принимает размер массива n и два числа min, max.Создает массив размера n
//который заполнен случайными  числами в джиапазоне[min, max].
////
//	int a = 0;
//
//	static const int kArraySize = 10;
//	int arr[kArraySize] = { 0 };
//
//	for (int i = 0; i < kArraySize; i++)
//	{
//		arr[i] = std::rand() % 10 + 10;
//	}

	Array(int size, int min, int max)
		: _size(size), _min(min), _max(max)
	{
		_array = new int[_size];

		for (int i = 0; i < _size; i++)
		{
			const int temp = _min + std::rand() % _max;
			if (temp < max)
			{
				_array[i] = temp;
			}
			else
			{
				_array[i] = temp % 10 + 10;
			}
		}
	}

	~Array()
	{
		delete[] _array;
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
		bool is_sorted = false;
		for (int i = 0; i < _size; i++) 
		{
			if (_array[i + 1] > _array[i])
			{
				is_sorted = true;
			}
		}
		return is_sorted;
	}
};


class DynamicArray
{
	int _size = 0;
	int _value = 0;
	int _min = 0;
	int _max = 0;
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
	DynamicArray(int size)
		: _size(size)
	{
		_array = new int[_size];
	}

	DynamicArray(int size, int value)
		: _size(size), _value(value)
	{
		_array = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = _value;
		}
	}

	DynamicArray(int size, int min, int max)
		: _size(size), _min(min), _max(max)
	{
		_array = new int[_size];

		for (int i = 0; i < _size; i++)
		{
			const int temp = _min + std::rand() % _max;
			if (temp < max)
			{
				_array[i] = temp;
			}
			else
			{
				_array[i] = temp % 10 + 10;
			}
		}
	}
	~DynamicArray() 
	{
		delete[] _array;
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

	void SetNewSize(int new_size)
	{
		
		int* new_array = new int[new_size];
		if (new_size > _size)
		{
			for (int i = 0; i < new_size - 1; i++)
			{
				if (i >= _size)
				{
					new_array[i] = 0;
				}
				else
				{
					new_array[i] = _array[i];
				}
			}
			_size = new_size;
			delete[] _array;
		}
		else if (new_size < _size)
		{
			for (int i = 0; i < new_size - 1 ; i++)
			{
					new_array[i] = _array[i];
			}
			_size = new_size;
			delete[] _array;
		}
		_array = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = new_array[i];
		}
		delete[] new_array;
	}


	void PushBack(int value) {}
	void PopBack() {}
};

