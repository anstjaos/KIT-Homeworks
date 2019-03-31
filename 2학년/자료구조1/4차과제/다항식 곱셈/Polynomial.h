#pragma once
#include "ChainNode.h"

class Polynomial
{
private:
	ChainNode *first;
	ChainNode *last;				// �߰��Ǵ� ���� �׻� �ǵڿ� �����ϹǷ� last ���� ����
public:
	Polynomial();
	~Polynomial();

	void setFirst(ChainNode *c) { first = c; }		// first�� ����Ű�� �ּҰ� ����
	void insertNode(Term t);

	void add(const Polynomial& b);
	void multi(const Polynomial& b);
	void displayResult();

	friend istream &operator >> (istream &is, Polynomial &p);
};