#pragma once
#include "Stack.h"

union token {
	int value;
	char oper;
};

class Token {				// 입력된 계산식을 토큰 단위로 저장하기 위해 만들어진 클래스
private:
	token data;				// 토큰 단위로 저장
	int type;				// 저장된 토큰의 타입 구분
public:
	Token() {}

	Token(token i_data, int i_type);

	token getData() { return data; }
	int getType() { return type; }
	
	void setData(token i_data) { data = i_data; }
	void setType(int i_type) { type = i_type; }
};