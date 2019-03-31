#include "Term.h"

void Term:: showTerm()
{
	if (exp != 0)								// ����� 1�϶��� ��ȣ�� ����Ѵ�.
	{
		if (coef == -1) cout << "-";
		else if (coef != 1) cout << coef;
	}

	switch (exp)								// ���� ���� ���� ��� ����� �޶�����.
	{
	case 0:
		cout << coef;
		break;
	case 1:
		cout << "x";
		break;
	default:
		cout << "x^" << exp;
		break;
	}
}