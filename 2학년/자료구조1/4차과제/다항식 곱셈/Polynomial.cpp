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
	// 소멸자가 호출되기 전 first는 결과 연결리스트를 가리키고, 
	// result 객체의 first는 원래의 연결리스트를 가리키게하여 원래 노드들이 소멸된다.
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
		if (ptr->data.exp == bPtr->data.exp)			// 지수가 같을 경우
		{
			int sum = ptr->data.coef + bPtr->data.coef;
			if (sum) c.insertNode(temp.set(sum, ptr->data.exp));
			
			ptr = ptr->link;
			bPtr = bPtr->link;							// 둘다 한칸씩 이동
		}
		else if (ptr->data.exp < bPtr->data.exp)		// b 객체의 지수가 더 클 경우
		{
			c.insertNode(temp.set(bPtr->data.coef, bPtr->data.exp));
			bPtr = bPtr->link;
		}
		else											// this 객체의 지수가 더 클 경우
		{
			c.insertNode(temp.set(ptr->data.coef, ptr->data.exp));
			ptr = ptr->link;
		}
	}
	// 아직 덧셈이 안된 노드들을 모두 결과 연결리스트에 삽입해준다.
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
	// 소멸자가 호출되기 전 first는 결과 연결리스트를 가리키고, 
	// c 객체의 first는 원래의 연결리스트를 가리키게하여 원래 노드들이 소멸된다.
	ptr = first;
	setFirst(c.first);
	c.setFirst(ptr);
}

void Polynomial::displayResult()
{
	cout << "두 다항식의 곱은 : ";
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.exp != 0)								// 계수가 1일때는 부호만 출력한다.
		{
			if (ptr->data.coef == -1) cout << "-";
			else if (ptr->data.coef != 1) cout << ptr->data.coef;
		}

		switch (ptr->data.exp)								// 지수 값에 따라 출력 결과가 달라진다.
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

istream &operator >> (istream &is, Polynomial &p)			// 객체 입력을 위한 연산자 오버로딩
{
	int coef = 0;
	int exp = 0;

	while (1)
	{
		is >> coef >> exp;
		if (coef == 0) break;			// 계수가 0 일 때 더이상 받지않고 종료
		Term t;
		t.set(coef, exp);
		p.insertNode(t);
		if (exp == 0) break;			// 지수가 0일 때 종료
	}
	return is;
}