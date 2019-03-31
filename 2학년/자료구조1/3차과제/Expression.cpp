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
	bool checkError;							// ��ȣ�� ¦�� ���߱� ���� ����
	string curValue;
	string preValue = " ";						// ������ �����ϱ� ���� �� �� ��ū ����
	int number;
	int length = formula.length();
	for (int i = 0; i < length; i++)
	{
		curValue = formula[i];
		checkError = true;
		if (curValue == " ") continue;				// ������ �����Ѵ�.
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
						token[j].setType(Check);		// ¦�� ���� ��ȣ�� type�� Check�� ��������ش�.
						insertToken(curValue, Operator);
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
			if (preValue == " ")		// ó�� ������ ��ū�� �ǿ������̸� ����
			{
				insertToken(curValue, Operand);
				preValue = curValue;
			}
			else if (token[count - 1].getType() == Operand)				// �� ��ū�� �ǿ������� ��� �ϳ��� ���ڷ� ����.
			{
				if (formula[i - 1] == ' ')
					throw Exception("[����] �ǿ����� ���̿��� ������ �� �� �����ϴ�!");

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
				else throw Exception("[����] ���� ������ ! �������� 0 �Ǵ� 1�� �;ߵ˴ϴ�.");
			}
			else if (preValue == ")")
				 throw Exception("[����] �ݴ� ��ȣ ������ �ٷ� �ǿ����ڰ� �� �� �����ϴ�!");
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
				if (curValue == "-")			// '-'�� ���� �����ڷ� �ν��ϰ� '~'�� ����
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
				else throw Exception("[����] ���� �����ڴ� ���� ���� �� �� �����ϴ�!");
			}
			else if (isOperator(preValue) && preValue != ")" && curValue == "-")
			{
				insertToken("~", BiOperator);
				preValue = "~";
			}
			else if (curValue == "!")
			{
				if (preValue == ")" || isOperand(preValue)) throw Exception("[����] ������ �� ���� ����");

				insertToken(curValue, BiOperator);
				preValue = curValue;
			}
			else if (isp(preValue) == 1 && icp(curValue) != 1)		// '-' �� if������ �ɷ�����.
				throw Exception("[����] ���� ������ �������� ���� �����ڰ� �� �� �����ϴ�!");
			else if (isOperator(preValue) && preValue != ")" && curValue != "(")
				throw Exception("[����] ������ �� ���� ����");
			else if (preValue == ")" && curValue == "(")
				throw Exception("[����] ������ �� ���� ����");
			else if (isOperand(preValue) && curValue == "(")
				throw Exception("[����] �ǿ����� �������� ���� ��ȣ�� �� �� �����ϴ�!");
			else
			{
				insertToken(curValue, Operator);
				preValue = curValue;
			}

		}
		else throw Exception("[����] �߸��� ���� �Է��ϼ̽��ϴ�!");
	}
	
	for (int i = 0; i < count; i++)			// ���� ��ȣ�� ����Ǿ����� üũ
	{
		if (token[i].getValue() == "(" && token[i].getType() != Check)
		{
			throw Exception("[����] �߸��� ���� �Է��ϼ̽��ϴ�!");
		}
	}
}

Expression Expression :: getPostfix(string formula)
{
	Expression ex;
	changeToken(formula);					// �Էµ� ���� ��ū ������ �����ش�.
	Stack<Token> stack;
	int operand = 0;
	stack.push('#');
	cout << "--- ���� ������ : ";

	for (int i = 0; i < count; i++)	
	{
		if (token[i].getType() == Operand)		// �ǿ������� ��� ���
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
			stack.pop();						// '('�� pop���ش�.
		}
		else
		{
			if (stack.getTop().getValue() == "#") stack.push(token[i]);		// ���ÿ� �ƹ��͵� ������� ���� ��� push
			else if (isp(stack.getTop().getValue()) > icp(token[i].getValue()))	stack.push(token[i]);	// ���ÿ� �ִ� �������� �켱 ������ �� Ŭ ���
			else									// ���ÿ� �ִ� �������� �켱 ������ �۰ų� ���� ��
			{
				if (stack.getTop().getType() == BiOperator && token[i].getType() == BiOperator) stack.push(token[i]);	// ���� �������� ���
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

	for (int j = stack.getIndex() ; j > 0; j--)				// ���ÿ� �����ִ� �����ڸ� ��� ����Ѵ�.
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