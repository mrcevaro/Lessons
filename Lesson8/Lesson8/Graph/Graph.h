#pragma once

namespace Graph
{
	class AbstractGraph
	{
	public:
		virtual size_t NodesCount() = 0;
		virtual size_t EdgesCount() = 0;

		virtual bool IsNodeExist(int node_id) = 0;
		virtual bool IsEdgeExist(int node_id_1, int node_id_2) = 0;

		// Вернуть true, если успешно добавился (до этого узла с таким id не было)
		virtual bool AddNode(int node_id) = 0;
		virtual bool AddEdge(int node_id_1, int node_id_2) = 0;

		// Удаляет узел, возвращает сколько ребер у него было
		virtual int RemoveNode(int node_id) = 0;
		virtual void RemoveEdge(int node_id_1, int node_id_2) = 0;

		virtual int AdjacentNodesCount(int node_id) = 0;
		virtual int GetAdjacentNodeId(int node_id, int i) = 0;

		virtual void Clear() = 0;

		virtual void Print() = 0;
	};
}


void f()
{
	//std::map<int, std::string> s;
}

/*
	1. Сделать 3 способа хранения графа. 
	Матрица смежности
	Матрица инцидентности
	Список смежности

	2. Сделать наш способ хранения графа

	3. Запилить 2 алгоритма: Дейкстры и Краскала

*/

//void f()
//{
//	for (int i = 0; i < AdjacentNodesCount(3); i++)
//	{
//		std::cout << GetAdjacentNodeId(3, i) << std::endl;
//	}
//}