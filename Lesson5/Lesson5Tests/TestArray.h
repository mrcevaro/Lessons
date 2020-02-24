//Hello Unicode World ☺. ☻.
#pragma once
#include "pch.h"

#include "../Lesson5/Array.h"

//К классу Array добавить следующий функционал :
//1.1.Конструктор, который принимает размер массива n и число v.Создает массив размера n, все элементы которого
//заполнены значением v.
//1.2.Конструктор, который принимает размер массива n и два числа min, max.Создает массив размера n
//который заполнен случайными  числами в джиапазоне[min, max].
//
//1.3.Добавить метод IsSorted, который возвращает true, если массив отсортирован по возрастанию, иначе false.
//
//


TEST(TestArray, TestEmpty)
{
	Array arr(0);
	EXPECT_EQ(arr.Size(),0);
}

TEST(TestArray, TestGetterSetter)
{
	Array arr(5);
	EXPECT_EQ(arr.Size(), 5);
	arr.SetValue(0, 4);
	arr.SetValue(0, 5);
	arr.SetValue(1, 6);
	EXPECT_EQ(arr.GetValue(0), 5);
	EXPECT_EQ(arr.GetValue(1), 6);
	arr.SetValue(3, 4);
	EXPECT_EQ(arr.GetValue(3), 4);
}

TEST(TestArray, TestStress)
{
	static const int kCountOfActions = 2000;
	static const int kMaxValue = 100;
	static const int kArraySize = 2000;
	Array arr(kArraySize);
	int test_arr[kArraySize] = { 0 };

	for (int i = 0; i < kArraySize; i++)
	{
		arr.SetValue(i, 0);
		test_arr[i] = 0;
	}

	for (int k = 0; k < kCountOfActions; k++)
	{
		const int i = std::rand() % kArraySize;
		if (std::rand() % 2 == 0)
		{
			const auto new_value = std::rand() % kMaxValue;
			test_arr[i] = new_value;
			arr.SetValue(i, new_value);
		}
		else
		{
			EXPECT_EQ(test_arr[i], arr.GetValue(i));
		}
	}
}

TEST(TestArray, TestConstructor1_1)
{
	//EXPECT_TRUE(false);
	// Расскоменть и убери предыдущую строчку как будет готово задание 1.1
	
	static const int kArraySize = 10;
	Array arr(kArraySize, 4);
	for (int i = 0; i < kArraySize; i++)
	{
		EXPECT_EQ(arr.GetValue(i), 4);
	}
	
}

TEST(TestArray, TestConstructor1_2)
{
	//EXPECT_TRUE(false);
	// Расскоменть и убери предыдущую строчку как будет готово задание 1.2
	
	static const int kArraySize = 1000;
	static const int kMinValue = 10;
	static const int kMaxValue = 30;

	Array arr(kArraySize, kMinValue, kMaxValue);
	for (int i = 0; i < kArraySize; i++)
	{
		const auto value = arr.GetValue(i);
		EXPECT_TRUE(value >= kMinValue && value <= kMaxValue);
	}
	
}

TEST(TestArray, TestIsSorted)
{
	//EXPECT_TRUE(false);
	// Расскоменть и убери предыдущую строчку как будет готово задание 1.3
	
	static const int kArraySize = 1000;
	static const int kMaxValue = 10000;

	static const int kTestsCount = 100;

	for (int k = 0; k < kTestsCount; k++)
	{
		std::vector<int> test_array(kArraySize);
		for (int i = 0; i < kArraySize; i++)
		{
			test_array[i] = std::rand() % kMaxValue;
		}
		std::sort(test_array.begin(), test_array.end());

		Array arr(kArraySize);
		for (int i = 0; i < kArraySize; i++)
		{
			arr.SetValue(i, test_array[i]);
		}

		EXPECT_TRUE(arr.IsSorted());
	}
}