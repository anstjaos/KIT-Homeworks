#pragma once
#include "Node.h"

class topologicalOrder					// ���� ���� Ŭ����
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