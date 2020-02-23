//Hello Unicode World ☺. ☻.
#include "pch.h"

#include "../../Shared/TestHelper.h"

#include "../Lesson3/Sorts/Arrays.h"

// Внимание. Задачи из этого файла делай в одном хидере

TEST(MaxMinInArray, Task_1_1_FirstMax)
{
	// Задача 1.1. Первый максимум
	// Функция получает на вход массив и его размер.
	// Вернуть индекс первого максимального элемента. 

	auto test = TestHelper::GetTestReturnValue(Task_1_1_GetFirstMax);
	test.ExpectEq({ 2,7,4,8,5,6,8,3,1,8,8,4 }, 3); // Максимальный элемент тут 8. Их в массиве 4 штуки, но первая идет по индексом 3.
	test.ExpectEq({ 1,2,3,3,2,1 }, 2);
	test.ExpectEq({ 1,1,1,2,1,1 }, 3);
	test.ExpectEq({ 1,1,1,1,2,1 }, 4);
}

TEST(MaxMinInArray, Task_1_2_LastMax)
{
	// Задача 1.2. Последний максимум
	// Функция получает на вход массив и его размер.
	// Вернуть индекс последнего максимального элемента. 

	auto test = TestHelper::GetTestReturnValue(GetLastMax);
	test.ExpectEq({ 2,7,4,8,5,6,8,3,1,8,8,4 }, 10); // Последжняя 8ка под индексом 10.
	test.ExpectEq({ 1,2,3,3,2,1 }, 3);
}

TEST(MaxMinInArray, Task_1_3_ThirdMax)
{
	// Задача 1.3. Третий максимум
	// Функция получает на вход массив и его размер.
	// Вернуть индекс третьего максимального элемента.
	// Если третьего максимума нету - вернуть -1

	auto test = TestHelper::GetTestReturnValue(GetThirdMax);
	test.ExpectEq({ 2,7,4,8,5,6,8,3,1,8,8,4 }, 9); // Третья 8ка под индексом 10.
	test.ExpectEq({ 1,2,3,3,2,1 }, -1);
	test.ExpectEq({ -2,-3,-1,-1,-1 }, 4);
	test.ExpectEq({ 1,1,1,2,2,2 }, 5);
}

TEST(MaxMinInArray, Task_1_4_PenultimateMax)
{
	// Задача 1.4. Предпоследний максимум
	// Функция получает на вход массив и его размер.
	// Вернуть индекс предпоследнего максимального элемента.
	// Если такого нету - вернуть -1

	auto test = TestHelper::GetTestReturnValue(GetPenultimateMax);
	test.ExpectEq({ 2,9,9,4,8,5,6,9,3,1,9,8,4 }, 7); // Максимум тут 9. Предпоследняя девятка под номером 7
	test.ExpectEq({ 1,2,3,4,3,2,1 }, -1);
}


TEST(MaxMinInArray, Task_1_5_CountOfMax)
{
	// Задача 1.5. Количество максимумов
	// Функция получает на вход массив и его размер.
	// Вернуть количество максимальных элементов.

	auto test = TestHelper::GetTestReturnValue(GetCountOfMax);
	test.ExpectEq({ 2,9,9,4,8,5,6,9,3,1,9,8,4 }, 4); // Максимум тут 9 их 4 штуки
	test.ExpectEq({ 1,2,3,4,3,2,1 }, 1);
}

TEST(MaxMinInArray, Task_1_6_AlmostMax)
{
	// Задача 1.6. Почти максимум
	// Функция получает на вход массив и его размер.
	// Вернуть число которое было бы максимальным, если бы не было максимального.
	// Иными словами, предмаксимум

	auto test = TestHelper::GetTestReturnValue(TestHelper::DummyFunction);
	test.ExpectEq({ 2,9,9,4,7,5,6,9,3,1,9,7,4 }, 7); // Максимум тут 9, следом за ним идет число 7
	test.ExpectEq({ 1,2,3,4,3,2,1 }, 3);
}