#pragma once

#include "ConsoleHelper.h"

static const char kWallSymbol = (char)219;
static const char kFoodSymbol = (char)22;
static const char kSnakeSymbol = (char)22;
static const char kEnemieSymbol = (char)253;


enum class FieldObject
{
	None = 0,
	Wall = 1,
	Food = 2,
	Snake = 3,
	Enemie = 4
};

static const char kDrawSymbols[] = 
{
	' ',
	(char)219,
	(char)22,
	(char)22,
	(char)253
};

//static const ConsoleColor kDrawColors[] =
//{
//	
//};

enum class KeyCode
{
	up,
	down,
	left,
	right
};

