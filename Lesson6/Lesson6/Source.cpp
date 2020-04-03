#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <thread>

struct Point
{
	int x = 0;
	int y = 0;
};

// задания
// 1. Убрать _wals, _foods. Сделать только массив fields
// 2. Убарть логику score в отдельный класс
// 3. Перевести змейку на вектор. Сделать чтоб голова была в начале массива


// 1. Разнести логику по файликам
// 2. В классе Score не рисовать стену, ит не принимать размеры поля. А принимать только точку куда писать.
// 3. Заюзать енам Snake в поле
// 4. Сделать кольцеовй массив
// 5. Добавить врагов 
// 6. Добавить к змейке и врагам скорость
// 7. Сделать так чтоб, если враг касается змейки, то он ее "режет"
// 8. Сделать врагам более умную логику движения. Использовать алгоритм поиска наикратчайшего пути от врага до змеи.




class ConsoleHelper
{
	HANDLE _console_handle;
	CONSOLE_CURSOR_INFO info;
public:

	ConsoleHelper() {
		_console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		info.bVisible = false;
		info.dwSize = 100;
		SetConsoleCursorInfo(_console_handle, &info);
	}
	void SetPosition(short x, short y) const
	{
		SetConsoleCursorPosition(_console_handle, { x, y });
	}
	void Print(short x, short y, char ch) const
	{
		SetPosition(x, y);
		std::cout.put(ch);
	}
	void Print(Point p, const std::string& text) const
	{
		for (int i = 0; i < text.size(); i++)
		{
			Print(p.x + i, p.y, text[i]);
		}
	}
};

enum class FieldObject
{
	None  = 0,
	Wall  = 1,
	Food  = 2,
	Snake = 3
};
static const char kWallSymbol = (char)219;
static const char kFoodSymbol = '@';

enum class KeyCode
{
	up,
	down,
	left,
	right
};

class Score
{
public:

	Score(const int width, const int height)
		: _width(width),
		_height(height)
	{
		DrawBorderScore();
		DrawTitleScore();
		DrawScore();
	}

	void UpdateScore()
	{
		score++;
	}

	void DrawScore()
	{
		Point p = { _width + 3, 3 };
		cs.Print(p, std::to_string(score));
	}

private:

	void DrawBorderScore() const
	{
		for (int i = _width + 1; i < _width + 10; i++)
		{
			cs.Print(i, 0, kWallSymbol);
			cs.Print(i, _height, kWallSymbol);
		}

		for (int j = 0; j < _height + 1; j++)
		{
			cs.Print(0, j, kWallSymbol);
			cs.Print(_width + 10, j, kWallSymbol);
		}
	}

	void DrawTitleScore() const
	{
		Point p = { _width + 3, 2 };
		cs.Print(p, "Score");
	}

	const int _width = 0;
	const int _height = 0;
	ConsoleHelper cs;

	int score = 0;
};

class Game
{
public:
	Game()
	{
		DrawBorders();
		GenerateElementsGame();
		DrawElementsGame();
		GenerateSnake();
		DrawSnake();
		_score.DrawScore();
	}

	Point GetNewPosition(Point position)
	{
		switch (_kd)
		{
		case KeyCode::down: position.y--; break;
		case KeyCode::left: position.x--; break;
		case KeyCode::up:   position.y++; break;
		case KeyCode::right: position.x++; break;
		}
		if (prev_position.x != position.x || prev_position.y != position.y)
		{
			prev_position = position;
			return position;
		}
		else
		{
			return prev_position;
		}
	}


	void GetKey()
	{
		while (true)
		{
			char ch = _getch();
			switch (ch)
			{
			case 'w': _kd = KeyCode::down; break;
			case 'a': _kd = KeyCode::left; break;
			case 's': _kd = KeyCode::up; break;
			case 'd': _kd = KeyCode::right; break;
			}
		}
	}


	void MoveAsterisk()//void MoveAsterisk(char symbol)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
			Point new_position = GetNewPosition(_snake[0]);
			// new_position = _snake[0];

		/*	switch (symbol)
			{
			case 'w': new_position.y--; break;
			case 'a': new_position.x--; break;
			case 's': new_position.y++; break;
			case 'd': new_position.x++; break;
			}
	*/

			if (IsOutOfField(new_position) || IsWal(new_position))
			{
				return;
			}

			if (IsFood(new_position))
			{
				RemoveFood(new_position);
				_score.UpdateScore();
				_score.DrawScore();
				_snake.push_back(_snake[_snake.size() - 1]);
			}

			DeleteSnake();
			_snake[0] = new_position;
			for (int i = _snake.size() - 1; i > 0; i--)
			{
				_snake[i] = _snake[i - 1];
			}
			DrawSnake();
	}

