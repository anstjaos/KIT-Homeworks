#pragma once
#include "Queue.h"
#include "Stack.h"
#include "CommonHeader.h"

class AdjacencyList;
class topologicalOrder;

class Node
{
	friend class AdjacencyList;
	friend class topologicalOrder;
private:
	int data;
	Node *link;
public:
	Node();
	Node(int i_data, Node *next);
	~Node() {}
};