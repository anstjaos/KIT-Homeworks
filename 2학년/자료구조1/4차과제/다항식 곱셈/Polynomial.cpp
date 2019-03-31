#include "Polynomial.h"

Polynomial :: Polynomial()
{
	first = 0;
	last = first;
}

Polynomial :: ~Polynomial()
{
	ChainNode *temp = first;
	last = NULL;

	while (temp)
	{
		first = temp;
		temp = temp->link;
		delete first;
	}
}

void Polynomial::insertNode(Term t)
{
	if (first)
	{
		last->link = new ChainNode(t, 0);
		last = last->link;
	}
	else first = last = new ChainNode(t, 0);
}

void Polynomial :: multi(const Polynomial &b) 
{
	Polynomial result;
	Term t;

	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		Polynomial temp;
		for (ChainNode *bPtr = b.first; bPtr != 0; bPtr = bPtr->link)
		{
			int coef = ptr->data.coef * bPtr->data.coef;
			int exp = ptr->data.exp + bPtr->data.exp;
			t.set(coef, exp);
			temp.insertNode(t);
		}
		result.add(temp);
	}
	// �Ҹ��ڰ� ȣ��Ǳ� �� first�� ��� ���Ḯ��Ʈ�� ����Ű��, 
	// result ��ü�� first�� ������ ���Ḯ��Ʈ�� ����Ű���Ͽ� ���� ������ �Ҹ�ȴ�.
	ChainNode *ptr = first;
	setFirst(result.first);
	result.setFirst(ptr);
}

void Polynomial :: add(const Polynomial& b)
{
	Term temp;
	Polynomial c;

	ChainNode *ptr = first;
	ChainNode *bPtr = b.first;

	while (ptr && bPtr)
	{
		if (ptr->data.exp == bPtr->data.exp)			// ������ ���� ���
		{
			int sum = ptr->data.coef + bPtr->data.coef;
			if (sum) c.insertNode(temp.set(sum, ptr->data.exp));
			
			ptr = ptr->link;
			bPtr = bPtr->link;							// �Ѵ� ��ĭ�� �̵�
		}
		else if (ptr->data.exp < bPtr->data.exp)		// b ��ü�� ������ �� Ŭ ���
		{
			c.insertNode(temp.set(bPtr->data.coef, bPtr->data.exp));
			bPtr = bPtr->link;
		}
		else											// this ��ü�� ������ �� Ŭ ���
		{
			c.insertNode(temp.set(ptr->data.coef, ptr->data.exp));
			ptr = ptr->link;
		}
	}
	// ���� ������ �ȵ� ������ ��� ��� ���Ḯ��Ʈ�� �������ش�.
	while (ptr)
	{
		c.insertNode(temp.set(ptr->data.coef, ptr->data.exp));
		ptr = ptr->link;
	}
	while (bPtr)
	{
		c.insertNode(temp.set(bPtr->data.coef, bPtr->data.exp));
		bPtr = bPtr->link;
	}
	// �Ҹ��ڰ� ȣ��Ǳ� �� first�� ��� ���Ḯ��Ʈ�� ����Ű��, 
	// c ��ü�� first�� ������ ���Ḯ��Ʈ�� ����Ű���Ͽ� ���� ������ �Ҹ�ȴ�.
	ptr = first;
	setFirst(c.first);
	c.setFirst(ptr);
}

void Polynomial::displayResult()
{
	cout << "�� ���׽��� ���� : ";
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.exp != 0)								// ����� 1�϶��� ��ȣ�� ����Ѵ�.
		{
			if (ptr->data.coef == -1) cout << "-";
			else if (ptr->data.coef != 1) cout << ptr->data.coef;
		}

		switch (ptr->data.exp)								// ���� ���� ���� ��� ����� �޶�����.
		{
		case 0:
			cout << ptr->data.coef;
			break;
		case 1:
			cout << "x";
			break;
		default:
			cout << "x^" << ptr->data.exp;
			break;
		}
		if (ptr->link == 0) cout << endl;
		else cout << " + ";
	}
}

istream &operator >> (istream &is, Polynomial &p)			// ��ü �Է��� ���� ������ �����ε�
{
	int coef = 0;
	int exp = 0;

	while (1)
	{
		is >> coef >> exp;
		if (coef == 0) break;			// ����� 0 �� �� ���̻� �����ʰ� ����
		Term t;
		t.set(coef, exp);
		p.insertNode(t);
		if (exp == 0) break;			// ������ 0�� �� ����
	}
	return is;
}