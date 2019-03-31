#include "Polynomial.h"

Polynomial:: Polynomial()													// default 생성자
{
	capacity = 1;
	terms = 0;
	termArray = new Term[capacity];
}

Polynomial::Polynomial(const Polynomial& copy)								// 복사 생성자
{																			// 함수가 끝나면 자동으로 소멸자가 호출되어
	capacity = copy.capacity;												// 객체가 소멸되므로 복사 생성자를 정의하였다.
	terms = copy.terms;
	termArray = new Term[copy.capacity];
	memcpy(termArray, copy.termArray, sizeof(Term)*copy.terms);
}

void Polynomial::newTerm(const int theCoef, const int theExp)
{
	if (terms == capacity)													// 동적 할당한 객체 배열이 가득 찼을 경우
	{																		// capacity를 2배로 늘리고 기존 객체를 delete하고
		capacity *= 2;														// 새로운 객체를 가리키게 한다.
		Term *temp = new Term[capacity];
		memcpy(temp, termArray, sizeof(Term)*terms);
		delete[] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoef;
	termArray[terms++].exp = theExp; 
}

Polynomial Polynomial::add(Polynomial b)
{
	Polynomial c;
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < b.terms))
	{
		if ((termArray[aPos].exp == b.termArray[bPos].exp))					// 지수가 같은 경우 계수끼리 더하여 값을 저장한다.
		{
			int coef = termArray[aPos].coef + b.termArray[bPos].coef;
			if (coef != 0) c.newTerm(coef, termArray[aPos].exp);
			aPos++;
			bPos++;
		}
		else if ((termArray[aPos].exp < b.termArray[bPos].exp))				// b의 지수가 더 클 경우 b의 계수와 지수를 저장한다.
		{
			c.newTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else																// 호출한 객체의 지수가 더 클 경우 
		{																	// 객체의 계수와 지수를 저장한다.
			c.newTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	for (; aPos < terms; aPos++)											// 아직 남아있는 계수와 지수를 저장한다.
	{
		if (termArray[aPos].coef != 0) c.newTerm(termArray[aPos].coef, termArray[aPos].exp);
	}
	for (; bPos < b.terms; bPos++)
	{
		if (b.termArray[bPos].coef != 0) c.newTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	}
	return c;
}

Polynomial Polynomial :: multi(Polynomial p)
{
	Polynomial result;														// 값을 저장할 객체를 선언한다.
	for (int aPos = 0; aPos < terms; aPos++)
	{
		Polynomial temp;
		for (int bPos = 0; bPos < p.terms; bPos++)
		{
			int coef = termArray[aPos].coef * p.termArray[bPos].coef;
			int exp = termArray[aPos].exp + p.termArray[bPos].exp;
			temp.newTerm(coef, exp);
		}
		result = result.add(temp);
	}
	return result;
}

void Polynomial:: printPolynomial()
{
	termArray[0].showTerm();
	for (int i = 1; i < terms; i++)
	{
		cout << " + ";
		termArray[i].showTerm();
	}
	cout << endl;
}

void Polynomial:: operator=(const Polynomial& p)							
{
	capacity = p.capacity;
	terms = p.terms;
	delete[] termArray;
	termArray = new Term[p.capacity];
	memcpy(termArray, p.termArray, sizeof(Term)*p.terms);
}

istream &operator>> (istream &is, Polynomial &p)
{
	int coef=0;
	int exp=0;

	while (1)
	{
		is >> coef >> exp;
		p.newTerm(coef, exp);
		if (exp == 0) break;
	}
	return is;
}

ostream &operator<< (ostream &os, Polynomial &p)
{
	p.printPolynomial();
	return os;
}