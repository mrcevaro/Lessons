#pragma once

class DynamicArray
{
	int _size = 0; // ������ ������� �� ������� ������
	int _capacity = 0; // ������� ������ ��������� �� ����� ����
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

	// �������� ������� ���� ������ ������� ���������������, � ������ ����, ��� ������ ��� ������������
// 1,3,6,7,9   5 (���� 5 ������ �������� ��������)
// ��������� ������ 0 � ����� ������

	void AddValue(int value)
	{
	
		if (_size == 0)
		{
			PushBack(value);
		}

		for (int i = 0; i < _size; i++)
		{

			if (value > _array[i])
			{
				int temp = _array[i];
				PushBack(value);
				_array[i] = temp;
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

	// ������� ������� setNewCapacity
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



	//2.4.����� PushBack(int value).��������� value � ����� ������� � ����������� ������ ������� �� 1.
//�������� ��� ������ 1 2 3 4. ������� PushBack(13).������ ���� 1 2 3 4 13.
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

	//2.5.����� PopBack().���������� �� ������� ��������� �������.��������� ������ �� 1.
	void PopBack() 
	{
		_size -= 1;
	}

	void Print()
	{
		for (int i = 0; i < _size; i++) // ���� �������� � 1 ���� ��������� ������ 0 �������?
		{
			std::cout << _array[i] << std::endl;
		}
	}
};