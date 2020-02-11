﻿//Hello Unicode World ☺. ☻.
#pragma once

namespace Sort
{
	void BubbleSort(int* arr, int n)
	{
		// Сортировка пузырьком.
		// Необходимо n раз сделать следующее:
		// Пробежаться по массиву, сравнить все пары a[i] и a[i+1]. Т.к. мы хотим отсортировать по возрастанию
		// то необходимо чтоб каждый следующий элемент был больше. Соотвественно, если встретили такое, что
		// a[i] > a[i+1], то надо поменять их местами. Т.к. образом за один пробег массива, самый большой элемент "всплывает"
		// в конец массива.
		// Если мы проделаем такую процедуру n раз, то все элементы повсплывают и массив получится осортированным.
	}
}