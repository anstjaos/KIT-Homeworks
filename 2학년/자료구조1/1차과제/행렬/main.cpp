/* ---      ��� ȸ���ϴ� ���α׷�      --- */
/* --- �ۼ���: �蹮��, �й�: 20130162   --- */
/* ---  97 lines, �ۼ���: 2017. 3. 20.  --- */

#include "Matrix.h"		

int main()
{
	Matrix mat,tmpMat;

	cout << "����� ä�� 16���� ���� �Է��ϼ��� : ";
	cin >> mat;					 // ���� 16�� �Է� �޾� ä���
	cout << "�������\n" << mat;

	tmpMat = mat.turnRight();	// ��� ���� ȸ��
	cout << "�������� 90�� ȸ��\n" << tmpMat;

	tmpMat = mat.turnLeft();	// ��� ���� ȸ��
	cout << "�������� 90�� ȸ��\n" << tmpMat;
}