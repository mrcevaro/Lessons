#include <windows.h>
#include <iostream>
#include <conio.h>

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

	const int _width = 50;
	const int _height = 10;

	ConsoleHelper cs;
	Point _asterisk_position{ 3, 5 };

	void ClearAsterisk()
	{
		cs.Print(_asterisk_position.x, _asterisk_position.y, ' ');
	}

	void DrawAsterisk()
	{
		cs.Print(_asterisk_position.x, _asterisk_position.y, '*');
	}

	bool IsOutOfField(Point position) const
	{
		return (position.x >= _width || position.y >= _height || position.x <= 0 || position.y <= 0);
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

public:
	Game(int width, int height)
	: _width(width),
	  _height(height)
	{
		DrawBorders();
	}

	void MoveAsterisk(char symbol)
	{
		Point new_position = _asterisk_position;

		switch (symbol)
		{
		case 'w': new_position.y--; break;
		case 'a': new_position.x--; break;
		case 's': new_position.y++; break;
		case 'd': new_position.x++; break;
		}

		if (IsOutOfField(new_position))
		{
			return;
		}
		
		ClearAsterisk();
		_asterisk_position = new_position;
		DrawAsterisk();
	}
};



//1. Зафиксировать размеры карты и нарисовать на границах стену из #.
//2. Не позволять звездочке выходить за границу.
//3. Заполнить массив стен рандомными стенами в количестве n штук.
//4. Нарисовать стены из массива.
//5. Не позволять звездочке наступать на стены.




int main() 
{
	Game game(20,20);

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
		//char ch = _getch();

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

		game.MoveAsterisk(ch);
		
	}
	
	//std::cout << ch << std::endl;

	std::system("pause");
}