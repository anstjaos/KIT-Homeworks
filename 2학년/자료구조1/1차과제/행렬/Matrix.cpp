#include "Matrix.h"

Matrix Matrix::turnRight()				//배열을 우측으로 회전
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

Matrix Matrix::turnLeft()				//배열을 좌측으로 회전
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

ostream &operator<<(ostream &out, Matrix &mat)		//객체를 출력하기 위한 연산자 오버로딩
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

istream &operator>>(istream &in, Matrix &mat)		//객체를 입력받기 위한 연산자 오버로딩
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