#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int korScore;
	int engScore;
	int mathScore;
	float average;
	string grade;

	string findGrade();
public:
	Person() {}
	Person(string i_name, int i_korScore, int i_engScore, int i_mathScore);

	string getName() { return name; }
	int getKorScore() { return korScore; }
	int getEngScore() { return engScore; }
	int getMathScore() { return mathScore; }
	float getAverage() { return average; }
	string getGrade() { return grade; }
};