#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Term			// ���׽��� ��Ÿ���� ����ü
{
	int coef;
	int exp;
	Term set(int i_coef, int i_exp) { coef = i_coef; exp = i_exp; return *this; };		// ����ü set�Լ�
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