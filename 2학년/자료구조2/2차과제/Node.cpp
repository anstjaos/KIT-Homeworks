#include "Node.h"

Node::Node()
{
	data = -1;
	link = NULL;
}

Node::Node(int i_data, Node *next)
{
	data = i_data;
	link = next;
}