#pragma once
#include <vector>
#include <iostream>
#include <cassert>

#include <thread>
#include <mutex>

std::mutex _mutex;

int a = 0;

void f()
{
	int c = 0;
	while (c++ < 1000)
	{
		_mutex.lock();
		std::cout << "Hello" << std::endl;
		_mutex.unlock();
	}
}

void h()
{
	int c = 0;
	while (c++ < 1000)
	{
		_mutex.lock();
		a++;
		std::cout << a << std::endl;
		_mutex.unlock();
	}
}


void g()
{
	int c = 0;
	while (c++ < 1000)
	{
		std::cout << "World" << std::endl;
	}
}


void Parralel1()
{
	std::thread thread1(f); // Начиная с этого момента - параллельно начинает работать функция f

	thread1.detach(); // Отцепить поток - он тебе больше не подвластен

	g();

}

void Parralel2()
{
	std::thread thread1(f); // Начиная с этого момента - параллельно начинает работать функция f

	g();

	thread1.join(); // Остановиться на этой срочке, до тех пор, пока не будет выполнен поток thread1 (функция f)
}

void Parralel3()
{
	std::thread thread1(f); // Начиная с этого момента - параллельно начинает работать функция f

	f();

	thread1.join(); // Остановиться на этой срочке, до тех пор, пока не будет выполнен поток thread1 (функция f)
}

void Parralel4()
{
	std::thread thread1(h); // Начиная с этого момента - параллельно начинает работать функция f

	h();

	thread1.join(); // Остановиться на этой срочке, до тех пор, пока не будет выполнен поток thread1 (функция f)
}

void Sum(const std::vector<int>& v, int& result, int start_position, int end_position)
{
	result = 0;
	for (int i = start_position; i < end_position; i++)
	{
		result = v[i] + result;
	}
}


// 1 2 3 4 5 6 7 

void Task()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(std::rand() % 10);
	}

	int sum1 = 0;

	std::thread thread1(Sum, v, std::ref(sum1), 0, v.size() / 2);

	int sum2 = 0;
	Sum(v, sum2, v.size() / 2, v.size());

	thread1.join();

	std::cout << sum1 + sum2  << std::endl;


}

bool is_inc = true;
bool is_active = true;

void KeyboardInput()
{
	// 27
	while (true)
	{
		char ch = _getch();
		if (ch == 27)
		{
			is_active = false;
			return;
		}
		is_inc = !is_inc;
	}
}

void Input()
{
	std::thread keyboard_thread(KeyboardInput);

	int i = 0;
	while (is_active)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(100)); // Подождать 100 миль

		std::cout << i << std::endl;

		if (is_inc)
		{
			i++;
		}
		else
		{
			i--;
		}
	}

	keyboard_thread.join();

}