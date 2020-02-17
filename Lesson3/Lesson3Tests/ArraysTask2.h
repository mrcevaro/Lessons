//Hello Unicode World ☺. ☻.
#include "pch.h"

#include "../../Shared/TestHelper.h"

#include "../Lesson3/Sorts/Arrays.h"
#include "../Lesson3/Sorts/ArrarysTask2.h"

// Внимание. Задачи из этого файла делай в одном хидере

TEST(ArraysTask2, Task_2_1_Palindrome)
{
	// Задача 2.1. Палиндром
	// На вход функции подается массив и его размер
	// Вывести 0, если его значения симметричны относительно центра
	// В противном случае вывести 1

	auto test = TestHelper::GetTestReturnValue(TestHelper::DummyFunction);
	test.ExpectEq({ 1,2,3,4,5,4,3,2,1 }, 0);
	test.ExpectEq({ 4,3,8,1 }, 1);
}

TEST(ArraysTask2, Task_2_2_RemoveAndShrink)
{
	// Задача 2.2. Удаление и уплотнение
	// На вход функции подается массив и его размер
	// Удалить из массива все отрицательные значения и 0, а оставшиеся уплотнить (сдви-
	// нуть) с сохранением исходного порядка к началу массива. Хвост массива заполнить нулями

	auto test = TestHelper::GetTestArrayCompare(Task_2_2_RemoveAndShrink);
	test.ExpectEq({ 0, 1,2,-1,3,-1,-1,4,5,-1,6 }, {1,2,3,4,5,6,0,0,0,0,0});
	test.ExpectEq({ 1,-1,-2,3 }, { 1,3,0,0 });
}

TEST(ArraysTask2, Task_2_3_MaxSegment)
{
	// Задача 2.3. Длина отрезка
	// На вход функции подается массив и его размер
	// Назовем "отрезком" участок массива с одинаковыми элементами.
	// Например 1 2 2 2 3 3 4. Тут 4 отрезка: (1), (2 2 2), (3 3), (4).
	// Вернуть количество элементов в самом длинном отрезке

	auto test = TestHelper::GetTestReturnValue(TestHelper::DummyFunction);
	test.ExpectEq({ 1,2,2,2,3,3,4 }, 3); // Самый длинный 2 2 2, его длина 3
	test.ExpectEq({ 1,2,3,4,5 }, 1);
	test.ExpectEq({ 1,1,1,1,1,1}, 6);
}

TEST(ArraysTask2, Task_2_4_MoveMaxElement)
{
	// Задача 2.4. Вытащить максимум
	// На вход функции подается массив и его размер
	// Гарантируется что в массиве нет повторяющихся элементов.
	// Необходимо поместить максимум в конец массива, с сохранением порядка остальных элементов

	auto test = TestHelper::GetTestArrayCompare(TestHelper::DummyFunction);
	test.ExpectEq({ 3,7,9,3,5,4,7,8 }, { 3,7,3,5,4,7,8,9 }); // 9 подвинулась в конец, порядок остальных сохранен
	test.ExpectEq({ 1,9,2,3,4,5 }, { 1,2,3,4,5,9 });
	test.ExpectEq({ 1,1,3,1,1,1 }, {1,1,1,1,1,3});
}