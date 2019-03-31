#pragma once
#include "Stack.h"

union token {
	int value;
	char oper;
};

class Token {				// �Էµ� ������ ��ū ������ �����ϱ� ���� ������� Ŭ����
private:
	token data;				// ��ū ������ ����
	int type;				// ����� ��ū�� Ÿ�� ����
public:
	Token() {}

	Token(token i_data, int i_type);

	token getData() { return data; }
	int getType() { return type; }
	
	void setData(token i_data) { data = i_data; }
	void setType(int i_type) { type = i_type; }
};