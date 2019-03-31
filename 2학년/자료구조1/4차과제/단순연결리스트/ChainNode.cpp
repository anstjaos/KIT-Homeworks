#include "ChainNode.h"

ChainNode:: ChainNode(Book i_data, ChainNode *next)
{
	data = i_data;
	link = next;
}