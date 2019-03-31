#pragma once
#include "DblListNode.h"

class DblList
{
private:
	DblListNode *first;
	DblListNode *head;
public:
	DblList();
	~DblList();
	
	bool checkNode(Book b);
	DblListNode* findNode(string bookName);					// ã�����ϴ� Ư�� ��������� �ּҸ� return

	void insertNode(Book b);  
	void deleteNode(string bookNumber);
	
	void showInOrder();										// ���������� ���
	void showReverse();										// �������� ���
	void showSpecific(DblListNode *index);					// Ư�� ������ ���
	void showSpecificReverse(DblListNode *index);			// Ư�� ������ �������� ó������ ���

	bool loadFile(string fileName);
	void saveFile(string fileName);
};