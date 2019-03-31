#pragma once
#include "Stack.h"

class Token {				// �Էµ� ������ ��ū ������ �����ϱ� ���� ������� Ŭ����
private:
	string value;			// ��ū ������ ����
	int type;				// ����� ��ū�� Ÿ�� ����
public:
	Token() {}

	Token(char i_value);
	Token(string i_value);
	Token(string i_value, int i_type);

	string getValue() { return value; }
	int getType() { return type; }
	
	void setType(int i_type) { type = i_type; }
};