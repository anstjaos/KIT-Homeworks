#pragma once
#include <iostream>
#include <string>

#define Operator 0			// ��ū�� Ÿ���� �����ϱ� ���ؼ� ������.
#define BiOperator 1
#define Operand 2
#define Check 3

using namespace std;

class Exception				// ���� ó���� ����ϴ� Ŭ����
{
private:
	string error;
public:
	Exception(string msg) { error = msg; }
	void putError() { cout << error << endl << endl; }
};