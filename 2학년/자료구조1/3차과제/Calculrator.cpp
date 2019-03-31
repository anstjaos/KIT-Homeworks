#include "Calculrator.h"

void Calculrator::calculration(Expression e)		// 매개변수로 후위표기식을 저장한 객체를 받는다.
{
	Token value;

	int rightValue;
	int leftValue;
	int result;

	Stack<Token> stack;
	stack.push('#');

	for (int i = 0; i < e.getCount(); i++)
	{
		result = 0;
		value = e.getToken(i);
		if (value.getType() == Operand) stack.push(value);
		else
		{
			switch (e.isp(value.getValue()))
			{
			case 1:
				if (value.getValue() == "~")
				{
					result = stoi(stack.getTop().getValue()) * (-1);
					stack.pop();

					stack.push(to_string(result));
				}
				else if (value.getValue() == "!")
				{
					if (stack.getTop().getValue() == "0")
					{
						stack.pop();
						
						Token t("1");
						stack.push(t);
					}
					else if (stack.getTop().getValue() == "1")
					{
						stack.pop();

						Token t("0");
						stack.push(t);
					}
					else throw Exception("[오류] 단항 연산자 '!' 뒤에 1, 0이외의 값이 입력됨!");
				}
				break;
			case 2:			// 제곱 연산자 '^'
			{
				rightValue = stoi(stack.getTop().getValue());
				stack.pop();

				leftValue = stoi(stack.getTop().getValue());
				stack.pop();

				result = 1;
				if (rightValue < 0) throw Exception("[오류] 제곱의 두 번째 연산자가 음수인 경우 발생!");
				else
				{
					for (int i = 0; i < rightValue; i++)
					{
						result *= leftValue;
					}
				}
				stack.push(to_string(result));
				break;
			}
			case 3:			// 곱셈, 나눗셈, 나머지 연산자
				if (value.getValue() == "*")
				{
					rightValue = stoi(stack.getTop().getValue());
					stack.pop();

					leftValue = stoi(stack.getTop().getValue());
					stack.pop();

					result = leftValue * rightValue;
		
					stack.push(to_string(result));
				}
				else if (value.getValue() == "/")
				{
					rightValue = stoi(stack.getTop().getValue());
					stack.pop();

					leftValue = stoi(stack.getTop().getValue());
					stack.pop();

					if (rightValue == 0) throw Exception("[오류] 나누기 우측 연산자가 0인 경우 발생");

					result = leftValue / rightValue;
					stack.push(to_string(result));
				}
				else if (value.getValue() == "%")
				{
					rightValue = stoi(stack.getTop().getValue());
					stack.pop();

					leftValue = stoi(stack.getTop().getValue());
					stack.pop();

					if (rightValue == 0) throw Exception("[오류] 퍼센트 우측 연산자가 0인 경우 발생");

					result = leftValue % rightValue;
					stack.push(to_string(result));
				}
				break;
			case 4:			// 덧셈, 뺄셈 연산자
				if (value.getValue() == "+")
				{
					rightValue = stoi(stack.getTop().getValue());
					stack.pop();

					leftValue = stoi(stack.getTop().getValue());
					stack.pop();

					result = leftValue + rightValue;
					stack.push(to_string(result));
				}
				else if (value.getValue() == "-")
				{
					rightValue = stoi(stack.getTop().getValue());
					stack.pop();

					leftValue = stoi(stack.getTop().getValue());
					stack.pop();

					result = leftValue - rightValue;
					stack.push(to_string(result));
				}
				break;
			default:
				break;
			}
		}
	}
	result = stoi(stack.getTop().getValue());
	cout << "---- 결과값은 " << result << endl << endl;
}