#pragma once
#include "Queue.h"

template <class T> class Tree;

template <class T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
public:
	TreeNode() {}
	TreeNode(T i_data);
};

template <class T>
TreeNode<T> ::TreeNode(T i_data)
{
	data = i_data;
	leftChild = NULL;
	rightChild = NULL;
}