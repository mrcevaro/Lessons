//Hello Unicode World ☺. ☻.
#pragma once
#include <iostream>

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
		// std::cout << _first->_value << ' ';
		// std::cout << _first->_next->_value << ' ';
		// std::cout << _first->_next->_next->_value << ' ';


		// std::cout << _first->_value << ' ';
		// ListElem* p = _first->_next;
		// ListElem* q = p->_next;
		// std::cout << p->_value << ' ';
		// std::cout << q->_value << ' ';
		
		// ListElem* p = _first;
		// std::cout << p->_value << ' ';
		// p = p->_next;
		// std::cout << p->_value << ' ';
		// p = p->_next;
		// std::cout << p->_value << ' ';
		// p = p->_next;
		// std::cout << p->_value << ' ';

		//int n = 5;
		//ListElem* p = _first;
		//
		//for (int i = 0; i < n; i++)
		//{
		//	std::cout << p->_value << ' ';
		//	p = p->_next;
		//}


		//ListElem* p = _first;	   // [1]
		//ListElem* p = p->_next;  // [2]
		//ListElem* p = p->_next;  // [3]
		//ListElem* p = p->_next;  // nullptr
		//ListElem* p = p->_next;  // segfault
		//
		//int n = 5;
		//ListElem* p = _first;
		//// 1 2 3
		//// 1 2
		//for (int i = 0; i < n; i++)
		//{
		//	if (p == nullptr)
		//	{
		//		return;
		//	}			
		//	std::cout << p->_value << ' ';
		//	p = p->_next;
		//
		//}
		ListElem* p = _first;
		while (p != nullptr)
		{
			std::cout << p->_value << ' ';
			p = p->_next;
		}

		std::cout << std::endl;
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
		if (_first == nullptr)
		{
			// Список пуст
			_first = new ListElem{ value, nullptr };
			return;
		}

		// Вывести на экран последний элемент списка
		// После этого добавить после него новый кубик со значением value
		ListElem* p = _first;

		while (p != nullptr)
		{
			if (p->_next == nullptr)
			{
				ListElem* list_elem = new ListElem{ value, nullptr };
				p->_next = list_elem;                //p = list_elem; // Вопрос почему не выводиться 9 если по сути перезаписывается 3?
				return;
			}
			p = p->_next;
		}
	}

	bool IsExist(int value)
	{
		// Вывести тру, если в списке есть элемнт со значнием value
	}

	void PrintNextIfExist(int value)
	{
		// Вывести следующий элемент за элементом value
		// 4 7 6 5 7 8. 6 => 5
		// А что, если value нету в списке? Ничего не выводить
		// А что, если следущего у value нет? Ничего не выводить 4 7 6 5 7 8. 7 =>
		// А что, если value несколько в списке? Вывести только для первого 4 7 6 5 7 8. 7 => 6
	}

	void PrintPrevIfExist(int value)
	{

	}

	bool IsSorted()
	{
		// Вернуть тру, если в списке элементы отсортированы
	}

	void AddAfterIfExist(int value, int new_elem)
	{
		// Вставить в список новый элемент new_elem после value
		// {4 7 6 5 7 8}. 6 2 {4 7 6 2 5 7 8}
	}

	void AddBeforeIfExist(int value, int new_elem)
	{
		// Вставить в список новый элемент new_elem перед value
		// {4 7 6 5 7 8}. 6 2 {4 7 2 6 5 7 8}
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
	
	/*list.AddValue(3);
	list.Print();
	list.AddValue(5);
	list.Print();
	list.AddValue(2);
	list.Print();
	list.AddValue(1);
	list.Print();


	list.EraseValue(5);
	list.EraseValue(6);*/
}