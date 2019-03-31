#include "DblListNode.h"

DblListNode:: DblListNode(Book i_data, DblListNode *i_left, DblListNode *i_right)
{
	data = i_data;
	left = i_left;
	right = i_right;
}