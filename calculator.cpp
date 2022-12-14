// calculator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"Driver.h"
#include"Table.h"
#include"Lexer.h"
#include"Parcer.h"
#include"Error.h"
#include<iostream>
#include<sstream>

int Driver::no_of_errors = 0;
std::istream* Driver::input;
TablePair::Table TablePair::table;

void Driver::skip()
{
	char c;
	while (Driver::input->get(c) && !(c == Lexer::PRINT || c == '\n'));
	Driver::input->putback(c);
}

int main(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		Driver::input = &std::cin;
		break;
	case 2:
		Driver::input = new std::istringstream(argv[1]);
		break;
	default:
		std::cerr<<"too many arguments";
		return 1;
	}

	TablePair::table.push(Variable("pi", acos(-1.)));
	TablePair::table.push(Variable("e", 2.718281));

	while (*Driver::input) {
		try {
			Lexer::get_token();
			if (Lexer::curr_token == Lexer::END) break;
			if (Lexer::curr_token == Lexer::PRINT) continue;
			std::cout << Parcer::expression(false) << '\n';
		}
		catch (Error::Zero_devide)
		{
			std::cerr << "divide by zero\n";
			if (Lexer::curr_token != Lexer::PRINT) Driver::skip();
		}
		catch (Error::Syntax_error e1)
		{
			std::cerr << e1.p;
			if (Lexer::curr_token != Lexer::PRINT) Driver::skip();
		}
		catch (Error::Table_error e2)
		{
			std::cerr << e2.p;
			if (Lexer::curr_token != Lexer::PRINT) Driver::skip();
		}
	}
	if (Driver::input != &std::cin) delete Driver::input;
	return Driver::no_of_errors;
}

