//Hello Unicode World ☺. ☻.
#pragma once

#include "pch.h"

#include "../../Shared/TestHelper.h"
#include "../Lesson3/Sorts/SelectionSort.h"
#include "../Lesson3/Sorts/BubbleSort.h"



static const std::vector<std::initializer_list<int>> kInputArrays =
{
	{3,5,8,3,0,2,1,4},
	{2,1,1,1,1,1,1,1},
	{-5,3,8,5,-3,-1,-5,8,4},
	{3,9,8,1,0,0,4},
	{1,2,1,2,1,2,1,2},
	{0},
	{},
	{1,2,3,4,5,6}
};

template <class TSortFunction>
TestHelper::SortTestHelper<TSortFunction>  GetSortTestHelper(TSortFunction sort_function)
{
	return TestHelper::SortTestHelper<TSortFunction>{sort_function, kInputArrays};
}

TEST(SortTests, SelectionSortTest) {
	auto test = GetSortTestHelper(Sort::SelectionSort);
	test.Test();
}

TEST(SortTests, BubbleSortTest) {
	auto test = GetSortTestHelper(Sort::BubbleSort);
	test.Test();
}