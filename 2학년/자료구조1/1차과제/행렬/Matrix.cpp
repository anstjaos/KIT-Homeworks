#include "Matrix.h"

Matrix Matrix::turnRight()				//�迭�� �������� ȸ��
{
	Matrix mat;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			mat.arr[j][SIZE - i - 1] = arr[i][j];
		}
	}
	return mat;
}

Matrix Matrix::turnLeft()				//�迭�� �������� ȸ��
{
	Matrix mat;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			mat.arr[SIZE - j - 1][i] = arr[i][j];
		}
	}
	return mat;
}

ostream &operator<<(ostream &out, Matrix &mat)		//��ü�� ����ϱ� ���� ������ �����ε�
{
	for (int i = 0; i < SIZE; i++)
	{
		out << "| ";
		for (int j = 0; j < SIZE; j++)
		{
			out.setf(ios::right);
			out << setw(3) << mat.arr[i][j];
		}
		out << " |" << endl;
	}
	return out;
}

istream &operator>>(istream &in, Matrix &mat)		//��ü�� �Է¹ޱ� ���� ������ �����ε�
{
	int num;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			in >> num;
			mat.arr[i][j] = num;
		}
	}
	return in;
}