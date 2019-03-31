#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"

class Polynomial
{
private:
	Term *termArray;
	int capacity;
	int terms;
public:
	Polynomial();											// default ������
	Polynomial(const Polynomial& copy);						// ���� ������
	~Polynomial() { delete[] termArray; }					// ���� �Ҵ��� ��ü�� �Ҹ��Ѵ�.
	
	void newTerm(const int theCoef, const int theExp);		// ��ü �迭�� �� ����
	Polynomial add(Polynomial b);
	Polynomial multi(Polynomial b);
	void printPolynomial();

	void operator= (const Polynomial &);					// = ������ �����ε�
	friend istream &operator>>(istream &, Polynomial &);	// >>������ �����ε�
	friend ostream &operator<<(ostream &, Polynomial &);	// <<������ �����ε�
};
#endif