private:
	Game(const Game&) = delete;

	void DeleteSnake()
	{
		for (int i = 0; i < _snake.size(); i++)
		{
			cs.Print(_snake[i].x, _snake[i].y, ' ');
		}
	}

	void DrawSnake()
	{
		for (int i = 0; i < _snake.size(); i++)
		{
			cs.Print(_snake[i].x, _snake[i].y, '*');
		}

	}

	bool IsOutOfField(Point position) const
	{
		return (position.x >= _width || position.y >= _height || position.x <= 0 || position.y <= 0);
	}

	bool IsWal(Point position)
	{
		return (_field[position.x][position.y] == FieldObject::Wall);
	}

	void DrawBorders() const
	{
		for (int i = 0; i < _width + 1; i++)
		{
			cs.Print(i, 0, kWallSymbol);
			cs.Print(i, _height, kWallSymbol);
		}

		for (int j = 0; j < _height; j++)
		{
			cs.Print(0, j, kWallSymbol);
			cs.Print(_width, j, kWallSymbol);
		}
	}

	void DrawElementsGame() const
	{
		for (int i = 2; i < _width; i++)
		{
			for (int j = 2; j < _height; j++)
			{
				switch (_field[i][j])
				{
				case FieldObject::None:
					cs.Print(i, j, ' ');
					break;
				case FieldObject::Wall:
					cs.Print(i, j, kWallSymbol);
					break;
				case FieldObject::Food:
					cs.Print(i, j, kFoodSymbol);
					break;
				}
			}
		}
	}

	void GenerateSnake()
	{
		for (int i = 0; i < 3 ; i++)
		{
			_snake.push_back({ 1 + i,_height / 2 });
		}
	}

	bool IsFood(Point position)
	{
		if (_field[position.x][position.y] == FieldObject::Food)
		{
			return true;
		}
		return false;
	}

	void RemoveFood(Point position)
	{
		_field[position.x][position.y] = FieldObject::None;
	}

	void GenerateElementsGame()
	{
		int count = 0;
		for (int i = 2; i < _width; i++)
		{
			for (int j = 2; j < _height; j++)
			{
				//static const auto kWallChance  = 30;
				//static const auto kFoodChance  = 10;
				//static const auto kEmptyChance = 60;
				//
				//const auto rand_number = rand() % 100;
				//if (rand_number < kWallChance)
				//{
				//	_field[i][j] = FieldObject::Wall;
				//}
				//else if (rand_number - kWallChance < kFoodChance)
				//{
				//	_field[i][j] = FieldObject::Food
				//}
				//else
				//{
				//	_field[i][j] = FieldObject::None;
				//}


				_field[i][j] = rand() % 100 > 90 ? FieldObject::Wall : FieldObject::None;

				if (_field[i][j] == FieldObject::None)
				{
					if (count == 30)
					{
						_field[i][j] = FieldObject::Food;
						count = 0;
					}
					else
					{
						count++;
					}
				}
			}
		}
	}

	

	static const int _width = 30;
	static const int _height = 20;

	std::vector<Point> _snake;

	FieldObject _field[_width][_height] = {};

	ConsoleHelper cs;
	Score _score{ _width, _height };

	KeyCode _kd = KeyCode::down;
	Point prev_position;
};




//1. Зафиксировать размеры карты и нарисовать на границах стену из #.
//2. Не позволять звездочке выходить за границу.
//2.5 При вверх  - есть бага
//3. Заполнить массив стен рандомными стенами в количестве n штук.
//4. Нарисовать стены из массива.
//5. Не позволять звездочке наступать на стены.
//6/ Сделать правильное движение змейки. Сейчас двигается только голова, тело стоит на месте.
// Змейка движется так: голова встает на новую позицию, а все следующие элементы двигаются вперед
// {2,0} {3,0} {3,1} {3,2} {4,2}
// {1,0} {2,0} {3,0} {3,1} {3,2}

// 7 добавить на поле в случаеное место еду (1 клетка), кога голова ее касается, то написать Hello
// Еда генерируется в новом месте


char RandomMove()
{
	char ch;
	switch (std::rand() % 4)
	{
	case 0: ch = 'w'; break;
	case 1: ch = 'a'; break;
	case 2: ch = 's'; break;
	case 3: ch = 'd'; break;
	default:
		break;
	}
	return ch;
}

#include "Parallel.h"

int main()
{
	//Input();
	//return 1;

	Game game;

	ConsoleHelper cs;

	//int xx[10][10] = {0};
	//
	//xx[3][4] = 1;
	//xx[3][5] = 1;
	//xx[3][7] = 1;
	//xx[3][9] = 1;
	//
	///*for (int i = 0; i <  4; i++)
	//{
	//	cs.Print(x, y, '#');
	//}*/
	//
	//int x = 3;
	//int y = 5;
	//
	//
	//if(xx[x][y] == 1)
	//{
	//}
	//
	//cs.Print(x, y, '*');


	/*while (true)
	{
		char ch = std::rand() % 255;
		if (ch == '\a')
		{
			continue;
		}

		cs.Print(std::rand() % 50, std::rand() % 50, ch);
	}*/


	std::thread keyboard_thread(&Game::GetKey, &game);
	while (true)
	{
		/*char ch = _getch();
		cs.Print(x, y, ' ');

		switch (ch)
		{
		case 'w': y--; break;
		case 'a': x--; break;
		case 's': y++; break;
		case 'd': x++; break;
		}

		game.
		cs.Print(x, y, '*');*/
		//char ch = _getch();
		
		
		
		//game.MoveAsterisk(RandomMove());
		game.MoveAsterisk();
	}
	keyboard_thread.join();
	//std::cout << ch << std::endl;

	std::system("pause");
}