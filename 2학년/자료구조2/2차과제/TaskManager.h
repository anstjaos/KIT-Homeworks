#pragma once
#include "AdjacencyArray.h"
#include "AdjacencyList.h"
#include "WeightedEdgeList.h"
#include "topologicalOrder.h"

class TaskManager
{
public:
	void search();						// DFS�� BFS
	void minimumCostSpanningTree();		// �ּҺ�� ����Ʈ�� ���α׷�
	void topologicalSort();				// ���� ���� ���α׷���
};