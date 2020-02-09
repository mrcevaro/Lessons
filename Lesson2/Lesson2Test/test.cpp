//Hello Unicode World ☺.

#include "pch.h"
#include <utility>

#include "TestHelper.h"

#include "../Lesson2/HomeWork1.h"
#include "../Lesson2/MaxElement.h"
#include "../Lesson2/SwapMaxMin.h"
#include "../Lesson2/Eraser.h"

TEST(ArrayTest, Task0_Homework)
{
	auto test = TestHelper::GetTestArrayCompare(Task0_ArrayIncrease);
	test.ExpectEq({ 0,1,2,3,4,5,6 }, { 0, 3, 4, 9, 8, 15, 12 });
	test.ExpectEq({ 1,1,1,1,1,1,1,1,1 }, { 2,3,2,3,2,3,2,3,2 });
	test.ExpectEq({ -1, 1, -2, 2, -3, 3, -4, 3}, { -2, 3, -4, 6, -6, 9, -8, 9 });
	test.ExpectEq(std::initializer_list<int>{ }, std::initializer_list<int>{ });
}

int  DummyReturnValue(int* arr, int n) { return 0; }
void DummyCheckArray(int* arr, int n) { }

TEST(ArrayTest, Task1_MaxElement)
{
	/* Задание 1.
	 * На вход функции задается массив и его размер.
	 * Функция должна вернуть максимальный элемент массива
	 */
	
	auto test = TestHelper::GetTestReturnValue(GetReturnMaxElement); // Вместо DummyReturnValue всунь имя своей функции. Как в тесте Task0_Homework
	test.ExpectEq({ 4, 7, 1, 9, 12, 5, 3 }, 12);
	test.ExpectEq({ -4, 8, 1000, 3 }, 1000 );
}

TEST(ArrayTest, Task2_SwapMaxMin)
{
	/* Задание 2.
	 * На вход функции задается массив и его размер.
	 * Функция должна поменять местами максимальный и минимальный элементы.
	 * Гарантируется что все элементы в массиве разные.
	 */

	auto test = TestHelper::GetTestArrayCompare(SwapElement);
	test.ExpectEq({ 4, 7, 1, 9, 12, 5, 3 }, { 4, 7, 12, 9, 1, 5, 3 });
	test.ExpectEq({ -4, 8, 1000, 3 }, { 1000, 8, -4, 3 });
}

TEST(ArrayTest, Task3_Shift1)
{
	/* Задание 3.
	 * На вход функции задается массив и его размер.
	 * Циклически сдвинуть все элементы массива направо на одну позицию.
	 */

	auto test = TestHelper::GetTestArrayCompare(DummyCheckArray);
	test.ExpectEq({ 0, 1, 2, 3, 4, 5, 6 }, { 6, 0, 1, 2, 3, 4, 5 });
	test.ExpectEq({ 3, 9, 5 }, { 5, 3, 9 });
}

TEST(ArrayTest, Task4_Eraser)
{
	/* Задание 4.
	 * На вход функции задается массив и его размер.
	 * Зафиксируем число A = (max + min) / 2, где max - максимальный элемент массива, min - минимальный
	 * Занулить все элементы массива, который строго больше A
	 */

	auto test = TestHelper::GetTestArrayCompare(Erase);
	test.ExpectEq({ 0, 1, 2, 3, 4, 5, 6 }, { 0, 1, 2, 3, 0, 0, 0 }); // max = 6, min = 0. A = 3
	test.ExpectEq({ 3, 9, 5, 8, 2, 1, 9 }, { 3, 0, 5, 0, 2, 1, 0 }); // max = 9, min = 1, A = 5
}

TEST(ArrayTest, Task5_Inversion)
{
	/* Задание 5.
	 * На вход функции задается массив и его размер.
	 * Отзеркалить массив.
	 */

	auto test = TestHelper::GetTestArrayCompare(DummyCheckArray);
	test.ExpectEq({ 0, 1, 2, 3, 4, 5, 6 }, { 6, 5, 4, 3, 2, 1, 0 });
	test.ExpectEq({ 0, 1, 2, 3, 4, 5 }, { 5, 4, 3, 2, 1 });
}