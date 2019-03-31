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
	bool checkError;							// ��ȣ�� ¦�� ���߱� ���� ����
	char curValue;
	char preValue = ' ';						// ������ �����ϱ� ���� �� �� ��ū ����
	int number;
	int length = formula.length();
	
	for (int i = 0; i < length; i++)
	{
		union token temp;
		curValue = formula[i];
		checkError = true;
		if (curValue == ' ') continue;				// ������ �����Ѵ�.
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
						tokenArr[j].setType(CHECK);		// ¦�� ���� ��ȣ�� type�� Check�� ��������ش�.
						temp.oper = curValue;
						insertToken(temp , OPERATOR);
						checkError = false;
						break;
					}
				}
			}

			if (checkError == true) throw Exception("�߸��� ���� �Է��ϼ̽��ϴ�!");		// ¦�� �ȸ´� ��ȣ�� ������ ��� ����ó��
		}
		else if (i == length - 1 && isOperator(curValue))	throw Exception("���� ���������� �����ڰ� �� �� �����ϴ�!");
		else if (isOperand(curValue))
		{
			if (preValue == ' ')		// ó�� ������ ��ū�� �ǿ������̸� ����
			{
				temp.value = curValue -'0';
				insertToken(temp, OPERAND);
			}
			else if (tokenArr[count - 1].getType() == OPERAND)				// �� ��ū�� �ǿ������� ��� �ϳ��� ���ڷ� ����.
			{
				if (formula[i - 1] == ' ')
					throw Exception("[����] �ǿ����� ���̿��� ������ �� �� �����ϴ�!");

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
				throw Exception("[����] �ݴ� ��ȣ ������ �ٷ� �ǿ����ڰ� �� �� �����ϴ�!");
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
				if (curValue == '-')			// '-'�� ���� �����ڷ� �ν��ϰ� '~'�� ����
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
				else throw Exception("[����] ���� �����ڴ� ���� ���� �� �� �����ϴ�!");
			}
			else if (isOperator(preValue) && preValue != ')' && curValue == '-')
			{
				temp.oper = '~';
				insertToken(temp, BIOPERATOR);
				preValue = '~';
			}
			else if (curValue == '!')
			{
				if (preValue == ')' || isOperand(preValue)) throw Exception("[����] ������ �� ���� ����");

				temp.oper = curValue;
				insertToken(temp, BIOPERATOR);
				preValue = curValue;
			}
			else if (isp(preValue) == 1 && icp(curValue) != 1)		// '-' �� if������ �ɷ�����.
				throw Exception("[����] ���� ������ �������� ���� �����ڰ� �� �� �����ϴ�!");
			else if (isOperator(preValue) && preValue != ')' && curValue != '(')
				throw Exception("[����] ������ �� ���� ����");
			else if (preValue == ')' && curValue == '(')
				throw Exception("[����] ������ �� ���� ����");
			else if (isOperand(preValue) && curValue == '(')
				throw Exception("[����] �ǿ����� �������� ���� ��ȣ�� �� �� �����ϴ�!");
			else
			{
				temp.oper = curValue;
				insertToken(temp, OPERATOR);
				preValue = curValue;
			}

		}
		else throw Exception("[����] �߸��� ���� �Է��ϼ̽��ϴ�!");
	}

	for (int i = 0; i < count; i++)			// ���� ��ȣ�� ����Ǿ����� üũ
	{
		if (tokenArr[i].getData().oper == '(' && tokenArr[i].getType() != CHECK)
		{
			throw Exception("[����] �߸��� ���� �Է��ϼ̽��ϴ�!");
		}
	}
}

Expression Expression::getPostfix(string formula)
{
	Expression ex;
	changeToken(formula);					// �Էµ� ���� ��ū ������ �����ش�.
	Stack<Token> stack;
	int operand = 0;

	cout << "--- ���� ������ : ";

	for (int i = 0; i < count; i++)
	{
		//Token tempToken = stack.getTop();
		if (tokenArr[i].getType() == OPERAND)		// �ǿ������� ��� ���
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
			stack.pop();						// '('�� pop���ش�.
		}
		else
		{
			if (stack.isEmpty()) stack.push(tokenArr[i]);		// ���ÿ� �ƹ��͵� ������� ���� ��� push
			else if (isp(stack.getTop().getData().oper) > icp(tokenArr[i].getData().oper))	stack.push(tokenArr[i]);	// ���ÿ� �ִ� �������� �켱 ������ �� Ŭ ���
			else									// ���ÿ� �ִ� �������� �켱 ������ �۰ų� ���� ��
			{
				if (stack.getTop().getType() == BIOPERATOR && tokenArr[i].getType() == BIOPERATOR) stack.push(tokenArr[i]);	// ���� �������� ���
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

	for (int j = stack.getIndex(); j >=0; j--)				// ���ÿ� �����ִ� �����ڸ� ��� ����Ѵ�.
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