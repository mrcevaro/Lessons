//Hello Unicode World ☺. ☻.
#pragma once
#include <vector>
#include <chrono>
#include <set>
#include <iostream>
#include <algorithm>

#include "../Lesson5/List.h"


class StlVectorAdapter
{
	std::vector<int> _v;

public:

	void AddValue(int value)
	{
		const auto it = std::lower_bound(_v.begin(), _v.end(), value);

		_v.insert(it, value);
	}

	std::vector<int> GetSortedElems()
	{
		return _v;
	}
};

class StlSetAdapter
{
	std::multiset<int> _s;

public:

	void AddValue(int value)
	{
		_s.emplace(value);
	}

	std::vector<int> GetSortedElems()
	{
		std::vector<int> res;
		res.reserve(_s.size());
		std::copy(_s.begin(), _s.end(), std::back_inserter(res));
		return res;
	}
};


template <class TContainer>
double Test(const std::vector<int>& elems, const std::vector<int>& sorted_elems)
{
	auto start_time = std::chrono::system_clock::now();

	TContainer container;

	for (auto elem : elems)
	{
		container.AddValue(elem);
	}

	const auto sorted_container_elems = container.GetSortedElems();

	auto end_time = std::chrono::system_clock::now();

	assert(sorted_container_elems.size() == sorted_elems.size());

	for (int i = 0; i < sorted_container_elems.size(); i++)
	{
		assert(sorted_container_elems[i] == sorted_elems[i]);
	}

	return  std::chrono::duration<double>(end_time - start_time).count();
}

template <class NumbersGenerator>
void TestContainers(int elems_count, NumbersGenerator numbers_generator)
{
	static const int max_value = 1000000;

	std::vector<int> elems;
	elems.reserve(elems_count);

	for (int i = 0; i < elems_count; i++)
	{
		elems.push_back(numbers_generator());
	}

	auto sorted_elems = elems;
	std::sort(sorted_elems.begin(), sorted_elems.end());

	const auto array_time       = Test<DynamicArray>(elems, sorted_elems);
	const auto list_time        = Test<SortedList>(elems, sorted_elems);
	const auto stl_vector_time  = Test<StlVectorAdapter>(elems, sorted_elems);
	const auto stl_set_time     = Test<StlSetAdapter>(elems, sorted_elems);

	std::cout << std::endl;
	std::cout << "Results for size " << elems_count << ":\n";
	std::cout << "       array: " << array_time << "s" << std::endl;
	std::cout << "        List: " << list_time << "s" << std::endl;
	std::cout << "  stl_vector: " << stl_vector_time << "s" << std::endl;
	std::cout << "     stl_set: " << stl_set_time << "s" << std::endl;
}

template <class NumbersGenerator>
void TestContainersSquared(NumbersGenerator numbers_generator)
{
	static const int kStartPow = 10;
	static const int kMaxPow = 16;
	for (int i = pow(2, kStartPow); i < pow(2, kMaxPow); i *= 2)
	{
		TestContainers(i, numbers_generator);
	}
}

