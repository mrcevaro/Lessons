#include <windows.h>
#include <iostream>
#include <conio.h>

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
	void SetPosition(short x, short y)
	{
		SetConsoleCursorPosition(_console_handle, { x, y });
	}
	void Print(short x, short y, char ch)
	{
		SetPosition( x, y);
		std::cout.put(ch);
	}
};

class Game
{

	struct AsteriskPosition
	{
		int x = 0;
		int y = 0;
	};

	int _width = 50;
	int _height = 10;

	ConsoleHelper cs;
	AsteriskPosition _asterisk_position{ 3, 5 };

	

	void SetPositionAsterisk(AsteriskPosition position)
	{
		_asterisk_position = position;
	}

	AsteriskPosition GetPositionAsterisk()
	{
		return _asterisk_position;
	}

	void ClearAsterisk()
	{
		cs.Print(GetPositionAsterisk().x, GetPositionAsterisk().y, ' ');
	}
	
	

public:
	Game() {};
	~Game() {};

	
	void ControlPositionAsterisk()
	{
		char ch = _getch();
		
		ClearAsterisk();

		switch (ch)
		{
		case 'w': _asterisk_position.y--; break;
		case 'a': _asterisk_position.x--; break;
		case 's': _asterisk_position.y++; break;
		case 'd': _asterisk_position.x++; break;
		}
	}

	const void DrawingBorders()
	{
		ConsoleHelper cs;

		for (int i = 0; i < _width + 1; i++)
		{
			cs.Print(i, 0, '#');
			cs.Print(i, _height, '#');
		}

		for (int i = 0; i < _height; i++)
		{
			cs.Print(0, i, '#');
			cs.Print(_width, i, '#');
		}
	}


	const void setBorders(const int width, const int height)
	{
		_width = width;
		_height = height;
	}

	void DrawingAsterisk()
	{
		CheckСrossBorderExpansion();
		cs.Print(GetPositionAsterisk().x, GetPositionAsterisk().y, '*');
	}
	

	void CheckСrossBorderExpansion()
	{
		if (GetPositionAsterisk().x > _width - 1)
		{
			_asterisk_position.x = GetPositionAsterisk().x - 1;
		}

		if (GetPositionAsterisk().y >= _height || GetPositionAsterisk().y == 0) 
		{
			_asterisk_position.y = GetPositionAsterisk().y - 1;
		}

	}
	
};



//1. Зафиксировать размеры карты и нарисовать на границах стену из #.
//2. Не позволять звездочке выходить за границу.

//2.5 При вверх  - есть бага
//3. Заполнить массив стен рандомными стенами в количестве n штук.
//4. Нарисовать стены из массива.
//5. Не позволять звездочке наступать на стены.






int main() 
{
	Game game;

	ConsoleHelper cs;

	game.setBorders(50, 10);
	game.DrawingBorders();
	   	   
	int xx[10][10] = {0};

	xx[3][4] = 1;
	xx[3][5] = 1;
	xx[3][7] = 1;
	xx[3][9] = 1;

	/*for (int i = 0; i <  4; i++)
	{
		cs.Print(x, y, '#');
	}*/

	int x = 3;
	int y = 5;


	if(xx[x][y] == 1)
	{
	}

	cs.Print(x, y, '*');


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
		game.ControlPositionAsterisk();
		game.DrawingAsterisk();
		
	}
	
	//std::cout << ch << std::endl;

	std::system("pause");
}