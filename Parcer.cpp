#include"stdafx.h"
#include"parcer.h"
#include"lexer.h"
#include"error.h"
#include"table.h"

double Parcer::primary(bool get) {
	if (get) Lexer::get_token();
	switch (Lexer::curr_token) {
	case  Lexer::NUMBER:
	{
		double v = Lexer::number_value;
		Lexer::get_token();
		return v;
	}
	case Lexer::NAME:
	{
		if (!get) TablePair::table.push(Variable(Lexer::string_value));
		double& v = TablePair::table[Lexer::string_value];
		if (Lexer::get_token() == Lexer::ASSIGN) v = expression(true);
		return v;
	}

	case Lexer::MINUS:
		return -primary(true);
	case Lexer::LP:
	{
		double e = expression(true);
		if (Lexer::curr_token != Lexer::RP)
			throw Error::Syntax_error("')' expected");
		Lexer::get_token();
		return e;
	}
	default:
		throw Error::Syntax_error("primary expected");
	}
}

double Parcer::term(bool get) {
	double left = primary(get);
	for (;;) {
		switch (Lexer::curr_token) {
		case Lexer::MULT:
			left *= primary(true);
			break;
		case Lexer::DIV:
		{
			if (double d = primary(true)) {
				left /= d;
				break;
			}
			throw Error::Zero_devide();
		}
		default:
			return left;
		}
	}
}

double Parcer::expression(bool get) {
	double left = term(get);
	for (;;) {
		switch (Lexer::curr_token) {
		case Lexer::PLUS:
			left += term(true);
			break;
		case Lexer::MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}
