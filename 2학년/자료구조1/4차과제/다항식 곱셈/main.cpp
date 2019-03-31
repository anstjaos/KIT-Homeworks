/* ---   연결리스트로 구현한 다항식의 곱셈  --- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    211 lines, 작성일: 2017. 5. 27.   --- */

#include "Polynomial.h"

void main()
{
	Polynomial p1;
	Polynomial p2;

	cout << "첫번째 다항식을 계수-지수 쌍으로 입력하세요.(계수나 지수가 0으로 입력되면 종료)" << endl;
	cin >> p1;				// operator>>를 재정의하여 입력받는다.
	cout << "첫번째 다항식을 계수-지수 쌍으로 입력하세요.(계수나 지수가 0으로 입력되면 종료)" << endl;
	cin >> p2;

	p1.multi(p2);			// 다항식의 곱셈
	p1.displayResult();		// 결과 출력
}