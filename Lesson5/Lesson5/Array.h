#pragma once


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
};