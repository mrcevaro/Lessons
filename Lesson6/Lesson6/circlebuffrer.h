#pragma once
#include <vector>


//2. Самое частое действие, которое ты делаешь, это "движение змейки".
//Оно заключатеся в перекидывание хвоста на новое место перед головой.
//Например, путь это координаты змейки : 1 2 3 4 5. Голова 1, хвост 5.
//Змейка двигается влево, получаются такие координаты : 0 1 2 3 4.
//Если делать змейку через классический массив, то тут пришлось весь массив сдвинуть на 1 позицию направо, за O(n).
//А если массив кольцевой, то ты просто двигаешь указатель на голову за O(1)

//Написать класс, со следующими методами :
//Кольцевой массив имеет голову, т.е.текущий "первый" элемент.
//Например, вот массив 1 2 3 4 5, допустим изначально голова находится на 5. Двигаем голову дальше,
//головой становится 1. Далее будет двойка и так далее.Т.е.например, если голова это 2, то относительно головы массив будет выстроен так :
//3 4 5 1 2 - т.е.голова условно в конце.
//
//
//void PushBeforeTail(int v) - добавить элемент в хвост, т.е.перед головой.Т.е.например был массив 1 2 3 4 5, и голова у него на числе 3.
//Тогда вызывать PushBeforeTail(6), то получится массив 1 2 3 6 4 5. Голова останется на тройке.
//
//void PushAfterHead(int v) - добавить новый элемент после головы и сделать этот элемент головой.
//
//void MoveHeadForward() - передвинуть голову к следующему элементу
//
//void MoveHeadBackward() - передвинуть голову к предыдущем элементу.
//
//int Head() - вернуть головной элемент.
//
//int GetElem(int i) - вернуть i - ый после головы элемент.Наприер 1 2 3 4 5, голова 3.  GetElem(2) вернёт число 1.
//
//int Size() - вернуть количетсво элементов в массиве

struct Element 
{
	int value;
	Element* next;
};

class CircleBuffer 
{

	void AddFirstElement(int v)
	{
		_elems.push_back(v);
		_head = 0;
	}
public:
	void PushBeforeTail(int v) 
	{
		if (_elems.empty())
		{
			AddFirstElement(v);
			return;
		}



	}
	void  PushAfterHead(int v)
	{
		if (_elems.empty())
		{
			AddFirstElement(v);
			return;
		}

		// Вставляет в массив _elems элемент v перед позицией _head
		_elems.insert(_elems.begin() + _head + 1, v);
		_head++;

	}
	void MoveHeadForward()
	{
		_head++;
		if (_head == _elems.size())
		{
			_head = 0;
		}
	}

	void MoveHeadBackward()
	{
		_head--;
		if (_head < 0)
		{
			_head = _elems.size() - 1;
		}
	}
	int Head();
	int GetElem(int i);
	int Size()
	{
		return 0;
	}

	int Sum()
	{
		return 0;
	}

	void ChangeHeadValue(int v)
	{

	}


private:
	int _head = -1;
	std::vector<int> _elems;
};

#include <iostream>

void f1()
{
	CircleBuffer c;

	int window_size = 3;
	int sum = 0;
	for (int i = 0; i < 20; i++)
	{
		int num = std::rand() % 10;

		if (c.Size() < window_size)
		{
			c.PushAfterHead(num);
		}
		else
		{
			c.MoveHeadForward();
			c.ChangeHeadValue(num);
		}
		
		std::cout << num << ' ';

		if (c.Size() >= window_size)
		{
			std::cout << c.Sum();
		}

		
		std::cout << std::endl;
	}

	int a = 0;
}