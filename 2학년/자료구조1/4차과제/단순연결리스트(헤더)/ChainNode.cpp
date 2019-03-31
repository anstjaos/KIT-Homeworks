#include "ChainNode.h"

ChainNode::ChainNode(Book b, ChainNode *next)
{
	data = b;
	link = next;
}