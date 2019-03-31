#pragma once
#include "Queue.h"
#include "CommonHeader.h"

class AdjancencyArray {			// ������ �׷����� ���� ��ķ� ǥ��
private:
	int **adjArray;				// 2���� ���� �迭
	int size;					// ���� �迭 ������

	void displayDFS(int start, bool *visit);	// DFS ���
	void displayBFS(int start, bool *visit);	// BFS ���
public:
	AdjancencyArray() {}
	~AdjancencyArray();

	void roadFile(string fileName);				// ���Ϸ� ���� ������ �о�� ���� �ʱ�ȭ�Ѵ�.
	void displayArray();
};