#include "Expression.h"

Expression :: Expression()
{
	capacity = 4;
	count = 0;
	token = new Token[capacity];
}

Expression :: Expression(const Expression& e)
{
	capacity = e.capacity;
	count = e.count;
	token = new Token[capacity];

	copy(e.token, e.token + count, token);
}

Expression :: ~Expression()
{
	delete[] token;
}

bool Expression :: isOperator(string value)
{
	if (value == "(" || value == "-" || value == "!" || value == "*" || value == "/" || value == "%" 
		|| value == "+" || value == ")" || value == "^" || value == "~")
		return true;
	else return false;
}

bool Expression ::isOperand(string value)
{
	if ("0" <= value && value <= "9") return true;
	else return false;
}

int Expression :: isp(string value)			// In Stack Priority
{
	if (value == "(") return 6;
	else if (value == "~" || value == "!") return 1;
	else if (value == "^") return 2;
	else if (value == "*" || value == "/" || value == "%") return 3;
	else if (value == "+" || value == "-") return 4;
	else return 5;
}

int Expression :: icp(string value)			// In Coming Priority
{
	if (value == "(") return 0;
	else if (value == "~" || value == "!") return 1;
	else if (value == "^") return 2;
	else if (value == "*" || value == "/" || value == "%") return 3;
	else if (value == "+" || value == "-") return 4;
	else return 5;
}

