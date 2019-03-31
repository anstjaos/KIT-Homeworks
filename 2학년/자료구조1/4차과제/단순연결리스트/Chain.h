#pragma once
#include "ChainNode.h"

class Chain
{
private:
	ChainNode *first;
public:
	Chain() { first = 0; }
	~Chain();
	
	bool checkNode(Book b);					// 노드 중복 검사
	void insertNode(Book b);				// 노드 생성, 추가
	void deleteNode(string bookNumber);		// 입력받은 도서 번호와 일치하는 노드 삭제
	void printAll();						// 전체 출력

	bool loadFile(string fileName);
	void saveFile(string fileName);
};