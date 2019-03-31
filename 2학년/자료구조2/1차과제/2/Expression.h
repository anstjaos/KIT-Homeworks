#pragma once
#include "Token.h"

class Expression {						// �Էµ� ������ ��ū���� ��ȯ���ִ� Ŭ����
private:
	Token *tokenArr;
	int capacity;
	int count;

	bool isOperator(char value);
	bool isOperand(char value);
	void changeToken(string formula);	// �Էµ� ������� ��ū ������ �����ϴ� �Լ�
public:
	Expression();
	Expression(const Expression& e);	// ���� ���縦 ���� ���������
	~Expression();

	int getCount() { return count; }
	Token getToken(int index) { return tokenArr[index]; }
	int isp(char value);				// ���ÿ� ����� �������� �켱������ return���ִ� �Լ�
	int icp(char value);				// ���ÿ� ����� �������� �켱������ return���ִ� �Լ�

	Expression getPostfix(string formula);	// ���� ������� ����ϴ� �Լ�
	void insertToken(token value, int type);

	void operator=(const Expression& e);
};