#pragma once
#include <iostream>
using namespace std;

template <class T> class Insertion;

template <class T>
class Node {							// Doubly Linked list를 구성하기 위한 Node
	friend class Insertion<T>;
private:
	T data;
	Node* pre;
	Node* next;
public:
	Node();
	Node(T i_data, Node* i_pre, Node* i_next);
	~Node() {}
};

template <class T>
Node<T> ::Node()
{
	pre = NULL;
	next = NULL;
}

template <class T>
Node<T> ::Node(T i_data, Node* i_pre, Node* i_next)
{
	data = i_data;
	pre = i_pre;
	next = i_next;
}