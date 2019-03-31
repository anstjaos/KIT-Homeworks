#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Term			// 다항식을 나타내는 구조체
{
	int coef;
	int exp;
	Term set(int i_coef, int i_exp) { coef = i_coef; exp = i_exp; return *this; };		// 구조체 set함수
};

class Polynomial;
class ChainNode
{
	friend class Polynomial;
private:
	Term data;
	ChainNode *link;
public:
	ChainNode(Term i_data, ChainNode *next);
};