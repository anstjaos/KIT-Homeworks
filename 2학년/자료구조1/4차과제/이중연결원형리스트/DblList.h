#pragma once
#include "DblListNode.h"

class DblList
{
private:
	DblListNode *first;								
public:
	DblList() { first = NULL; }
	~DblList();

	bool checkNode(Book b);							// ����� �ߺ� �˻�
	DblListNode* findNode(string bookName);			// Ư�� ��������� ����� �ÿ� Ư�� ���� ����� �ּҸ� return���ش�.

	void insertNode(Book b);
	void deleteNode(string bookNumber);
	void showInOrder();								// ��ü ���
	void showReverse();								// ��ü ���� ���
	void showSpecific(DblListNode *index);			// Ư�� ��������� ���
	void showSpecificReverse(DblListNode *index);	// Ư�� ��������� ó������ ���� ���

	bool loadFile(string fileName);
	void saveFile(string fileName);
};