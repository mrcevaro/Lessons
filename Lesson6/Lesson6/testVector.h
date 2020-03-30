#pragma once
#include <vector>
#include <iostream>
#include <cassert>

struct Point
{
	int x = 0;
	int y = 0;
};

void f(int a, double c)
{
	assert(a > 10);

}


void TestVector()
{
	std::vector<int> v;

	// Если выражение ложно, то программа упадет.
	// Можно читаь ассерт как "ожидаем"
	assert(v.size() == 0);

	v.push_back(11);
	assert(v.size() == 1);



	std::vector<int> v1(10); 
	assert(v1.size() == 10);

	std::vector<int> v2(10, 1); // Создаст массив размера 10 заполненный 1

	v2[2] = 4;
	v2[5] = v2[1] * 2;
	
	// Пробежаться по элементам вектора
	for (auto elem : v2)
	{
		std::cout << elem << std::endl;
	}
	// Эквиваалентны
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}



	std::vector<Point> snake;
	//snake.push_back({ 3, 3 });

	const int _height = 20;
	for (int i = 0; i < 10; i++)
	{
		snake.push_back({ 1 + i,_height / 2 });
	}

	Point new_position = { 3,3 };
	snake[0] = new_position;
	for (int i = snake.size() - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}
	
	for (Point  p : snake)
	{
		std::cout << p.x << p.y << std::endl;
	}

	
}