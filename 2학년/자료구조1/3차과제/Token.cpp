#include "Token.h"

Token::Token(char i_value)
{
	value = i_value;
	type = Operator;
}

Token::Token(string i_value)
{
	value = i_value;
	type = Operand;
}

Token :: Token(string i_value, int i_type)
{
	value = i_value;
	type = i_type;
}