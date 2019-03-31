#pragma once
#include "Token.h"

class Expression {						// �Էµ� ������ ��ū���� ��ȯ���ִ� Ŭ����
private:
	Token *token;
	int capacity;
	int count;

	bool isOperator(string value);
	bool isOperand(string value);
	void changeToken(string formula);	// �Էµ� ������� ��ū ������ �����ϴ� �Լ�
public:
	Expression();
	Expression(const Expression& e);	// ���� ���縦 ���� ���������
	~Expression();

	int getCount() { return count; }
	Token getToken(int index) { return token[index]; }
	int isp(string value);				// ���ÿ� ����� �������� �켱������ return���ִ� �Լ�
	int icp(string value);				// ���ÿ� ����� �������� �켱������ return���ִ� �Լ�

	Expression getPostfix(string formula);	// ���� ������� ����ϴ� �Լ�
	void insertToken(string value, int type);

	void operator=(const Expression& e);
};