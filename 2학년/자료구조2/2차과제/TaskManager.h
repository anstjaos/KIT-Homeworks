#pragma once
#include "AdjacencyArray.h"
#include "AdjacencyList.h"
#include "WeightedEdgeList.h"
#include "topologicalOrder.h"

class TaskManager
{
public:
	void search();						// DFS와 BFS
	void minimumCostSpanningTree();		// 최소비용 신장트리 프로그램
	void topologicalSort();				// 위상 정렬 프로그래밍
};