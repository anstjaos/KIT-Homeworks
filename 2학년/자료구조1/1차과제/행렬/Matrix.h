#pragma once

#include <iostream>
#include <iomanip>				//setw() �Լ��� ��������

using namespace std;

const int SIZE = 4;

class Matrix {
	int arr[SIZE][SIZE];
public:
	Matrix() {};
	Matrix turnRight();				//�迭�� �������� ȸ��
	Matrix turnLeft();				//�迭�� �������� ȸ��
	
	friend ostream &operator<<(ostream &, Matrix &);		//��ü�� ����ϱ� ���� ������ �����ε�
	friend istream &operator>>(istream &, Matrix &);		//��ü�� �Է¹ޱ� ���� ������ �����ε�
};