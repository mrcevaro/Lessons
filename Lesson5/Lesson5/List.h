//Hello Unicode World ☺. ☻.
#pragma once
#include <iostream>

#include <vector>

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

		while (p->_next != nullptr)
		{
			p = p->_next;
		}

		p->_next = new ListElem{ value, nullptr };
	}

	bool IsExist(int value) 		// Вывести тру, если в списке есть элемнт со значнием value
	{
		ListElem* p = _first;
		while (p != nullptr)
		{
			if (p->_value == value) 
			{
				return true;
			}
			p = p->_next;
		}
		return false;
	}

	// Вывести следующий элемент за элементом value
	// 4 7 6 5 7 8. 6 => 5
	// А что, если value нету в списке? Ничего не выводить
	// А что, если следущего у value нет? Ничего не выводить 4 7 6 5 7 8. 7 =>
	// А что, если value несколько в списке? Вывести только для первого 4 7 6 5 7 8. 7 => 6

	void PrintNextIfExist(int value)
	{
		if (_first == nullptr)
		{
			return;
		}

		ListElem* p = _first;
		while (p->_next != nullptr)
		{
			if (p->_value == value)
			{
				std::cout << "PrintNextIfExist: " << p->_next->_value << " ";
				return;
			}
			p = p->_next;
		}


		/*while (p != nullptr)
		{
			if (p->_value == value)
			{
				if (p->_next != nullptr)
				{
					std::cout << "PrintNextIfExist: " << p->_next->_value << " ";
				}
				return;
			}
			p = p->_next;
		}*/

	}

	void PrintPrevIfExist(int value)
	{
		if (_first == nullptr)
		{
			return;
		}

		ListElem* p = _first;
		while (p->_next != nullptr)
		{
			if (p->_next->_value == value)
			{
				std::cout << "PrintPrevIfExist: " << p->_value << " ";
				return;
			}
			p = p->_next;
		}
	}

	bool IsSorted() // Вернуть тру, если в списке элементы отсортированы
	{
		if (_first == nullptr)
		{
			return false;
		}

		ListElem* p = _first;
		while (p->_next != nullptr)
		{
			if (p->_value > p->_next->_value)
			{
				return false;
			}
			p = p->_next;
		}
		return true;
	}

	void AddAfterIfExist(int value, int new_elem)
	{
		// Вставить в список новый элемент new_elem после value
		// {4 7 6 5 7 8}. 6 2 {4 7 6 2 5 7 8}

		ListElem* p = _first;
		//while (p != nullptr)
		//{
		//	if (p->_value == value)
		//	{
		//		ListElem* list_elem = new ListElem{ new_elem, p->_next };
		//		p->_next = list_elem;
		//		return;
		//	}
		//	p = p->_next;
		//}

		while (p != nullptr || p->_value != value)
		{
			p = p->_next;
		}

		if (p != nullptr)
		{
			ListElem* list_elem = new ListElem{ new_elem, p->_next };
			p->_next = list_elem;
		}
	}

	void AddBeforeIfExist(int value, int new_elem)
	{
		// Вставить в список новый элемент new_elem перед value
		// {4 7 6 5 7 8}. 6 2 {4 7 2 6 5 7 8}
		// Не решен случай, когда new_element ставиться первым

		if (_first == nullptr)
		{
			return;
		}

		ListElem* p = _first;
		while (p->_next != nullptr)
		{
			if (p->_next->_value == value)
			{
				ListElem* list_elem = new ListElem{ new_elem, p->_next };
				p->_next = list_elem;
				return;
			}
			p = p->_next;
		}
	}

	void SortList()
	{
		ListElem* p = _first;
		ListElem* q = p;
		int count = 0;
		while (p != nullptr)
		{
			
			while (q != nullptr)
			{
				if (q->_next != nullptr && q->_value > q->_next->_value)
				{
					AddBeforeIfExist(q->_value, q->_next->_value);
				}
				q = q->_next;
				delete q->_next;
		
			}
			p = p->_next;
		}
	}

	// Добавить элемент чтоб список остался отсортированным, с учетом того, что список уже отсортирован
	// 1,3,6,7,9   5 (если 5 меньше текущего элемента)
	// Отдельные случаи 0 и конец списка

	void AddValue(int value) 
	{
		if (_first == nullptr)
		{
			_first = new ListElem{ value, nullptr };
			return;
		}


		if (_first->_value > value)
		{
			ListElem* list_elem = new ListElem{ value, _first };
			_first = list_elem;
			return;
		}

		ListElem* p = _first;

		while (p->_next != nullptr)
		{
			if (p->_next->_value > value)
			{
				ListElem* list_elem = new ListElem{ value, p->_next };
				p->_next = list_elem;
				return;
			}
			p = p->_next;
		}

		if (p != nullptr)
		{
			ListElem* list_elem = new ListElem{ value, p->_next };
			p->_next = list_elem;
		}
	}



	void EraseValue(int value) // Смена одного указателя

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

	std::vector<int> GetSortedElems()
	{
		std::vector<int> result;

		ListElem* p = _first;
		while (p != nullptr)
		{
			result.push_back(p->_value);
			p = p->_next;
		}
		return result;
	}

	~SortedList() // После удаления указателя p пользоваться нельзя. Не понимаю в чем разница
	{
		delete _first;
		_first = nullptr;
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