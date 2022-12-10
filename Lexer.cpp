#include"stdafx.h"
#include"Lexer.h"
#include"Driver.h"
#include"Error.h"

Lexer::Token_value Lexer::curr_token = Lexer::PRINT;
double Lexer::number_value;
std::string Lexer::string_value;

Lexer::Token_value Lexer::get_token() {
	char ch = 0;
	do {
		if (!Driver::input->get(ch)) return curr_token = Token_value::END;

	} while (isspace(ch) && ch != '\n');

	switch (ch) {
	case 0:
		return curr_token = END;
	case ';':
	case '\n':
	{
		return curr_token = PRINT;
	}
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '=':
	case '{':
	case '}':
		return curr_token = Token_value(ch);

	default:
		if (ch >= '0' && ch <= '9')
		{
			Driver::input->putback(ch);
			*Driver::input >> number_value;
			return curr_token = NUMBER;
		}
		if (isalpha(ch)) {
			string_value = ch;
			while (Driver::input->get(ch) && isalnum(ch))
				string_value.push_back(ch);
			Driver::input->putback(ch);
			return curr_token = Token_value::NAME;
		}
		throw Error::Syntax_error("bad_token");
		return curr_token = Token_value::PRINT;
	}
}
