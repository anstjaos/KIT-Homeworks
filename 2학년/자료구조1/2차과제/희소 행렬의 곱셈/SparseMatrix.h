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
	SparseMatrix() {}											// default 생성자
	SparseMatrix(int i_row, int i_col,int i_terms);				// 생성자
	SparseMatrix(const SparseMatrix& copy);						// 복사 생성자
	~SparseMatrix() { delete[] smArray; }						// 소멸자를 이용한 객체 배열 동적 할당해제

	int getRows() { return rows; }
	int getCols() { return cols; }

	SparseMatrix fastTranspose();
	void storeSum(const int sum, const int row, const int col);
	void changeSize(const int newSize);
	SparseMatrix multiply(SparseMatrix b);

	void operator=(const SparseMatrix& s);						// = 연산자 오버로딩
	friend istream &operator >> (istream &is, SparseMatrix &s);	// >>연산자 오버로딩
	friend ostream &operator<< (ostream &os, SparseMatrix &s);	// <<연산자 오버로딩
};
#endif