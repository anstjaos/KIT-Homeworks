#pragma once

#include <iostream>
#include <iomanip>				//setw() 함수를 쓰기위함

using namespace std;

const int SIZE = 4;

class Matrix {
	int arr[SIZE][SIZE];
public:
	Matrix() {};
	Matrix turnRight();				//배열을 우측으로 회전
	Matrix turnLeft();				//배열을 좌측으로 회전
	
	friend ostream &operator<<(ostream &, Matrix &);		//객체를 출력하기 위한 연산자 오버로딩
	friend istream &operator>>(istream &, Matrix &);		//객체를 입력받기 위한 연산자 오버로딩
};