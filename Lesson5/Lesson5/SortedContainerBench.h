//Hello Unicode World ☺. ☻.
#pragma once
#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>

#include "../Lesson5/List.h"

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

void TestContainers(int elems_count)
{
	static const int max_value = 1000000;

	std::vector<int> elems;
	elems.reserve(elems_count);

	for (int i = 0; i < elems_count; i++)
	{
		elems.push_back(std::rand() % max_value);
	}

	auto sorted_elems = elems;
	std::sort(sorted_elems.begin(), sorted_elems.end());

	//const auto array_time = Test<Array>(elems, sorted_elems);
	const auto list_time = Test<SortedList>(elems, sorted_elems);

	std::cout << "Results for size " << elems_count << ":\n";
	std::cout << "	List time: " << list_time << "s" << std::endl;
}

void TestContainersSquared()
{
	static const int kStartPow = 5;
	static const int kMaxPow = 25;
	for (int i = pow(2, kStartPow); i < pow(2, kMaxPow); i *= 2)
	{
		TestContainers(i);
	}
}

