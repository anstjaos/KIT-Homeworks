#pragma once

template <class T>
class Stack {				// ���� Ŭ����
private:
	T *stack;
	int top;
	int capacity;

	void changeSize(T *&stack, const int newSize);
public:
	Stack();
	~Stack();

	bool isEmpty() const;
	T& getTop() const;
	int getIndex() const;
	void push(const T& item);
	void pop();
};

template <class T>
Stack<T>::Stack()
{
	capacity = 10;
	top = -1;
	stack = new T[capacity];
}

template <class T>
Stack<T>::~Stack()
{
	delete[] stack;				// �޸� ���� �Ҵ� ����
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return top == -1;
}

template <class T>
T& Stack<T>::getTop() const
{
	if (isEmpty())
	{
		throw "������ ����ֽ��ϴ�!";
	}

	return stack[top];
}

template <class T>
int Stack<T>::getIndex() const
{
	return top;
}

template <class T>
void Stack<T>::push(const T& item)
{
	if (top == capacity - 1)
	{
		changeSize(stack, 2 * capacity);
		capacity *= 2;
	}

	stack[++top] = item;
}

template <class T>
void Stack<T>::pop()
{
	if (isEmpty()) throw "������ ����ֽ��ϴ�! ������ �Ұ����մϴ�.";

	stack[top--].~T();
}

template <class T>
void Stack<T>::changeSize(T *&stack, const int newSize)
{
	if (newSize < 0) throw "ũ��� �׻� 0���� Ŀ���մϴ�.";

	T* temp = new T[newSize];
	copy(stack, stack + capacity, temp);
	delete[] stack;
	stack = temp;
}