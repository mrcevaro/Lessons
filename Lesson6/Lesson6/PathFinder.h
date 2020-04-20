#pragma once


#include <vector>
#include <queue>
#include <iostream>

namespace Path
{
	struct Point
	{
		int x = 0;
		int y = 0;
	};


	class PathFinder
	{
		static const int size = 20;
		int _field[size][size];

		void GenerateField()
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (std::rand() % 100 < 20)
					{
						_field[i][j] = 1;
					}
					else
					{
						_field[i][j] = 0;
					}
				}
			}
		}

		std::vector<Point> FindPath(Point start_position, Point end_position)
		{
			_field[start_position.x][start_position.y] = 0;
			_field[end_position.x][end_position.y] = 0;

			// понадобится std::queue

			std::queue<int> q;
			q.push(1);
			q.push(2);
			q.push(3);
			q.push(4);
			std::cout << q.front();
			std::cout << q.back();
			q.pop(); 

		}


	};
}