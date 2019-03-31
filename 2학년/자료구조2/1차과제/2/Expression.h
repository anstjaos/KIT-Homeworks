#pragma once
#include "Token.h"

class Expression {						// 입력된 계산식을 토큰으로 변환해주는 클래스
private:
	Token *tokenArr;
	int capacity;
	int count;

	bool isOperator(char value);
	bool isOperand(char value);
	void changeToken(string formula);	// 입력된 연산식을 토큰 단위로 저장하는 함수
public:
	Expression();
	Expression(const Expression& e);	// 깊은 복사를 위한 복사생성자
	~Expression();

	int getCount() { return count; }
	Token getToken(int index) { return tokenArr[index]; }
	int isp(char value);				// 스택에 저장된 연산자의 우선순위를 return해주는 함수
	int icp(char value);				// 스택에 저장될 연산자의 우선순위를 return해주는 함수

	Expression getPostfix(string formula);	// 후위 연산식을 출력하는 함수
	void insertToken(token value, int type);

	void operator=(const Expression& e);
};