#include "Expression.h"

Expression::Expression()
{
	capacity = 4;
	count = 0;
	tokenArr = new Token[capacity];
}

Expression::Expression(const Expression& e)
{
	capacity = e.capacity;
	count = e.count;
	tokenArr = new Token[capacity];

	copy(e.tokenArr, e.tokenArr + count, tokenArr);
}

Expression :: ~Expression()
{
	delete[] tokenArr;
}

bool Expression::isOperator(char value)
{
	if (value == '(' || value == '-' || value == '!' || value == '*' || value == '/' || value == '%'
		|| value == '+' || value == ')' || value == '^' || value == '~')
		return true;
	else return false;
}

bool Expression::isOperand(char value)
{
	if ('0' <= value && value <= '9') return true;
	else return false;
}

int Expression::isp(char value)			// In Stack Priority
{
	if (value == '(') return 6;
	else if (value == '~' || value == '!') return 1;
	else if (value == '^') return 2;
	else if (value == '*' || value == '/' || value == '%') return 3;
	else if (value == '+' || value == '-') return 4;
	else return 5;
}

int Expression::icp(char value)			// In Coming Priority
{
	if (value == '(') return 0;
	else if (value == '~' || value == '!') return 1;
	else if (value == '^') return 2;
	else if (value == '*' || value == '/' || value == '%') return 3;
	else if (value == '+' || value == '-') return 4;
	else return 5;
}

void Expression::changeToken(string formula)
{
	bool checkError;							// 괄호의 짝을 맞추기 위한 변수
	char curValue;
	char preValue = ' ';						// 공백을 무시하기 위해 그 전 토큰 저장
	int number;
	int length = formula.length();
	
	for (int i = 0; i < length; i++)
	{
		union token temp;
		curValue = formula[i];
		checkError = true;
		if (curValue == ' ') continue;				// 공백은 무시한다.
		else if (curValue == ')')
		{
			for (int j = 0; j < count; j++)
			{
				if (tokenArr[j].getData().oper == '(')
				{
					if (tokenArr[j].getType() == CHECK) continue;
					else
					{
						preValue = curValue;
						tokenArr[j].setType(CHECK);		// 짝이 맞은 괄호는 type을 Check로 변경시켜준다.
						temp.oper = curValue;
						insertToken(temp , OPERATOR);
						checkError = false;
						break;
					}
				}
			}

			if (checkError == true) throw Exception("잘못된 값을 입력하셨습니다!");		// 짝이 안맞는 괄호가 들어왔을 경우 예외처리
		}
		else if (i == length - 1 && isOperator(curValue))	throw Exception("식의 마지막에는 연산자가 올 수 없습니다!");
		else if (isOperand(curValue))
		{
			if (preValue == ' ')		// 처음 들어오는 토큰이 피연산자이면 저장
			{
				temp.value = curValue -'0';
				insertToken(temp, OPERAND);
			}
			else if (tokenArr[count - 1].getType() == OPERAND)				// 전 토큰이 피연산자일 경우 하나의 숫자로 본다.
			{
				if (formula[i - 1] == ' ')
					throw Exception("[오류] 피연산자 사이에는 공백이 올 수 없습니다!");

				count--;
				number = tokenArr[count].getData().value * 10 + (curValue-'0');
				temp.value = number;
				insertToken(temp, OPERAND);
			}
			else if (preValue == '!')
			{
				temp.oper = curValue;
				insertToken(temp, OPERAND);
			}
			else if (preValue == ')')
				throw Exception("[오류] 닫는 괄호 다음에 바로 피연산자가 올 수 없습니다!");
			else
			{
				temp.value = curValue - '0';
				insertToken(temp, OPERAND);
			}
			preValue = curValue - '0';
		}
		else if (isOperator(curValue))
		{
			if (preValue == ' ')
			{
				if (curValue == '-')			// '-'를 단항 연산자로 인식하고 '~'로 변경
				{
					temp.oper = '~';
					insertToken(temp, BIOPERATOR);
					preValue = '~';
				}
				else if (curValue == '!')
				{
					temp.oper = '!';
					insertToken(temp , BIOPERATOR);
					preValue = curValue;
				}
				else if (curValue == '(')
				{
					temp.oper = '(';
					insertToken(temp, OPERATOR);
					preValue = curValue;
				}
				else throw Exception("[오류] 이항 연산자는 제일 먼저 올 수 없습니다!");
			}
			else if (isOperator(preValue) && preValue != ')' && curValue == '-')
			{
				temp.oper = '~';
				insertToken(temp, BIOPERATOR);
				preValue = '~';
			}
			else if (curValue == '!')
			{
				if (preValue == ')' || isOperand(preValue)) throw Exception("[오류] 이해할 수 없는 수식");

				temp.oper = curValue;
				insertToken(temp, BIOPERATOR);
				preValue = curValue;
			}
			else if (isp(preValue) == 1 && icp(curValue) != 1)		// '-' 는 if문에서 걸러진다.
				throw Exception("[오류] 단항 연산자 다음으로 이항 연산자가 올 수 없습니다!");
			else if (isOperator(preValue) && preValue != ')' && curValue != '(')
				throw Exception("[오류] 이해할 수 없는 수식");
			else if (preValue == ')' && curValue == '(')
				throw Exception("[오류] 이해할 수 없는 수식");
			else if (isOperand(preValue) && curValue == '(')
				throw Exception("[오류] 피연산자 다음으로 여는 괄호가 올 수 없습니다!");
			else
			{
				temp.oper = curValue;
				insertToken(temp, OPERATOR);
				preValue = curValue;
			}

		}
		else throw Exception("[오류] 잘못된 값을 입력하셨습니다!");
	}

	for (int i = 0; i < count; i++)			// 여는 괄호만 저장되었는지 체크
	{
		if (tokenArr[i].getData().oper == '(' && tokenArr[i].getType() != CHECK)
		{
			throw Exception("[오류] 잘못된 값을 입력하셨습니다!");
		}
	}
}

