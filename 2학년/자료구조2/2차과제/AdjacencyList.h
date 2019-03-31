#pragma once
#include "Node.h"

class AdjacencyList {							// 무방향 그래프를 인접 리스트로 표현
private:
	Node* *adjList;
	int size;

	void displayDFS(int start, bool *visit);	// DFS 출력
	void displayBFS(int start, bool *visit);	// BFS 출력
public:
	AdjacencyList() {}
	~AdjacencyList();

	void roadFile(string fileName);
	void displayList();
};