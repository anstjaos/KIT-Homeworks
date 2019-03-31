#include "Polynomial.h"

Polynomial:: Polynomial()													// default ������
{
	capacity = 1;
	terms = 0;
	termArray = new Term[capacity];
}

Polynomial::Polynomial(const Polynomial& copy)								// ���� ������
{																			// �Լ��� ������ �ڵ����� �Ҹ��ڰ� ȣ��Ǿ�
	capacity = copy.capacity;												// ��ü�� �Ҹ�ǹǷ� ���� �����ڸ� �����Ͽ���.
	terms = copy.terms;
	termArray = new Term[copy.capacity];
	memcpy(termArray, copy.termArray, sizeof(Term)*copy.terms);
}

void Polynomial::newTerm(const int theCoef, const int theExp)
{
	if (terms == capacity)													// ���� �Ҵ��� ��ü �迭�� ���� á�� ���
	{																		// capacity�� 2��� �ø��� ���� ��ü�� delete�ϰ�
		capacity *= 2;														// ���ο� ��ü�� ����Ű�� �Ѵ�.
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
		if ((termArray[aPos].exp == b.termArray[bPos].exp))					// ������ ���� ��� ������� ���Ͽ� ���� �����Ѵ�.
		{
			int coef = termArray[aPos].coef + b.termArray[bPos].coef;
			if (coef != 0) c.newTerm(coef, termArray[aPos].exp);
			aPos++;
			bPos++;
		}
		else if ((termArray[aPos].exp < b.termArray[bPos].exp))				// b�� ������ �� Ŭ ��� b�� ����� ������ �����Ѵ�.
		{
			c.newTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else																// ȣ���� ��ü�� ������ �� Ŭ ��� 
		{																	// ��ü�� ����� ������ �����Ѵ�.
			c.newTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	for (; aPos < terms; aPos++)											// ���� �����ִ� ����� ������ �����Ѵ�.
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
	Polynomial result;														// ���� ������ ��ü�� �����Ѵ�.
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