Expression Expression::getPostfix(string formula)
{
	Expression ex;
	changeToken(formula);					// 입력된 식을 토큰 단위로 나눠준다.
	Stack<Token> stack;
	int operand = 0;

	cout << "--- 후위 계산식은 : ";

	for (int i = 0; i < count; i++)
	{
		//Token tempToken = stack.getTop();
		if (tokenArr[i].getType() == OPERAND)		// 피연산자일 경우 출력
		{
			cout << tokenArr[i].getData().value << " ";
			ex.insertToken(tokenArr[i].getData(), OPERAND);
		}
		else if (tokenArr[i].getData().oper == ')')
		{
			for (int j = stack.getIndex(); j >= 0; j--)
			{
				if (stack.getTop().getData().oper == '(') break;

				if (stack.getTop().getType() == OPERAND)
				{
					cout << stack.getTop().getData().value << " ";
					ex.insertToken(stack.getTop().getData(), OPERAND);
				}
				else
				{
					cout << stack.getTop().getData().oper << " ";
					ex.insertToken(stack.getTop().getData(), OPERATOR);
				}
				
				stack.pop();
			}
			stack.pop();						// '('을 pop해준다.
		}
		else
		{
			if (stack.isEmpty()) stack.push(tokenArr[i]);		// 스택에 아무것도 들어있지 않을 경우 push
			else if (isp(stack.getTop().getData().oper) > icp(tokenArr[i].getData().oper))	stack.push(tokenArr[i]);	// 스택에 있는 연산자의 우선 순위가 더 클 경우
			else									// 스택에 있는 연산자의 우선 순위가 작거나 같을 때
			{
				if (stack.getTop().getType() == BIOPERATOR && tokenArr[i].getType() == BIOPERATOR) stack.push(tokenArr[i]);	// 단항 연산자인 경우
				else
				{
					while (!stack.isEmpty())
					{
						if (isp(stack.getTop().getData().oper) <= icp(tokenArr[i].getData().oper))
						{
							cout << stack.getTop().getData().oper << " ";
							ex.insertToken(stack.getTop().getData(), OPERATOR);
							stack.pop();
						}
						else break;
					}
					stack.push(tokenArr[i]);
				}
			}
		}
	}

	for (int j = stack.getIndex(); j >=0; j--)				// 스택에 남아있는 연산자를 모두 출력한다.
	{
		cout << stack.getTop().getData().oper << " ";
		ex.insertToken(stack.getTop().getData(), OPERATOR);
		stack.pop();
	}
	cout << endl;
	return ex;
}

void Expression::insertToken(token value, int type)
{
	if (count == capacity - 1)
	{
		capacity *= 2;
		Token *temp = new Token[capacity];
		copy(tokenArr, tokenArr + count, temp);
		delete[] tokenArr;
		tokenArr = temp;
	}
	Token t(value, type);
	tokenArr[count++] = t;
}

void Expression :: operator=(const Expression& e)
{
	capacity = e.capacity;
	count = e.count;
	delete[] tokenArr;
	tokenArr = new Token[e.capacity];
	copy(e.tokenArr, e.tokenArr + count, tokenArr);
}