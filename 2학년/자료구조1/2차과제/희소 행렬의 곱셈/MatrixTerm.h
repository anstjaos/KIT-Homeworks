#ifndef MATRIXTERM_H
#define MATRIXTERM_H
#include <iostream>
using namespace std;

class SparseMatrix;				// ���� ����
class MatrixTerm {
	friend SparseMatrix;
private:
	int row, col, value;
public:
	int getRow() { return row; }
	int getCol() { return col; }
	int getValue() { return value; }
};
#endif