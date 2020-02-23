#pragma once
#include "pch.h"
#include <vector>

class DummyDynamicArray
{
public:
	DummyDynamicArray(int size) {}
	DummyDynamicArray(int size, int value) {}
	DummyDynamicArray(int size, int min_value, int max_value) {}

	int Size() const { return 42; }

	void SetValue(int index, int value) { }
	int GetValue(int index) const { return 42; }

	void SetNewSize(int new_size) {}

	void PushBack(int value) {}
	void PopBack() {}
};


class VectorAdapter
{
	std::vector<int> _v;
public:
	VectorAdapter(int size):_v(size) { }
	VectorAdapter(int size, int value) :_v(size, value) {}

	size_t Size() const { return _v.size(); }

	void SetValue(int index, int value) { _v[index] = value; }
	int GetValue(int index) const { return _v[index]; }

	void SetNewSize(int new_size) { _v.resize(new_size, 0); }

	void PushBack(int value) { _v.push_back(value); }
	void PopBack() { _v.pop_back(); }
};

// Вместо DummyDynamicArray, подставь свой массив и он будет использоваться во всех тестах
using TestingDynamicArray = DummyDynamicArray;
//using TestingDynamicArray = VectorAdapter;

TEST(TestDynamicArray, TestEmpty)
{
	TestingDynamicArray arr(0);
	EXPECT_EQ(arr.Size(), 0);
}

TEST(TestDynamicArray, TestGetterSetter)
{
	TestingDynamicArray arr(5);
	EXPECT_EQ(arr.Size(), 5);
	arr.SetValue(0, 4);
	arr.SetValue(0, 5);
	arr.SetValue(1, 6);
	EXPECT_EQ(arr.GetValue(0), 5);
	EXPECT_EQ(arr.GetValue(1), 6);
	arr.SetValue(3, 4);
	EXPECT_EQ(arr.GetValue(3), 4);
}

TEST(TestDynamicArray, TestResize)
{
	TestingDynamicArray arr(10);
	EXPECT_EQ(arr.Size(), 10);
	arr.SetNewSize(11);
	EXPECT_EQ(arr.Size(), 11);
	EXPECT_EQ(arr.GetValue(10), 0);
	arr.SetNewSize(8);
	EXPECT_EQ(arr.Size(), 8);
	arr.SetNewSize(15);
	EXPECT_EQ(arr.Size(), 15);
	for (int i = 8; i < 15; i++)
	{
		EXPECT_EQ(arr.GetValue(i), 0);
	}
}

TEST(TestDynamicArray, TestPushBack)
{
	TestingDynamicArray arr(10,4);
	EXPECT_EQ(arr.GetValue(3), 4);
	arr.PushBack(5);
	EXPECT_EQ(arr.Size(), 11);
	EXPECT_EQ(arr.GetValue(10), 5);
	arr.PushBack(6);
	EXPECT_EQ(arr.Size(), 12);
	EXPECT_EQ(arr.GetValue(11), 6);
	arr.SetNewSize(20);
	arr.PushBack(1);
	arr.PushBack(1);
	arr.PushBack(1);
	arr.PushBack(1);
	EXPECT_EQ(arr.Size(), 24);
	EXPECT_EQ(arr.GetValue(19), 0);
	EXPECT_EQ(arr.GetValue(20), 1);
}

TEST(TestDynamicArray, TestPopBack)
{
	TestingDynamicArray arr(10, 4);
	arr.PopBack();
	arr.PopBack();
	arr.PopBack();
	EXPECT_EQ(arr.Size(), 7);
	arr.PopBack();

	arr.PushBack(3);
	arr.PopBack();
	arr.PushBack(3);
	arr.PopBack();
	
	EXPECT_EQ(arr.Size(), 6);
	arr.PopBack();
	arr.PopBack();
	arr.PopBack();
	arr.PopBack();
	arr.PopBack();
	arr.PopBack();
	EXPECT_EQ(arr.Size(), 0);
}


TEST(TestDynamicArray, TestStress)
{
	static const int kCountOfActions = 2000;
	static const int kMaxValue = 100;
	static const int kStartSize = 100;
	TestingDynamicArray arr(kStartSize);
	std::vector<int> vec(kStartSize);

	for (int i = 0; i < arr.Size(); i++)
	{
		arr.SetValue(i, 0);
		vec[i] = 0;
	}

	for (int k = 0; k < kCountOfActions; k++)
	{
		if (arr.Size() == 0)
		{
			const int value = std::rand() % kMaxValue;
			arr.PushBack(value);
			vec.push_back(value);
			continue;
		}
		
		const int action = std::rand() % 3;

		if (action == 0)
		{
			const int i = std::rand() % arr.Size();
			const int value = std::rand() % kMaxValue;
			arr.SetValue(i, value);
			vec[i] = value;
		}
		else if (action == 1)
		{
			const int value = std::rand() % kMaxValue;
			arr.PushBack(value);
			vec.push_back(value);
		}
		else if (action == 2)
		{
			arr.PopBack();
			vec.pop_back();
		}

		EXPECT_EQ(arr.Size(), vec.size());
		for (int i = 0; i < arr.Size(); i++)
		{
			EXPECT_EQ(arr.GetValue(i), vec[i]);
		}
	}
}