#pragma once
#include <vector>


//2. ����� ������ ��������, ������� �� �������, ��� "�������� ������".
//��� ����������� � ������������� ������ �� ����� ����� ����� �������.
//��������, ���� ��� ���������� ������ : 1 2 3 4 5. ������ 1, ����� 5.
//������ ��������� �����, ���������� ����� ���������� : 0 1 2 3 4.
//���� ������ ������ ����� ������������ ������, �� ��� �������� ���� ������ �������� �� 1 ������� �������, �� O(n).
//� ���� ������ ���������, �� �� ������ �������� ��������� �� ������ �� O(1)

//�������� �����, �� ���������� �������� :
//��������� ������ ����� ������, �.�.������� "������" �������.
//��������, ��� ������ 1 2 3 4 5, �������� ���������� ������ ��������� �� 5. ������� ������ ������,
//������� ���������� 1. ����� ����� ������ � ��� �����.�.�.��������, ���� ������ ��� 2, �� ������������ ������ ������ ����� �������� ��� :
//3 4 5 1 2 - �.�.������ ������� � �����.
//
//
//void PushBeforeTail(int v) - �������� ������� � �����, �.�.����� �������.�.�.�������� ��� ������ 1 2 3 4 5, � ������ � ���� �� ����� 3.
//����� �������� PushBeforeTail(6), �� ��������� ������ 1 2 3 6 4 5. ������ ��������� �� ������.
//
//void PushAfterHead(int v) - �������� ����� ������� ����� ������ � ������� ���� ������� �������.
//
//void MoveHeadForward() - ����������� ������ � ���������� ��������
//
//void MoveHeadBackward() - ����������� ������ � ���������� ��������.
//
//int Head() - ������� �������� �������.
//
//int GetElem(int i) - ������� i - �� ����� ������ �������.������� 1 2 3 4 5, ������ 3.  GetElem(2) ����� ����� 1.
//
//int Size() - ������� ���������� ��������� � �������

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

		// ��������� � ������ _elems ������� v ����� �������� _head
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