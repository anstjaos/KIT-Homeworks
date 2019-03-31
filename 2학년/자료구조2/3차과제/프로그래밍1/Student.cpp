#include "Student.h"

Student::Student(int i_studentNum, int i_korScore, int i_engScore, int i_mathScore)
{
	studentNum = i_studentNum;
	korScore = i_korScore;
	engScore = i_engScore;
	mathScore = i_mathScore;
}

bool Student ::operator<(const Student& s)
{
	double average = (korScore + engScore + mathScore) / 3.0;
	double sAverage = (s.korScore + s.engScore + s.mathScore) / 3.0;

	if (average < sAverage) return true;
	else return false;
}

bool Student ::operator<=(const Student& s)
{
	double average = (korScore + engScore + mathScore) / 3.0;
	double sAverage = (s.korScore + s.engScore + s.mathScore) / 3.0;

	if (average <= sAverage) return true;
	else return false;
}