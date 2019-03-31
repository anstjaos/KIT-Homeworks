#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "MatrixTerm.h"
#include <iomanip>

class SparseMatrix
{
private:
	int rows, cols, terms, capacity;
	MatrixTerm *smArray;
public:
	SparseMatrix() {}											// default ������
	SparseMatrix(int i_row, int i_col,int i_terms);				// ������
	SparseMatrix(const SparseMatrix& copy);						// ���� ������
	~SparseMatrix() { delete[] smArray; }						// �Ҹ��ڸ� �̿��� ��ü �迭 ���� �Ҵ�����

	int getRows() { return rows; }
	int getCols() { return cols; }

	SparseMatrix fastTranspose();
	void storeSum(const int sum, const int row, const int col);
	void changeSize(const int newSize);
	SparseMatrix multiply(SparseMatrix b);

	void operator=(const SparseMatrix& s);						// = ������ �����ε�
	friend istream &operator >> (istream &is, SparseMatrix &s);	// >>������ �����ε�
	friend ostream &operator<< (ostream &os, SparseMatrix &s);	// <<������ �����ε�
};
#endif