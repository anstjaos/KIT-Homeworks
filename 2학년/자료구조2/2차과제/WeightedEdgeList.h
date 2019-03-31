#pragma once
#include "WeightedEdge.h"

class WeightedEdgeList									// 가중치가 있는 간선의 객체들을 관리하는 클래스
{
private:
	WeightedEdge *weList;
	int count;
	int capacity;
	int *parents;										// 자식이 부모의 index를 가지고 있는 배열, 자기 자신이 부모(루트)일 경우 -1
	int vertexCount;									// 정점의 개수

	void changeSize();
	void sortList(int left, int right);					// Quick Sort 사용
	void weightedUnion(int vertex1, int vertex2);		// 두 개의 트리를 합친다.
	int collapsingFind(int vertex);						// 매개 변수로 받은 정점으로부터 루트까지 올라가면서 부모를 루트로 바꾼다.
	void insertEdge(WeightedEdge e);
public:
	WeightedEdgeList();
	~WeightedEdgeList();

	void roadFile(string fileName);
	void minCostSpanningTree();
	void displayTree();
};