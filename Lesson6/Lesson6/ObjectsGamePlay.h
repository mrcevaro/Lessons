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

