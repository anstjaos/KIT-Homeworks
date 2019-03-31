#pragma once
#include "ChainNode.h"

class Polynomial
{
private:
	ChainNode *first;
	ChainNode *last;				// 추가되는 노드는 항상 맨뒤에 가야하므로 last 변수 선언
public:
	Polynomial();
	~Polynomial();

	void setFirst(ChainNode *c) { first = c; }		// first가 가리키는 주소값 변경
	void insertNode(Term t);

	void add(const Polynomial& b);
	void multi(const Polynomial& b);
	void displayResult();

	friend istream &operator >> (istream &is, Polynomial &p);
};