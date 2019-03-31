#include "Node.h"

Node::Node()
{
	data = -1;
	link = NULL;
}

Node::Node(int i_data,Node* i_link)
{
	data = i_data;
	link = i_link;
}