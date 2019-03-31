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
	DblListNode* findNode(string bookName);					// 찾고자하는 특정 도서노드의 주소를 return

	void insertNode(Book b);  
	void deleteNode(string bookNumber);
	
	void showInOrder();										// 순차적으로 출력
	void showReverse();										// 역순으로 출력
	void showSpecific(DblListNode *index);					// 특정 노드부터 출력
	void showSpecificReverse(DblListNode *index);			// 특정 노드부터 역순으로 처음까지 출력

	bool loadFile(string fileName);
	void saveFile(string fileName);
};