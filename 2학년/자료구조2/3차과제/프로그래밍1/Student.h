#pragma once
#include <iostream>
using namespace std;

class Student {			// 학생 개체 클래스
private:
	int studentNum;
	int korScore;
	int engScore;
	int mathScore;
public:
	Student() {}
	Student(int i_studentNum, int i_korScore, int i_engScore, int i_mathScore);

	~Student() {}

	bool operator<(const Student& s);				// < 연산자 오버로딩
	bool operator<=(const Student& s);				// <= 연산자 오버로딩
	int getStudentNum() { return studentNum; }
};