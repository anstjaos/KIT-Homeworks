#pragma once
#include "Stack.h"

class Token {				// 입력된 계산식을 토큰 단위로 저장하기 위해 만들어진 클래스
private:
	string value;			// 토큰 단위로 저장
	int type;				// 저장된 토큰의 타입 구분
public:
	Token() {}

	Token(char i_value);
	Token(string i_value);
	Token(string i_value, int i_type);

	string getValue() { return value; }
	int getType() { return type; }
	
	void setType(int i_type) { type = i_type; }
};