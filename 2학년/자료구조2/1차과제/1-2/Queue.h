#pragma once
#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

template <class T>
class Queue {
private:
	T *queue;
	int capacity;
	int front;
	int rear;

	void changeCapacity();
	bool isFull();
public:
	Queue();
	~Queue() { delete[] queue; }

	T& getFront();
	void push(T &item);
	bool isEmpty();
	void pop();
};

template <class T>
Queue<T> ::Queue()
{
	capacity = 4;
	front = 0;
	rear = 0;
	queue = new T[capacity];
}

template <class T>
void Queue<T> ::changeCapacity()
{
	T* newQueue = new T[2 * capacity];

	int start = (front + 1) % capacity;
	if (start < 2) copy(queue + start, queue + start + capacity - 1, newQueue);
	else
	{
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}
	
	front = 2 * capacity - 1;
	rear = capacity - 2;
	capacity *= 2;

	delete[] queue;
	queue = newQueue;
}

template <class T>
bool Queue<T> ::isFull()
{
	if ((rear + 1) % capacity == front) return true;
	else return false;
}

template <class T>
T& Queue<T> ::getFront()
{
	if (isEmpty())
	{
		throw "queue is empty!";
	}

	return queue[(front + 1)%capacity];
}

template <class T>
void Queue<T>:: push(T &item)
{
	if (isFull()) changeCapacity();
	rear = (rear + 1) % capacity;
	queue[rear] = item;
}

template <class T>
bool Queue<T> ::isEmpty()
{
	return front == rear;
}

template <class T>
void Queue<T> ::pop()
{
	if (isEmpty())
	{
		throw "queue is empty!";
	}
	front = (front+1) % capacity;
	queue[front].~T();
}