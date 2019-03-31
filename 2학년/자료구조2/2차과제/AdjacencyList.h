#pragma once
#include "Node.h"

class AdjacencyList {							// ������ �׷����� ���� ����Ʈ�� ǥ��
private:
	Node* *adjList;
	int size;

	void displayDFS(int start, bool *visit);	// DFS ���
	void displayBFS(int start, bool *visit);	// BFS ���
public:
	AdjacencyList() {}
	~AdjacencyList();

	void roadFile(string fileName);
	void displayList();
};