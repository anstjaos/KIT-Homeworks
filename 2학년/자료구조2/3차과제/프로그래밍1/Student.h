#pragma once
#include <iostream>
using namespace std;

class Student {			// �л� ��ü Ŭ����
private:
	int studentNum;
	int korScore;
	int engScore;
	int mathScore;
public:
	Student() {}
	Student(int i_studentNum, int i_korScore, int i_engScore, int i_mathScore);

	~Student() {}

	bool operator<(const Student& s);				// < ������ �����ε�
	bool operator<=(const Student& s);				// <= ������ �����ε�
	int getStudentNum() { return studentNum; }
};