/* ---      행렬 회전하는 프로그램      --- */
/* --- 작성자: 김문서, 학번: 20130162   --- */
/* ---  97 lines, 작성일: 2017. 3. 20.  --- */

#include "Matrix.h"		

int main()
{
	Matrix mat,tmpMat;

	cout << "행렬을 채울 16개의 값을 입력하세요 : ";
	cin >> mat;					 // 정수 16개 입력 받아 채우기
	cout << "최초행렬\n" << mat;

	tmpMat = mat.turnRight();	// 행렬 우측 회전
	cout << "우측으로 90도 회전\n" << tmpMat;

	tmpMat = mat.turnLeft();	// 행렬 좌측 회전
	cout << "좌측으로 90도 회전\n" << tmpMat;
}