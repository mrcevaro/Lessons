#pragma once
#include <mmsystem.h>
//template <int kWidth, int kHeight>
class GamePlay
{
public:
	GamePlay()
	{
		//PrintChar();
		DrawBorders();
		GenerateElementsGame();
		DrawElementsGame();
		GenerateSnake();
		DrawSnake();
		GenerateEnemie();
		DrawEnemie();
		_score.DrawScore();
	}

	void PrintChar()
	{
		for (int i = 0; i < 256; i++)
		{
			cs.Print(0,i, (char)i);
		}
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

	void PlaySoundWithBeep() 
	{
		while (true)
		{
			if (_playBeep)
			{
				Beep(294, 1000 / 8);
				Beep(440, 1000 / 4);

				_playBeep = !_playBeep;
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
	GamePlay(const GamePlay&) = delete;

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
			cs.Print(_snake[i].x, _snake[i].y, kSnakeSymbol, White);
		}
	}

	void DrawEnemie()
	{
		for (int i = 0; i < 3; i++)
		{
			cs.Print(_enemie[i].x, _enemie[i].y, kEnemieSymbol, Yellow);
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
					cs.Print(i, j, ' ', Black);
					break;
				case FieldObject::Wall:
					cs.Print(i, j, kWallSymbol, DarkGray);
					break;
				case FieldObject::Food:
					cs.Print(i, j, kFoodSymbol, LightRed);
					break;
				}
			}
		}
	}

	void GenerateSnake()
	{
		for (int i = 0; i < 3; i++)
		{
			_snake.push_back({ 1 + i,_height / 2 });
		}
	}

	void GenerateEnemie()
	{
		for (int i = 0; i < 3; i++)
		{
			_enemie[i] = {i + 6,_height / 2 };
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
		_playBeep = true;
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

	


	/*static const int _width = kWidth;
	static const int _height = kHeight;*/

	static const int _width = 50;
	static const int _height = 20;

	std::vector<Point> _snake;
	Point			   _enemie[3];
	FieldObject _field[_width][_height] = {};

	ConsoleHelper cs;
	Score _score{ _width, _height };

	KeyCode _kd = KeyCode::down;
	Point prev_position;

	
	bool _playBeep = false;
};
