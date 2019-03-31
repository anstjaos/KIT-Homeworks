#pragma once
#include <iostream>
#include <iomanip>

#define ALL true
#define PREORDER false
using namespace std;

template <class T>
class Tree {
private:
	T *treeArr;
	int capacity;

	void init();								// 배열 값을 0으로 초기화 하는 함수
	int checkNumberOfDigits(int index);			// 공백을 맞추기위해 자리수를 return하는 함수
	void print(int index);						// 전체 출력을 위한 함수
	void visit(int index);						

	void preorder(int index, bool flag);
	void inorder(int index);
	void postorder(int index);

	void showAll();								// 전체적인 출력을 담당하는 함수
	void showPreorder();
	void showInorder();
	void showPostorder();
	void showLevelorder();
public:
	Tree(int i_capacity);
	~Tree() { delete[] treeArr; }

	void printAll();
};

template <class T>
Tree<T> :: Tree(int i_capacity)
{
	capacity = i_capacity;
	treeArr = new T[capacity + 1];
}

template <class T>
void Tree<T> ::init()
{
	for (int i = 1; i <= capacity; i++) treeArr[i] = 0;
}

template <class T>
int Tree<T> ::checkNumberOfDigits(int index)
{
	int num = index;
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

	return cnt;
}

template <class T>
void Tree<T> ::print(int index)
{
	int cnt = -1;
	int pre = 1;
	int next = 2;
	int parentCnt = checkNumberOfDigits(index);

	if (index == 1)
	{
		cout << index;
		return;
	}

	if (treeArr[index/2] == 1)
	{
		cout << endl;
		while (1)
		{
			if (pre <= index && index < next) break;

			pre = pre * 2;
			next = next * 2;
			cnt++;
		}
		for (int i = 0; i <= cnt * 6 + parentCnt; i++) cout << " ";
	}

	cout << " --- " << index;
	treeArr[index / 2]++;
}

template <class T>
void Tree<T> ::visit(int index)
{
	cout << index << " ";
	treeArr[index] = -1;					// 한번 방문한 곳을 -1로 변경
}

template <class T>
void Tree<T> ::preorder(int index, bool flag)			// 매개변수로 받는 값에 따라 전체 출력과 preorder 출력을 정한다.
{
	if (treeArr[index] != -1)
	{
		if (flag == ALL) print(index);
		else visit(index);

		if (index * 2 <= capacity) preorder(index * 2,flag);
		if (index * 2 + 1 <= capacity) preorder(index * 2 + 1,flag);
	}
}

template <class T>
void Tree<T>::inorder(int index)
{
	if (treeArr[index] != -1)
	{
		if (index * 2 <= capacity) inorder(index * 2);
		visit(index);
		if (index * 2 + 1 <= capacity) inorder(index * 2 + 1);
	}
}

template <class T>
void Tree<T>:: postorder(int index)
{
	if (treeArr[index] != -1)
	{
		if (index * 2 <= capacity) postorder(index * 2);
		if (index * 2 + 1 <= capacity) postorder(index * 2 + 1);
		visit(index);
	}
}

template <class T>
void Tree<T> ::showAll()
{
	init();
	preorder(1, ALL);
	cout << endl;
}

template <class T>
void Tree<T> ::showPreorder()
{
	init();
	cout.setf(ios::left);
	cout << setw(11) <<  "preorder" << ": ";
	preorder(1,PREORDER);
	cout << endl;
}

template <class T>
void Tree<T> ::showInorder()
{
	init();
	cout.setf(ios::left);
	cout << setw(11) << "inorder" << ": ";
	inorder(1);
	cout << endl;
}

template <class T>
void Tree<T> ::showPostorder()
{
	init();
	cout.setf(ios::left);
	cout << setw(11) << "postorder" << ": ";
	postorder(1);
	cout << endl;
}

template <class T>
void Tree<T> ::showLevelorder()
{
	cout.setf(ios::left);
	cout << setw(11) << "level order" << ": ";
	for (int i = 1; i <= capacity; i++) cout << i << " ";
	cout << endl;
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