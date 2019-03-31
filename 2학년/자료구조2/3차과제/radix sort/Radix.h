#pragma once
#include "Node.h"
#include "Queue.h"
#include <time.h>

class Radix {						// Radix sort
public:
	Node* loadFile();

	void modulo16RadixSort(Node* chain);
	void logicalRadixSort(Node* chain);
	void modulo10RadixSort(Node* chain);
};

Node* Radix::loadFile()
{
	string fileName;

	cout << "Input FileName ? ";
	cin >> fileName;

	ifstream fin;

	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "Invalid File ! " << endl;
		return NULL;
	}

	Node* first = new Node();
	Node* curPtr = first;

	unsigned int data;
	while (!fin.eof())
	{
		fin >> data;
		curPtr->link = new Node(data, NULL);
		curPtr = curPtr->link;
	}

	return first;
}

void Radix:: modulo16RadixSort(Node* chain)			// Modulo 연산을 사용한 16진수 LSB radix sort
{
	Queue<Node*> queue[16];

	Node* curPtr = chain->link;

	unsigned int maxNum = -1;
	while (curPtr != NULL)
	{
		if (maxNum < curPtr->data) maxNum = curPtr->data;
		curPtr = curPtr->link;
	}

	int pass = 0;
	while (maxNum != 0)
	{
		maxNum = maxNum / 16;
		pass++;
	}

	unsigned int divisor = 1;
	unsigned int remainder;

	clock_t start, end;
	start = clock();

	for (int i = 0; i < pass; i++)
	{
		curPtr = chain->link;
		while (curPtr != NULL)
		{
			remainder = (curPtr->data / divisor) % 16;
			queue[remainder].push(curPtr);
			curPtr = curPtr->link;
		}

		curPtr = chain;
		for (int i = 0; i < 16; i++)
		{
			while (queue[i].isEmpty() == false)
			{
				curPtr->link = queue[i].getFront();
				queue[i].pop();
				curPtr = curPtr->link;
			}
		}
		curPtr->link = NULL;
		divisor = divisor * 16;
	}
	end = clock();
	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;

	while (chain != NULL)
	{
		curPtr = chain;
		chain = chain->link;
		delete curPtr;
	}
}

void Radix::logicalRadixSort(Node* chain)					// masking과 shift 연산을 사용한 16진수 LSB radix sort
{
	Queue<Node*> queue[16];

	Node* curPtr = chain->link;

	unsigned int maxNum = 0;
	while (curPtr != NULL)
	{
		if (maxNum < curPtr->data) maxNum = curPtr->data;
		curPtr = curPtr->link;
	}

	int pass = 0;
	while (maxNum != 0)
	{
		maxNum = maxNum / 16;
		pass++;
	}

	unsigned int remainder;
	unsigned int shift = 0;

	clock_t start, end;
	start = clock();
	for (int i = 0; i < pass; i++)
	{
		curPtr = chain->link;
		while (curPtr != NULL)
		{
			remainder = (curPtr->data >> shift) & 15;
			queue[remainder].push(curPtr);
			curPtr = curPtr->link;
		}

		curPtr = chain;
		for (int i = 0; i < 16; i++)
		{
			while (queue[i].isEmpty() == false)
			{
				curPtr->link = queue[i].getFront();
				queue[i].pop();
				curPtr = curPtr->link;
			}
		}
		curPtr->link = NULL;
		shift = shift + 4;
	}
	end = clock();
	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;

	while (chain != NULL)
	{
		curPtr = chain;
		chain = chain->link;
		delete curPtr;
	}
}

void Radix ::modulo10RadixSort(Node* chain)						// Modulo 연산을 사용한 10진수 LSB radix sort
{
	Queue<Node*> queue[10];

	Node* curPtr = chain->link;

	unsigned int maxNum = 0;
	while (curPtr != NULL)
	{
		if (maxNum < curPtr->data) maxNum = curPtr->data;
		curPtr = curPtr->link;
	}

	int pass = 0;
	while (maxNum != 0)
	{
		maxNum = maxNum / 10;
		pass++;
	}

	unsigned int divisor = 1;
	unsigned int remainder;

	clock_t start, end;
	start = clock();
	for (int i = 0; i < pass; i++)
	{
		curPtr = chain->link;
		while (curPtr != NULL)
		{
			remainder = (curPtr->data / divisor) % 10;
			queue[remainder].push(curPtr);
			curPtr = curPtr->link;
		}

		curPtr = chain;
		for (int i = 0; i < 10; i++)
		{
			while (queue[i].isEmpty() == false)
			{
				curPtr->link = queue[i].getFront();
				queue[i].pop();
				curPtr = curPtr->link;
			}
		}
		curPtr->link = NULL;
		divisor = divisor * 10;
	}
	end = clock();
	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;

	while (chain != NULL)
	{
		curPtr = chain;
		chain = chain->link;
		delete curPtr;
	}
}