#include "Person.h"

string Person::findGrade()
{
	if (average >= 90)
		return "A";
	else if (80 <= average && average < 90)
		return "B";
	else if (70 <= average && average < 80)
		return "C";
	else if (60 <= average && average < 70)
		return "D";
	else return "F";
}

Person :: Person(string i_name, int i_korScore, int i_engScore, int i_mathScore)
{
	name = i_name;
	korScore = i_korScore;
	engScore = i_engScore;
	mathScore = i_mathScore;
	average = (float)(i_korScore + i_engScore + i_mathScore) / 3;
	grade = findGrade();
}