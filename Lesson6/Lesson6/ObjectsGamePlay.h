#pragma once


static const char kWallSymbol = (char)219;
static const char kFoodSymbol = (char)22;
static const char kSnakeSymbol = (char)22;
static const char kEnemieSymbol = (char)253;

struct Point
{
	int x = 0;
	int y = 0;
};

enum class FieldObject
{
	None = 0,
	Wall = 1,
	Food = 2,
	Snake = 3
};

enum class KeyCode
{
	up,
	down,
	left,
	right
};


enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};


