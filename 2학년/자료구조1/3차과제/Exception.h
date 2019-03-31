#pragma once
#include <iostream>
#include <string>

#define Operator 0			// 토큰의 타입을 구분하기 위해서 선언함.
#define BiOperator 1
#define Operand 2
#define Check 3

using namespace std;

class Exception				// 예외 처리를 담당하는 클래스
{
private:
	string error;
public:
	Exception(string msg) { error = msg; }
	void putError() { cout << error << endl << endl; }
};