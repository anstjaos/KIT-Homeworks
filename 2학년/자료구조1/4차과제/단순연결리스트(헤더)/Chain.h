#include "ChainNode.h"

class Chain
{
private:
	ChainNode *head;
	ChainNode *first;
public:
	Chain();
	~Chain();
	
	bool checkNode(Book b);					// ��� �ߺ��˻�
	void insertNode(Book b);				// ��� ����
	void deleteNode(string bookNumber);		// �Է¹��� ���� ��ȣ�� �´� ��� ����
	void printAll();						// ��ü ���

	bool loadFile(string fileName);
	void saveFile(string fileName);
};