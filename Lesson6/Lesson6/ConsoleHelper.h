#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>

class ConsoleHelper
{
	HANDLE _console_handle;
	CONSOLE_CURSOR_INFO info;
	static const ConsoleColor kFieldColor = Black;

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

	void Print(short x, short y, char ch, ConsoleColor text_color)const
	{
		SetColorElement(kFieldColor, text_color);
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

	void SetColorElement(ConsoleColor color_console, ConsoleColor color_text) const
	{
		SetConsoleTextAttribute(_console_handle, (WORD)((color_console << 4 ) | color_text));
	}
};
