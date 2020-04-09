#pragma once

class Score
{
public:

	Score(const Point point)
		: _point(point)
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
		Point point_score {_point.x + 3, _point.y + 3 };
		cs.Print(point_score, std::to_string(score));
	}

private:

	void DrawBorderScore() const
	{
		for (int i = _point.x; i < _point.x + 10; i++)
		{
			cs.Print(i, _point.y, kWallSymbol);
			cs.Print(i, _point.y + 10, kWallSymbol);
		}

		for (int j = _point.y; j < _point.y + 11; j++)
		{
			cs.Print(_point.x, j, kWallSymbol);
			cs.Print(_point.x + 10, j, kWallSymbol);
		}
	}

	void DrawTitleScore() const
	{
		Point point_title { _point.x + 3, _point.y + 2 };
		cs.Print(point_title, "Score");
	}

	ConsoleHelper cs;
	Point _point;
	int score = 0;
};