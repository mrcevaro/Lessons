#pragma once

class Score
{
public:

	Score(const int width, const int height)
		: _width(width),
		_height(height)
	{
		DrawBorderScore();
		DrawTitleScore();
		DrawScore();
	}

	void UpdateScore()
	{
		score++;
	}

	void DrawScore()
	{
		Point p = { _width + 3, 3 };
		cs.Print(p, std::to_string(score));
	}

private:

	void DrawBorderScore() const
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
	}

	void DrawTitleScore() const
	{
		Point p = { _width + 3, 2 };
		cs.Print(p, "Score");
	}

	const int _width = 0;
	const int _height = 0;
	ConsoleHelper cs;

	int score = 0;
};