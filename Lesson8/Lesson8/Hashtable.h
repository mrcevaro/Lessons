#pragma once
#include <unordered_set>
#include <iostream>
namespace Hashtable
{

	int HashString1(std::string s)
	{
		return s.size();
	}

	int HashString2(std::string s)
	{
		return s[0];
	}

	int HashInt1(int num)
	{
		return num / 100;
	}

	int HashInt2(int num)
	{
		return num % 10;
	}

	// Множество строк, реализованных через хештаблицу
	// Каждый элеент хранится в одном экземпляре
	class HashSetForString
	{
		static const int kHashMaxValue = 20;

		// Массив из векторов размера kHashMaxValue
		std::vector<std::string> _hashtable[kHashMaxValue];


		int Hash(std::string s)
		{
			return s.size() % 20;
		}

	public:
		void Add(std::string s) {}
		void Remove(std::string s) {}
		bool IsExist(std::string s) {}
	};

	void f()
	{
		std::unordered_set<std::string> s;

		s.emplace("An"); // 6
		s.emplace("An"); // 6
		s.emplace("Wo"); // 5
		s.emplace("He"); // 5 
		s.emplace("Wo"); // 5
		s.emplace("ui");   // 3

		if (s.find("Andrey") != s.end())
		{
			std::cout << "Andrey is exist" << std::endl;
		}
		else
		{
			std::cout << "Andrey doesn't exist" << std::endl;
		}
	}
}