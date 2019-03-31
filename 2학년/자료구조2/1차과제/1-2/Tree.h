#pragma once
#include "TreeNode.h"
#define ALL true
#define PREORDER false

template <class T>
class Tree {
private:
	TreeNode<T> *root;
	int nodeCount;

	void createNode(TreeNode<T> *parent, T data);				// 노드 생성
	int checkNumberOfDigits(TreeNode<T> *curNode);				// 자리수를 return하는 함수
	void print(TreeNode<T> *curNode);
	void visit(TreeNode<T> *curNode);

	void preorder(TreeNode<T> *curNode, bool flag);
	void inorder(TreeNode<T> *curNode);
	void postorder(TreeNode<T> *curNode);

	void showAll();												// 전체 출력을 담당하는 함수
	void showPreorder();
	void showInorder();
	void showPostorder();
	void showLevelorder();
public:
	Tree(int i_nodeCount);
	~Tree();

	void printAll();
};

template <class T>
Tree<T> ::Tree(int i_nodeCount)
{
	nodeCount = i_nodeCount;
	root = new TreeNode<T>(1);
	createNode(root, root->data);
}

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
		if (q.isEmpty()) return;
		curNode = q.getFront();
		q.pop();
	}
}

template <class T>
void Tree<T> ::createNode(TreeNode<T> *parent, T data)
{
	if (parent->data * 2 <= nodeCount)								// nodeCount 보다 작을 경우 노드 생성
	{
		parent->leftChild = new TreeNode<T>(parent->data * 2);
		createNode(parent->leftChild, parent->leftChild->data);
	}
	if (parent->data * 2 +1 <= nodeCount)
	{
		parent->rightChild = new TreeNode<T>(parent->data * 2+1);
		createNode(parent->rightChild, parent->rightChild->data);
	}
}

template <class T>
int Tree<T> ::checkNumberOfDigits(TreeNode<T> *curNode)
{
	int num = curNode->data;
	int cnt = 0;
	int temp;
	while (1)
	{
		num = num / 2;
		temp = num;
		if (num == 0) break;
		while (1)
		{
			temp = temp / 10;
			if (temp == 0) break;
			cnt++;
		}
	}
	
	return cnt;							// 자리수를 return
}

template <class T>
void Tree<T> ::print(TreeNode<T> *curNode)
{
	int cnt = -1;
	int pre = 1;
	int next = 2;
	int parentCnt = checkNumberOfDigits(curNode);

	if (curNode->data == 1)
	{
		cout << curNode->data;
		return;
	}

	if (curNode->data % 2 != 0)			// rightChild는 홀수이므로
	{
		cout << endl;
		while (1)
		{
			if (pre <= curNode->data && curNode->data < next) break;

			pre = pre * 2;
			next = next * 2;
			cnt++;
		}
		for (int i = 0; i <= cnt * 6 + parentCnt; i++) cout << " ";
	}

	cout << " --- " << curNode->data;
}

template <class T>
void Tree<T> ::visit(TreeNode<T> *curNode)
{
	cout << curNode->data << " ";
}

template <class T>
void Tree<T> ::preorder(TreeNode<T> *curNode, bool flag)
{
	if (curNode)
	{
		if (flag == ALL) print(curNode);
		else visit(curNode);

		preorder(curNode->leftChild, flag);
		preorder(curNode->rightChild, flag);
	}
}

template <class T>
void Tree<T>::inorder(TreeNode<T> *curNode)
{
	if (curNode)
	{
		inorder(curNode->leftChild);
		visit(curNode);
		inorder(curNode->rightChild);
	}
}

template <class T>
void Tree<T>::postorder(TreeNode<T> *curNode)
{
	if (curNode)
	{
		postorder(curNode->leftChild);
		postorder(curNode->rightChild);
		visit(curNode);
	}
}

template <class T>
void Tree<T> ::showAll()
{
	preorder(root, ALL);
	cout << endl;
}

template <class T>
void Tree<T> ::showPreorder()
{
	cout.setf(ios::left);
	cout << setw(11) << "preorder" << ": ";
	preorder(root, PREORDER);
	cout << endl;
}

template <class T>
void Tree<T> ::showInorder()
{
	cout.setf(ios::left);
	cout << setw(11) << "inorder" << ": ";
	inorder(root);
	cout << endl;
}

template <class T>
void Tree<T> ::showPostorder()
{
	cout.setf(ios::left);
	cout << setw(11) << "postorder" << ": ";
	postorder(root);
	cout << endl;
}

template <class T>
void Tree<T> ::showLevelorder()
{
	cout.setf(ios::left);
	cout << setw(11) << "level order" << ": ";

	Queue<TreeNode<T>*> q;
	TreeNode<T> *curNode = root;
	while (curNode)
	{
		visit(curNode);
		if (curNode->leftChild) q.push(curNode->leftChild);
		if (curNode->rightChild) q.push(curNode->rightChild);
		if (q.isEmpty())
		{
			cout << endl;
			return;
		}
		curNode = q.getFront();
		q.pop();
	}
}

template <class T>
void Tree<T> ::printAll()
{
	showAll();
	showPreorder();
	showInorder();
	showPostorder();
	showLevelorder();
}