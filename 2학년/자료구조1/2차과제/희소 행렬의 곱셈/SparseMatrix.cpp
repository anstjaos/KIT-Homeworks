#include "SparseMatrix.h"

SparseMatrix:: SparseMatrix(int i_row, int i_col, int i_terms)			// ������
{
	rows = i_row;
	cols = i_col;
	terms = i_terms;
	capacity = i_terms + 1;
	smArray = new MatrixTerm[capacity];
}

SparseMatrix::SparseMatrix(const SparseMatrix& copy)					// ���� ������
{
	rows = copy.rows;
	cols = copy.cols;
	terms = copy.terms;
	capacity = copy.capacity;
	smArray = new MatrixTerm[copy.capacity];
	memcpy(smArray, copy.smArray, sizeof(MatrixTerm)*copy.terms);
}

SparseMatrix SparseMatrix::fastTranspose()
{
	SparseMatrix b(cols, rows, terms);
	if (terms > 0)
	{
		int *rowSize = new int[cols];

		fill(rowSize, rowSize + cols, 0);
		for (int i = 0; i < terms; i++) rowSize[smArray[i].col]++;		// rowSize�� ã���ش�.

		int temp = 0;
		int startValue = 0;
		for (int i = 1; i < cols; i++)									// for�� �̿��Ͽ� rowSize�� �������� �����Ѵ�.
		{
			startValue = rowSize[i];
			rowSize[i] = rowSize[i - 1] + temp;
			temp = startValue;
		}
		rowSize[0] = 0;													// 0���� �������� 0�̴�.

		for (int i = 0; i < terms; i++)
		{
			int j = rowSize[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			rowSize[smArray[i].col]++;
		}
		delete[] rowSize;
	}
	return b;
}

void SparseMatrix :: storeSum(const int sum, const int row, const int col)
{
	if (sum != 0)
	{
		if (terms == capacity) changeSize(2 * capacity);

		smArray[terms].row = row;
		smArray[terms].col = col;
		smArray[terms++].value = sum;
	}
}

void SparseMatrix::changeSize(const int newSize)						// ��ü �迭�� ���� á�� ��� capacity�� 2��� �÷��ش�.
{
	if (newSize < terms) throw "New size must be >= number of terms";
	MatrixTerm *temp = new MatrixTerm[newSize];
	memcpy(temp, smArray, sizeof(MatrixTerm)*terms);
	delete[] smArray;
	smArray = temp;
	capacity = newSize;
}

SparseMatrix SparseMatrix::multiply(SparseMatrix b)
{
	if (cols != b.rows) throw "Incompatible matrices";
	SparseMatrix bXpose = b.fastTranspose();							// b ����� ��ġ���ش�.
	SparseMatrix result(rows, b.cols,0);								// ��� ���� ��� ��ü ����
	int currRowIndex = 0;
	int currRowBegin = 0;
	int currRowA = smArray[0].row;

	if (terms == capacity) changeSize(terms + 1);
	bXpose.changeSize(bXpose.terms + 1);
	smArray[terms].row = rows;
	bXpose.smArray[b.terms].row = b.cols;
	bXpose.smArray[b.terms].col = -1;
	int sum = 0;

	while (currRowIndex < terms)
	{
		int currColB = bXpose.smArray[0].row;
		int currColIndex = 0;
		while (currColIndex <= b.terms)
		{
			if (smArray[currRowIndex].row != currRowA)
			{
				result.storeSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				while (bXpose.smArray[currColIndex].row == currColB) currColIndex++;

				currColB = bXpose.smArray[currColIndex].row;
			}
			else if (bXpose.smArray[currColIndex].row != currColB)
			{
				result.storeSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else
			{
				if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col) currRowIndex++;
				else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col)
				{
					sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
					currRowIndex++;
					currColIndex++;
				}
				else currColIndex++;
			}
		}
		while (smArray[currRowIndex].row == currRowA) currRowIndex++;

		currRowBegin = currRowIndex;
		currRowA = smArray[currRowIndex].row;
	}
	return result;
}

void SparseMatrix:: operator=(const SparseMatrix& s)					// ���� ���縦 �ϱ� ���� ������ �����ε�
{
	rows = s.rows;
	cols = s.cols;
	terms = s.terms;
	capacity = s.capacity;
	delete[] smArray;
	smArray = new MatrixTerm[s.capacity];
	memcpy(smArray, s.smArray, sizeof(MatrixTerm)*s.terms);
}

istream &operator >> (istream &is, SparseMatrix &s)
{
	int value;
	for (int i = 0; i < s.getRows(); i++)
	{
		for (int j = 0; j < s.getCols(); j++)
		{
			cin >> value;
			s.storeSum(value, i, j);
		}
	}
	return is;
}

ostream &operator<< (ostream &os, SparseMatrix &s)
{
	int index = 0;
	int size = 0;
	int value;
	for (int i = 0; i < s.terms; i++)								// �ڸ����� ���߱� ���� ���� ū �ڸ����� ���Ѵ�.
	{
		int temp = 0;
		value = s.smArray[i].getValue();
		while (value > 0)
		{
			value = value / 10;
			temp++;
		}
		if (temp > size) size = temp;
	}

	for (int i = 0; i < s.getRows(); i++)
	{
		os << "| ";
		for (int j = 0; j < s.getCols(); j++)
		{
			if(s.smArray[index].getRow() == i && s.smArray[index].getCol() == j)
				os << setw(size) << s.smArray[index++].getValue() << " ";
			else os << setw(size) << "0" << " ";
		}
		os << "|" << endl;
	}
	
	return os;
}