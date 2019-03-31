#pragma once
#include "Node.h"

class topologicalOrder					// 위상 정렬 클래스
{
private:
	Node *edgeList;
	int count;
public:
	topologicalOrder() {}
	~topologicalOrder();

	void roadFile(string fileName);
	void displayTopologicalOrder();
};