#pragma once
#include <iostream>
#include <string>
using namespace std;

#define OPERAND 0
#define OPERATOR 1
#define BIOPERATOR 2
#define CHECK 3

class Exception				// 예외 처리를 담당하는 클래스
{
private:
	string error;
public:
	Exception(string msg) { error = msg; }
	void putError() { cout << error << endl << endl; }
};