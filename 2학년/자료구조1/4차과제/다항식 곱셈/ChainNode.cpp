#include "ChainNode.h"

ChainNode::ChainNode(Term i_data, ChainNode *next)
{
	data = i_data;
	link = next;
}