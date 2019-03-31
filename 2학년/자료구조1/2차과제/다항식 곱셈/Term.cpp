#include "Term.h"

void Term:: showTerm()
{
	if (exp != 0)								// 계수가 1일때는 부호만 출력한다.
	{
		if (coef == -1) cout << "-";
		else if (coef != 1) cout << coef;
	}

	switch (exp)								// 지수 값에 따라 출력 결과가 달라진다.
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