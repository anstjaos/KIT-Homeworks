#pragma once
#include "TreeNode.h"

template <class T>
class Tree {
private:
	TreeNode<T> *root;
public:
	Tree() { root = NULL; }
	~Tree();

	void createNode(T input);				// 노드 생성하는 함수
	void showAll();							// 전체 출력하는 함수
};

template <class T>
Tree<T> :: ~Tree()
{
	Queue<TreeNode<T>*> q;
	TreeNode<T> *curNode = root;
	while (curNode)
	{
		if (curNode->leftChild) q.push(curNode->leftChild);
		if (curNode->rightChild) q.push(curNode->rightChild);
		
		delete curNode;
		if (q.isEmpty()) break;
		curNode = q.getFront();
		q.pop();
	}
}

template <class T>
void Tree<T> ::createNode(T input)
{
	if (root == NULL) root = new TreeNode<T>(input,1);
	else
	{
		TreeNode<T> *ptr = root;
		while (ptr != NULL)
		{
			if (ptr->data.compare(input) < 0)
			{
				if (ptr->rightChild == NULL)
				{
					ptr->rightChild = new TreeNode<T>(input,ptr->depth+1);
					break;
				}
				ptr = ptr->rightChild;
			}
			else
			{
				if (ptr->leftChild == NULL)
				{
					ptr->leftChild = new TreeNode<T>(input, ptr->depth+1);
					break;
				}
				ptr = ptr->leftChild;
			}

		}
	}
}

template <class T>
void Tree<T> ::showAll()
{
	Stack<TreeNode<T>*> s;
	TreeNode<T> *ptr = root;
	int length = 0;

	while (1)
	{
		if (ptr == NULL)
		{
			while (ptr == NULL)
			{
				if (s.isEmpty())
				{
					cout << "종료합니다." << endl;
					return;
				}
				ptr = s.getTop();
				s.pop();
			}
			if (ptr->rightChild == NULL)
			{
				if (ptr->leftChild != NULL)
				{
					for (int i = 0; i < (ptr->depth - 1) * 5 + length; i++) cout << " ";
					cout << " --- 0" << endl;
				}
				length = length - ptr->data.length();
				ptr = ptr->rightChild;
				continue;
			}
			else if (ptr->leftChild == NULL) cout << "0" << endl;
			
			for (int i = 0; i < (ptr->depth -1) * 5 + length; i++) cout << " ";
			cout << " --- ";
			ptr = ptr->rightChild;
			
			if (ptr->rightChild == NULL && ptr->leftChild == NULL) length = length - ptr->data.length();
		}
		else
		{
			cout << ptr->data;
			if (ptr->leftChild == NULL && ptr->rightChild == NULL) cout << endl;
			else
			{
				cout << " --- ";
				s.push(ptr);
				length = length + ptr->data.length();
			}
			
			ptr = ptr->leftChild;
		}
	}
}