#pragma once
#include "ChainNode.h"

class Chain
{
private:
	ChainNode *first;
public:
	Chain() { first = 0; }
	~Chain();
	
	bool checkNode(Book b);					// ��� �ߺ� �˻�
	void insertNode(Book b);				// ��� ����, �߰�
	void deleteNode(string bookNumber);		// �Է¹��� ���� ��ȣ�� ��ġ�ϴ� ��� ����
	void printAll();						// ��ü ���

	bool loadFile(string fileName);
	void saveFile(string fileName);
};