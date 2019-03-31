#include "ChainNode.h"

class Chain
{
private:
	ChainNode *head;
	ChainNode *first;
public:
	Chain();
	~Chain();
	
	bool checkNode(Book b);					// 노드 중복검사
	void insertNode(Book b);				// 노드 삽입
	void deleteNode(string bookNumber);		// 입력받은 도서 번호에 맞는 노드 제거
	void printAll();						// 전체 출력

	bool loadFile(string fileName);
	void saveFile(string fileName);
};