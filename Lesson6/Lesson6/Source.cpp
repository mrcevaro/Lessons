#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
struct Point
{
	int x = 0;
	int y = 0;
};

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
		SetPosition( x, y);
		std::cout.put(ch);
	}
};

class Game
{
	static const char kWallSymbol = '#';
	static const char kFoodSymbol = '@';

	static const int kSnakeSize = 10;

	static const int _width = 30;
	static const int _height = 20;
	int score = 0;
	
	int _wals[_width][_height] = {};
	int _foods2[_width][_height] = {};


	ConsoleHelper cs;
	Point _asterisk_positions[kSnakeSize];

	void ClearAsterisk()
	{
		for (int i = 0; i < kSnakeSize; i++)
		{
			cs.Print(_asterisk_positions[i].x, _asterisk_positions[i].y, ' ');
		}
	}

	void DrawAsterisks()
	{
		for (int i = 0; i < kSnakeSize; i++)
		{
			cs.Print(_asterisk_positions[i].x, _asterisk_positions[i].y, '*');
		}
		
	}

	bool IsOutOfField(Point position) const
	{
		return (position.x >= _width || position.y >= _height || position.x <= 0 || position.y <= 0);
	}

	bool IsWal(Point position)
	{
		return (_wals[position.x][position.y] == 1);
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

	void AddWals() 
	{
		for (int i = 0; i < _width; i++) 
		{
			for (int j = 0; j < _height; j++) 
			{
				_wals[i][j] = rand() % 100 > 95;
			}
		}
	}

	void DrawWals() const
	{
		for (int i = 0; i < _width; i++)
		{
			for (int j = 0; j < _height; j++)
			{
				if (_wals[i][j] == 1)
				{
					cs.Print(i, j, kWallSymbol);
				}
			}
		}
	}

	void GenerateSnake()
	{
		// 1, height / 2
		// 2, height / 2
		for (int i = 0; i < kSnakeSize; i++)
		{
			_asterisk_positions[i].x = 1 + i;
			_asterisk_positions[i].y = _height / 2;
		}
		DrawAsterisks();
	}

	void DrawBorderScore() 
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
		DrawTitleScore();
	}

	void DrawTitleScore() const
	{
		static const int size_name_score = 5;
		const char name_score[size_name_score] = { 'S','C','O','R','E'};
		Point p = { _width + 3, 2 };
		
		DrawTextChar(name_score, size_name_score, p);
	}

	void DrawTextChar(const char* text, int size, Point p) const
	{
		for (int i = 0; i < size; i++)
		{
			cs.Print(p.x + i, p.y, *(text+i));
		}
	}

	int UpdateScore()
	{
		
		return  score++;
	}

	void DrawScore()
	{
		static const int size_score = 3;

		char str[3] = {0};
		std::sprintf(str, "%d", UpdateScore());

		Point p = { _width + 3, 3 };
		DrawTextChar(str, size_score, p);
	}

	bool IsFood(Point position)
	{
		 if (_foods2[position.x][position.y] == 1) 
		{
			 _foods2[position.x][position.y] = 0;
			 return true;
		}
		 return false;
	}

	void GenerateFood()
	{
		for (int i = 0; i < _width; i++)
		{
			for (int j = 0; j < _height; j++)
			{
				_foods2[i][j] = rand() % 100 > 90;
			}
		}
	}

	

	void DrawFood()
	{
		for (int i = 0; i < _width; i++)
		{
			for (int j = 0; j < _height; j++)
			{
				if (_foods2[i][j] == 1)
				{
					cs.Print(i,j, kFoodSymbol);
				}
			}
		}
	}

public:
	Game()
	{
		GenerateSnake();
		GenerateFood();
		AddWals();
		DrawFood();
		DrawBorders();
		DrawWals();
		DrawBorderScore();
		DrawScore();
	}

	void MoveAsterisk(char symbol)
	{
		Point new_position = _asterisk_positions[0];



		switch (symbol)
		{
		case 'w': new_position.y--; break;
		case 'a': new_position.x--; break;
		case 's': new_position.y++; break;
		case 'd': new_position.x++; break;
		}


		if (IsOutOfField(new_position) || IsWal(new_position))
		{
			return;
		}

		if (IsFood(new_position))
		{
			DrawScore();
		}
		

		ClearAsterisk();
		_asterisk_positions[0] = new_position;
		for (int i = kSnakeSize; i > 0; i--)
		{
			_asterisk_positions[i] = _asterisk_positions[i - 1];
		}
		DrawAsterisks();
		
	}
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


int main() 
{
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
		char ch = _getch();
		game.MoveAsterisk(ch);
		//game.MoveAsterisk(RandomMove());
	}
	
	//std::cout << ch << std::endl;

	std::system("pause");
}