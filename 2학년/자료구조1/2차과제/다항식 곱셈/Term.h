#ifndef TERM_H
#define TERM_H
#include <iostream>
using namespace std;

class Polynomial;
class Term
{
	friend Polynomial;
private:
	int coef;			// ���
	int exp;			// ����
public:
	Term() {};

	void showTerm();	// ����� ����ϴ� �Լ�
};
#endif