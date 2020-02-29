#pragma once

class DynamicArray
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
	DynamicArray(int size)
		: _size(size)
	{
		_array = new int[_size];
	}

	DynamicArray(int size, int value)
		: _size(size)
	{
		_array = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = value;
		}
	}

	DynamicArray(int size, int min, int max)
		: _size(size)
	{
		_array = new int[_size];

		for (int i = 0; i < _size; i++)
		{
			for (int i = 0; i < _size; i++)
			{
				_array[i] = std::rand() % (max - min + 1) + min;
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

	//2.4.Метод PushBack(int value).Добавляет value в конец массива и увеличивает размер массива на 1.
//Например был массив 1 2 3 4. Вызвали PushBack(13).Массив стал 1 2 3 4 13.
	void PushBack(int value) 
	{
		SetNewSize(_size + 1);
		_array[_size - 1] = value;
	}

	//2.5.Метод PopBack().Выкидывает из массива последний элемент.Уменьшает размер на 1.
	void PopBack() 
	{
		_size -= 1;
	}
};