#pragma once
#include "TreeNode.h"

template <class T>
class Tree {
private:
	TreeNode<T> *root;
public:
	Tree() { root = NULL; }
	~Tree();

	void createTree(Expression ex);				// 노드를 생성하는 함수
	void showAll();								// 전체 출력하는 함수
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
		if (q.isEmpty()) return;
		delete curNode;
		curNode = q.getFront();
		q.pop();
	}
}

template <class T>
void Tree<T> ::createTree(Expression ex)
{
	Stack<TreeNode<T>*> s;
	for (int i = 0; i < ex.getCount(); i++)
	{
		union token temp;
		Token curToken = ex.getToken(i);
		TreeNode<T> *tempPtr;
		TreeNode<T> *left;
		TreeNode<T> *right;

		if (curToken.getType() == OPERAND)
		{
			tempPtr = new TreeNode<T>(curToken, curToken.getData().value);
			s.push(tempPtr);
		}
		else
		{
			int result;
			temp.oper = curToken.getData().oper;
			curToken.setData(temp);
			switch (ex.isp(temp.oper))
			{
			case 1:
				left = s.getTop();
				s.pop();
				if (temp.oper == '~')
				{
					result = left->result * (-1);
				}
				else if (temp.oper == '!')
				{
					if (left->result == 0)
					{
						result = 1;
					}
					else
					{
						result = 0;
					}
				}
				tempPtr = new TreeNode<Token>(curToken, result);
				tempPtr->leftChild = left;
				s.push(tempPtr);
				break;
			case 2:			// 제곱 연산자 '^'
			{
				right = s.getTop();
				s.pop();

				left = s.getTop();
				s.pop();

				result = 1;
				if (right->result < 0) throw Exception("[오류] 제곱의 두 번째 연산자가 음수인 경우 발생!");
				else
				{
					for (int i = 0; i < right->result; i++)
					{
						result *= left->result;
					}
				}
				tempPtr = new TreeNode<Token>(curToken, result);
				tempPtr->leftChild = left;
				tempPtr->rightChild = right;
				s.push(tempPtr);
				break;
			}
			case 3:			// 곱셈, 나눗셈, 나머지 연산자
				right = s.getTop();
				s.pop();

				left = s.getTop();
				s.pop();
				if (temp.oper == '*')
				{
					result = left->result * right->result;
				}
				else if (temp.oper == '/')
				{
					if (right->result == 0) throw Exception("[오류] 나누기 우측 연산자가 0인 경우 발생");

					result = left->result / right->result;
				}
				else if (temp.oper == '%')
				{
					if (right->result == 0) throw Exception("[오류] 퍼센트 우측 연산자가 0인 경우 발생");

					result = left->result % right->result;
				}
				tempPtr = new TreeNode<Token>(curToken, result);
				tempPtr->leftChild = left;
				tempPtr->rightChild = right;
				s.push(tempPtr);
				break;
			case 4:			// 덧셈, 뺄셈 연산자
				right = s.getTop();
				s.pop();

				left = s.getTop();
				s.pop();
				if (temp.oper == '+')
				{
					result = left->result + right->result;
				}
				else if (temp.oper == '-')
				{
					result = left->result - right->result;
				}
				tempPtr = new TreeNode<Token>(curToken, result);
				tempPtr->leftChild = left;
				tempPtr->rightChild = right;
				s.push(tempPtr);
				break;
			default:
				break;
			}
		}
	}
	root = s.getTop();
	s.pop();
}

template <class T>
void Tree<T> ::showAll()
{
	Stack<TreeNode<T>*> s;
	TreeNode<T> *ptr = root;
	int length = 0;
	ptr->setBlackCount(0);

	while (1)
	{
		if (ptr == NULL)
		{
			while (ptr == NULL)
			{
				if (s.isEmpty())
				{
					cout << "---- 결과는 " << root->result << endl;
					return;
				}
				ptr = s.getTop();
				s.pop();
			}

			if (ptr->rightChild != NULL)
			{
				ptr->rightChild->setBlackCount(ptr->blankCount);
				for (int i = 0; i < ptr->blankCount; i++) cout << " ";
				cout << " --- ";
			}
			
			ptr = ptr->rightChild;
		}
		else
		{
			if (ptr->data.getType() == OPERATOR)
			{
				cout << ptr->data.getData().oper << " (" << ptr->result << ")";
			}
			else
			{
				cout << ptr->result;
			}

			if (ptr->leftChild == NULL && ptr->rightChild == NULL) cout << endl;
			else
			{
				cout << " --- ";
				s.push(ptr);
			}

			if (ptr->leftChild != NULL) ptr->leftChild->setBlackCount(ptr->blankCount);
			ptr = ptr->leftChild;
		}
	}
	
}