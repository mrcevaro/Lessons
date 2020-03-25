#include <windows.h>
#include <iostream>
#include <conio.h>
#include <math.h>

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

	static const int kSnakeSize = 10;

	static const int _width = 30;
	static const int _height = 20;
	
	int _wals[_width][_height] = {};

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
				_wals[i][j] = rand() % 100 > 100;
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
	}

public:
	Game()
	{
		GenerateSnake();
		AddWals();
		DrawBorders();
		DrawWals();
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

		ClearAsterisk();
		_asterisk_positions[0] = new_position;
		DrawAsterisks();
	}
};



//1. Зафиксировать размеры карты и нарисовать на границах стену из #.
//2. Не позволять звездочке выходить за границу.
//2.5 При вверх  - есть бага
//3. Заполнить массив стен рандомными стенами в количестве n штук.
//4. Нарисовать стены из массива.
//5. Не позволять звездочке наступать на стены.



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