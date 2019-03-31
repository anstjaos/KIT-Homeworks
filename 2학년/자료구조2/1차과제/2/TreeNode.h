#pragma once
#include "Expression.h"

template <class T> class Tree;

template <class T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	int result;					// 결과 값을 가지고 있는 변수
	int blankCount;				// 출력할 때 자신의 공백값을 가지고 있는 변수
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
public:
	TreeNode() {}
	TreeNode(T i_data,int i_result);
	~TreeNode() {}

	void setBlackCount(int parentCount);
};

template <class T>
TreeNode<T> ::TreeNode(T i_data,int i_result)
{
	data = i_data;
	result = i_result;
	leftChild = NULL;
	rightChild = NULL;
}

template<class T>
void TreeNode<T>::setBlackCount(int parentCount)
{
	int tempLength = 0;

	if (data.getType() == OPERATOR) tempLength = tempLength + 4;
	int temp = result;
	if (temp < 0) tempLength++;
	while (temp != 0)
	{
		temp = temp / 10;
		tempLength++;
	}
	if(parentCount == 0) blankCount = parentCount + tempLength;
	else blankCount = parentCount + tempLength +5;
}