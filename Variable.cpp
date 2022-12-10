#include "stdafx.h"
#include "Variable.h"


Variable::Variable(std::string s, double v)
{
	name = s;
	value = v;
}


Variable::~Variable()
{
}

Variable::Variable(const Variable& v)
{
	name = v.name;
	value = v.value;
}

Variable& Variable::operator= (const Variable& v)
{
	name = v.name;
	value = v.value;
	return *this;
}