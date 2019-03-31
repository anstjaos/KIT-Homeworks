#pragma once
#include "Book.h"

class Chain;
class ChainNode
{
	friend class Chain;
private:
	Book data;
	ChainNode *link;
public:
	ChainNode(Book i_data, ChainNode *next = 0);
};