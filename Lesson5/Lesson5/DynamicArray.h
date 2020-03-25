#pragma once

class DynamicArray
{
	int _size = 0; // Размер массива на текущий момент
	int _capacity = 0; // Сколько памяти выделлено на самом деле
	int* _array = nullptr;

	static const int capacity_value_incriment = 5;

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
	DynamicArray(){}

	DynamicArray(int size)
		: _size(size)
	{
		_capacity = _size + capacity_value_incriment;
		_array = new int[_capacity];
	}

	DynamicArray(int size, int value)
		: DynamicArray (size)
	{

		for (int i = 0; i < _size; i++)
		{
			_array[i] = value;
		}
	}

	DynamicArray(int size, int min, int max)
		: DynamicArray(size)
	{
		for (int i = 0; i < _size; i++)
		{
			for (int i = 0; i < _size; i++)
			{
				_array[i] = std::rand() % (max - min + 1) + min;
			}
		}
	}

	// Добавить элемент чтоб список остался отсортированным, с учетом того, что список уже отсортирован
// 1,3,6,7,9   5 (если 5 меньше текущего элемента)
// Отдельные случаи 0 и конец списка

	void AddValue(int value)
	{
	
		if (_size == 0)
		{
			PushBack(value);
			return;
		}

		for (int i = 0; i < _size; i++)
		{
			if (value < _array[i])
			{
				// _4_
				// 1 2 3 5 7 8 9
				// i = 3

				PushBack(_array[_size - 1]);
				// 1 2 3 5 7 8 9 9
				// _size == 8

				// [6, 4]
				for (int j = _size - 2; j > i; j--)
				{
					_array[j] = _array[j - 1];
				}

				// j = 6. _array[6] = _array[5];
				// 1 2 3 5 7 8 8 9

				// j = 5. _array[5] = _array[4];
				// 1 2 3 5 7 7 8 9

				// j = 4. _array[4]= _array[3];
				// 1 2 3 5 5 7 8 9

				_array[i] = value;
				// 1 2 3 4 5 7 8 9
				return;
			}
		}
		
		PushBack(value);
		// 1 2 3 4 _10_
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
		if (new_size <= _size)
		{
			_size = new_size;
			return;
		}

		int* new_array = new int[new_size];
		for (int i = 0; i < _size; i++)
		{
			new_array[i] = _array[i];
		}
		for (int i = _size; i < new_size; i++)
		{
			new_array[i] = 0;
		}
		_size = new_size;
		delete[] _array;
		_array = new_array;
	}

	// Сделать функцию setNewCapacity
	void SetNewCapacity()
	{
		const int new_capacity = capacity_value_incriment + _capacity;
		
		int* new_array = new int[new_capacity];
		for (int i = 0; i < _capacity; i++)
		{
			new_array[i] = _array[i];
		}
		for (int i = _capacity; i < new_capacity; i++)
		{
			new_array[i] = 0;
		}
		_capacity = new_capacity;
		delete[] _array;
		_array = new_array;
	}



	//2.4.Метод PushBack(int value).Добавляет value в конец массива и увеличивает размер массива на 1.
//Например был массив 1 2 3 4. Вызвали PushBack(13).Массив стал 1 2 3 4 13.
	void PushBack(int value) 
	{
		if (_size < _capacity) 
		{
			_size += 1;
		}
		else
		{
			SetNewCapacity();
		}
		_array[_size - 1] = value;
	}

	//2.5.Метод PopBack().Выкидывает из массива последний элемент.Уменьшает размер на 1.
	void PopBack() 
	{
		_size -= 1;
	}

	void Print()
	{
		for (int i = 0; i < _size; i++) // Либо начинать с 1 либо объявлять массив 0 размера?
		{
			std::cout << _array[i] << std::endl;
		}
	}
};