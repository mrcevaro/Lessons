//Hello Unicode World ☺. ☻.
#pragma once

// Список, в котором все элементы отсортированы
class SortedList
{
	struct ListElem
	{
		int _value;
		ListElem* _next = nullptr;
	};

	ListElem* _first = nullptr;

public:
	void Print()
	{

	}

	void PushFront(int value) // Добавить элемент в начало списка
	{
		if (_first == nullptr)
		{
			// Список пуст
			_first = new ListElem{ value, nullptr };
			return;
		}
		ListElem* list_elem = new ListElem{ value, _first };
		_first = list_elem;
	}

	void PushBack(int value) // Добавить элемент в конец списка
	{
		// Добежать до конца
	}

	void AddValue(int value) // Добавить элемент чтоб список остался отсортированным
	{

	}

	void EraseValue(int value)
	{

	}

	int Size()
	{
		ListElem* p = _first;
		int size = 0;
		while (p != nullptr)
		{
			p = p->_next;
			size++;
		}
		return size;
	}

	~SortedList()
	{

	}
};


void f()
{
	SortedList list;
	list.AddValue(3);
	list.Print();
	list.AddValue(5);
	list.Print();
	list.AddValue(2);
	list.Print();
	list.AddValue(1);
	list.Print();


	list.EraseValue(5);
	list.EraseValue(6);
}