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
	Polynomial();											// default 생성자
	Polynomial(const Polynomial& copy);						// 복사 생성자
	~Polynomial() { delete[] termArray; }					// 동적 할당한 객체를 소멸한다.
	
	void newTerm(const int theCoef, const int theExp);		// 객체 배열에 값 저장
	Polynomial add(Polynomial b);
	Polynomial multi(Polynomial b);
	void printPolynomial();

	void operator= (const Polynomial &);					// = 연산자 오버로딩
	friend istream &operator>>(istream &, Polynomial &);	// >>연산자 오버로딩
	friend ostream &operator<<(ostream &, Polynomial &);	// <<연산자 오버로딩
};
#endif