void Expression :: changeToken(string formula)
{
	bool checkError;							// 괄호의 짝을 맞추기 위한 변수
	string curValue;
	string preValue = " ";						// 공백을 무시하기 위해 그 전 토큰 저장
	int number;
	int length = formula.length();
	for (int i = 0; i < length; i++)
	{
		curValue = formula[i];
		checkError = true;
		if (curValue == " ") continue;				// 공백은 무시한다.
		else if (curValue == ")")
		{
			for (int j = 0; j < count; j++)
			{
				if (token[j].getValue() == "(")
				{
					if (token[j].getType() == Check) continue;
					else
					{
						preValue = curValue;
						token[j].setType(Check);		// 짝이 맞은 괄호는 type을 Check로 변경시켜준다.
						insertToken(curValue, Operator);
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
			if (preValue == " ")		// 처음 들어오는 토큰이 피연산자이면 저장
			{
				insertToken(curValue, Operand);
				preValue = curValue;
			}
			else if (token[count - 1].getType() == Operand)				// 전 토큰이 피연산자일 경우 하나의 숫자로 본다.
			{
				if (formula[i - 1] == ' ')
					throw Exception("[오류] 피연산자 사이에는 공백이 올 수 없습니다!");

				count--;
				number = stoi(token[count].getValue()) * 10 + stoi(curValue);
				insertToken(to_string(number), Operand);
				preValue = curValue;
			}
			else if (preValue == "!")
			{
				if (curValue == "0" || curValue == "1")
				{
					insertToken(curValue, Operand);
					preValue = curValue;
				}
				else throw Exception("[오류] 단항 연산자 ! 다음에는 0 또는 1이 와야됩니다.");
			}
			else if (preValue == ")")
				 throw Exception("[오류] 닫는 괄호 다음에 바로 피연산자가 올 수 없습니다!");
			else
			{
				insertToken(curValue, Operand);
				preValue = curValue;
			}
		}
		else if (isOperator(curValue))
		{
			if (preValue == " ")
			{
				if (curValue == "-")			// '-'를 단항 연산자로 인식하고 '~'로 변경
				{
					insertToken("~", BiOperator);
					preValue = "~";
				}
				else if (curValue == "!")
				{
					insertToken("!", BiOperator);
					preValue = curValue;
				}
				else if (curValue == "(")
				{
					insertToken("(", Operator);
					preValue = curValue;
				}
				else throw Exception("[오류] 이항 연산자는 제일 먼저 올 수 없습니다!");
			}
			else if (isOperator(preValue) && preValue != ")" && curValue == "-")
			{
				insertToken("~", BiOperator);
				preValue = "~";
			}
			else if (curValue == "!")
			{
				if (preValue == ")" || isOperand(preValue)) throw Exception("[오류] 이해할 수 없는 수식");

				insertToken(curValue, BiOperator);
				preValue = curValue;
			}
			else if (isp(preValue) == 1 && icp(curValue) != 1)		// '-' 는 if문에서 걸러진다.
				throw Exception("[오류] 단항 연산자 다음으로 이항 연산자가 올 수 없습니다!");
			else if (isOperator(preValue) && preValue != ")" && curValue != "(")
				throw Exception("[오류] 이해할 수 없는 수식");
			else if (preValue == ")" && curValue == "(")
				throw Exception("[오류] 이해할 수 없는 수식");
			else if (isOperand(preValue) && curValue == "(")
				throw Exception("[오류] 피연산자 다음으로 여는 괄호가 올 수 없습니다!");
			else
			{
				insertToken(curValue, Operator);
				preValue = curValue;
			}

		}
		else throw Exception("[오류] 잘못된 값을 입력하셨습니다!");
	}
	
	for (int i = 0; i < count; i++)			// 여는 괄호만 저장되었는지 체크
	{
		if (token[i].getValue() == "(" && token[i].getType() != Check)
		{
			throw Exception("[오류] 잘못된 값을 입력하셨습니다!");
		}
	}
}

Expression Expression :: getPostfix(string formula)
{
	Expression ex;
	changeToken(formula);					// 입력된 식을 토큰 단위로 나눠준다.
	Stack<Token> stack;
	int operand = 0;
	stack.push('#');
	cout << "--- 후위 계산식은 : ";

	for (int i = 0; i < count; i++)	
	{
		if (token[i].getType() == Operand)		// 피연산자일 경우 출력
		{
			operand = atoi(token[i].getValue().c_str());
			cout << operand << " ";
			ex.insertToken(token[i].getValue(), Operand);
		}
		else if (token[i].getValue() == ")")
		{
			for (int j = stack.getIndex(); j >=0; j--)
			{
				if (stack.getTop().getValue() == "(") break;

				cout << stack.getTop().getValue() << " ";
				ex.insertToken(stack.getTop().getValue(), Operator);
				stack.pop();		
			}
			stack.pop();						// '('을 pop해준다.
		}
		else
		{
			if (stack.getTop().getValue() == "#") stack.push(token[i]);		// 스택에 아무것도 들어있지 않을 경우 push
			else if (isp(stack.getTop().getValue()) > icp(token[i].getValue()))	stack.push(token[i]);	// 스택에 있는 연산자의 우선 순위가 더 클 경우
			else									// 스택에 있는 연산자의 우선 순위가 작거나 같을 때
			{
				if (stack.getTop().getType() == BiOperator && token[i].getType() == BiOperator) stack.push(token[i]);	// 단항 연산자인 경우
				else
				{
					while(stack.getTop().getValue() != "#")
					{
						if (isp(stack.getTop().getValue()) <= icp(token[i].getValue()))
						{
							cout << stack.getTop().getValue() << " ";
							ex.insertToken(stack.getTop().getValue(), Operator);
							stack.pop();
						}
						else break;
					}
					stack.push(token[i]);
				}
			}
		}
	}

	for (int j = stack.getIndex() ; j > 0; j--)				// 스택에 남아있는 연산자를 모두 출력한다.
	{
		cout << stack.getTop().getValue() << " ";
		ex.insertToken(stack.getTop().getValue(), Operator);
		stack.pop();	
	}
	cout << endl;
	return ex;
}

void Expression :: insertToken(string value, int type)
{
	if (count == capacity - 1)
	{
		capacity *= 2;
		Token *temp = new Token[capacity];
		copy(token, token + count, temp);
		delete[] token;
		token = temp;
	}
	Token t(value, type);
	token[count++] = t;
}

void Expression :: operator=(const Expression& e)
{
	capacity = e.capacity;
	count = e.count;
	delete[] token;
	token = new Token[e.capacity];
	copy(e.token, e.token + count, token);
}