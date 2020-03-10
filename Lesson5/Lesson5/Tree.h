#pragma once
#include <iostream>
class Tree
{
	struct TreeElem
	{
		int _value = 0;
		TreeElem* _left = nullptr;
		TreeElem* _right = nullptr;
	};

	TreeElem* _root = nullptr;


	// Print - вывводит поддерово указанного элемента
	void Print(TreeElem* elem)
	{
		if (elem->_left != nullptr)
		{
			Print(elem->_left);
		}
		
		std::cout << elem->_value << std::endl;
	
		if (elem->_right != nullptr)
		{
			Print(elem->_right);
		}
	}

public:
	Tree() {}
	~Tree() {}


	bool IsExist(int value)
	{
		if (_root == nullptr)
		{
			return false;
		}

		TreeElem* p = _root;

		while (p != nullptr)
		{
			if (value == p->_value)
			{
				return true;
			}
			else if (value > p->_value)
			{
				p = p->_right;
			}
			else
			{
				p = p->_left;
			}
		}
		return false;
	}

	void AddValue(int value) // Нужно вставить элемент в правильноем место, чтоб дерево осталось бинарным деревом поиска 
	{
		if (_root == nullptr)
		{
			_root = new TreeElem{ value, nullptr, nullptr };
			return;
		}

		TreeElem* p = _root;

		while (p != nullptr)
		{
			if (value >= p->_value) 
			{
				if (p->_right == nullptr) 
				{
					p->_right = new TreeElem{ value, nullptr, nullptr };
					return;
				}
				p = p->_right;
			}
			else
			{
				if (p->_left == nullptr)
				{
					p->_left = new TreeElem{ value, nullptr, nullptr };
					return;
				}
				p = p->_left;
			}
		}
	}

	void Print()
	{
		Print(_root);
	}

private:

};

