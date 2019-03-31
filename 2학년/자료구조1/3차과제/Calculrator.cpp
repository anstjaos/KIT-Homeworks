#include "Calculrator.h"

void Calculrator::calculration(Expression e)		// �Ű������� ����ǥ����� ������ ��ü�� �޴´�.
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
					else throw Exception("[����] ���� ������ '!' �ڿ� 1, 0�̿��� ���� �Էµ�!");
				}
				break;
			case 2:			// ���� ������ '^'
			{
				rightValue = stoi(stack.getTop().getValue());
				stack.pop();

				leftValue = stoi(stack.getTop().getValue());
				stack.pop();

				result = 1;
				if (rightValue < 0) throw Exception("[����] ������ �� ��° �����ڰ� ������ ��� �߻�!");
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
			case 3:			// ����, ������, ������ ������
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

					if (rightValue == 0) throw Exception("[����] ������ ���� �����ڰ� 0�� ��� �߻�");

					result = leftValue / rightValue;
					stack.push(to_string(result));
				}
				else if (value.getValue() == "%")
				{
					rightValue = stoi(stack.getTop().getValue());
					stack.pop();

					leftValue = stoi(stack.getTop().getValue());
					stack.pop();

					if (rightValue == 0) throw Exception("[����] �ۼ�Ʈ ���� �����ڰ� 0�� ��� �߻�");

					result = leftValue % rightValue;
					stack.push(to_string(result));
				}
				break;
			case 4:			// ����, ���� ������
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
	cout << "---- ������� " << result << endl << endl;
}