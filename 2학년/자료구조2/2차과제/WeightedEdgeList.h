#pragma once
#include "WeightedEdge.h"

class WeightedEdgeList									// ����ġ�� �ִ� ������ ��ü���� �����ϴ� Ŭ����
{
private:
	WeightedEdge *weList;
	int count;
	int capacity;
	int *parents;										// �ڽ��� �θ��� index�� ������ �ִ� �迭, �ڱ� �ڽ��� �θ�(��Ʈ)�� ��� -1
	int vertexCount;									// ������ ����

	void changeSize();
	void sortList(int left, int right);					// Quick Sort ���
	void weightedUnion(int vertex1, int vertex2);		// �� ���� Ʈ���� ��ģ��.
	int collapsingFind(int vertex);						// �Ű� ������ ���� �������κ��� ��Ʈ���� �ö󰡸鼭 �θ� ��Ʈ�� �ٲ۴�.
	void insertEdge(WeightedEdge e);
public:
	WeightedEdgeList();
	~WeightedEdgeList();

	void roadFile(string fileName);
	void minCostSpanningTree();
	void displayTree();
};