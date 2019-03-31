#pragma once
#include "DblListNode.h"

class DblList
{
private:
	DblListNode *first;								
public:
	DblList() { first = NULL; }
	~DblList();

	bool checkNode(Book b);							// 노드의 중복 검사
	DblListNode* findNode(string bookName);			// 특정 도서명부터 출력할 시에 특정 도서 노드의 주소를 return해준다.

	void insertNode(Book b);
	void deleteNode(string bookNumber);
	void showInOrder();								// 전체 출력
	void showReverse();								// 전체 역순 출력
	void showSpecific(DblListNode *index);			// 특정 도서명부터 출력
	void showSpecificReverse(DblListNode *index);	// 특정 도서명부터 처음까지 역순 출력

	bool loadFile(string fileName);
	void saveFile(string fileName);
};