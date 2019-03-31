#pragma once
#include "Queue.h"

template <class T>
class Stack {
private:
	T *stack;
	int capacity;
	int top;

	void changeSize();
public:
	Stack();
	~Stack() { delete[] stack; }

	bool isEmpty();
	T& getTop();
	void push(T item);
	void pop();
};

template <class T>
Stack<T> ::Stack()
{
	capacity = 4;
	top = -1;
	stack = new T[capacity];
}

template <class T>
void Stack<T> ::changeSize()
{
	T *temp = new T[capacity * 2];
	copy(stack, stack + capacity, temp);
	delete[] stack;
	stack = temp;
}

template <class T>
bool Stack<T> ::isEmpty()
{
	return top == -1;
}

template <class T>
T& Stack<T> ::getTop()
{
	if (isEmpty())
	{
		throw "stack is empty!";
	}

	return stack[top];
}
template <class T>
void Stack<T> ::push(T item)
{
	if (top == capacity - 1)
	{
		changeSize();
	}

	stack[++top] = item;
}

template <class T>
void Stack<T> ::pop()
{
	if (isEmpty())
	{
		throw "stack is empty!";
	}
	else stack[top--].~T();
}