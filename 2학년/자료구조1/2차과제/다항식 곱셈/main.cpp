/* ---     다항식 곱셈하는 프로그램     --- */
/* --- 작성자: 김문서, 학번: 20130162   --- */
/* ---  203 lines, 작성일: 2017. 4. 09. --- */

#include "Polynomial.h"

void main()
{
	Polynomial p1;
	Polynomial p2;
	Polynomial result;
	cout << "첫번째 다항식을 계수-지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)" << endl;
	cin >> p1;																			// 연산자 오버로딩을 이용한 객체 입력
	cout << "두번째 다항식을 계수 - 지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)" << endl;
	cin >> p2;																			// 연산자 오버로딩을 이용한 객체 입력
	cout << "두 다항식의 곱은 : ";
	result = p1.multi(p2);																// 연산자 오버로딩을 이용한 객체 복사
	cout << result;																		// 연산자 오버로딩을 이용한 객체 출력
}