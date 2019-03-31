#pragma once
#include "Book.h"

class DblList;
class DblListNode
{
	friend class DblList;
private:
	Book data;
	DblListNode *left, *right;
public:
	DblListNode(Book i_data, DblListNode *i_left, DblListNode *i_right);
};