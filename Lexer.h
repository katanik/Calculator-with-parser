#include"stdafx.h"

namespace Lexer
{
	enum Token_value {
		NAME, NUMBER, END,
		PLUS = '+', MINUS = '-', MULT = '*', DIV = '/',
		PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
	};

	extern Token_value curr_token;
	extern double number_value;
	extern std::string string_value;

	Token_value get_token();
}
