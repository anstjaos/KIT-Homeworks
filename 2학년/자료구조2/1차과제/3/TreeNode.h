#pragma once
#include "Stack.h"

template <class T> class Tree;

template <class T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	int depth;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
public:
	TreeNode() {}
	TreeNode(T i_data, int i_depth);
	~TreeNode() {}
};

template <class T>
TreeNode<T> ::TreeNode(T i_data, int i_depth)
{
	data = i_data;
	depth = i_depth;
	leftChild = NULL;
	rightChild = NULL;
}