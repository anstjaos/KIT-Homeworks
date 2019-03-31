/* ---    희소행렬 곱셈하는 프로그램    --- */
/* --- 작성자: 김문서, 학번: 20130162   --- */
/* ---  251 lines, 작성일: 2017. 4. 12. --- */

#include "SparseMatrix.h"

void main()
{	
	int m, n, p;
	SparseMatrix result;
	cout << "곱할 행렬이 mxn 와 nxp 크기일 때, m과 n과 p의 값을 순서대로 입력하세요 ";
	cin >> m >> n >> p;
	SparseMatrix s1(m,n,0);
	SparseMatrix s2(n,p,0);
	cout << "첫번째 행렬의 " << m*n << "개 값을 행우선으로 입력하세요 : ";
	cin >> s1;																			// 연산자 오버로딩을 이용한 객체 입력
	cout << "두번째 행렬의 " << n*p << "개 값을 행우선으로 입력하세요 : ";
	cin >> s2;																			// 연산자 오버로딩을 이용한 객체 입력
	result = s1.multiply(s2);															// 연산자 오버로딩을 이용한 객체 복사
	cout << result;																		// 연산자 오버로딩을 이용한 객체 출력
}