#ifndef TERM_H
#define TERM_H
#include <iostream>
using namespace std;

class Polynomial;
class Term
{
	friend Polynomial;
private:
	int coef;			// 계수
	int exp;			// 지수
public:
	Term() {};

	void showTerm();	// 출력을 담당하는 함수
};
#endif