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

//1. Зафиксировать размеры карты и нарисовать на границах стену из #.
//2. Не позволять звездочке выходить за границу.
//3. Заполнить массив стен рандомными стенами в количестве n штук.
//4. Нарисовать стены из массива.
//5. Не позволять звездочке наступать на стены.


int main() 
{
	ConsoleHelper cs;

	int xx[10][10] = {0};

	xx[3][4] = 1;
	xx[3][5] = 1;
	xx[3][7] = 1;
	xx[3][9] = 1;

	for (int i = 0; i <  4; i++)
	{
		cs.Print(x, y, '#');
	}

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
		char ch = _getch();
		cs.Print(x, y, ' ');

		switch (ch)
		{
		case 'w': y--; break;
		case 'a': x--; break;
		case 's': y++; break;
		case 'd': x++; break;
		}
		
		cs.Print(x, y, '*');
	}
	
	//std::cout << ch << std::endl;

	std::system("pause");
}