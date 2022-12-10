#include "stdafx.h"
#include "table.h"
#include"error.h"

double& TablePair::Table::operator[] (std::string & s)
{
	int id = 0;
	for (; id < size() && table[id].name != s; ++id);

	if (id == size()) throw Error::Table_error("no exist variable");
	else return table[id].value;
}

double& TablePair::Table::operator[] (const char* p)
{
	if (size()==0) throw Error::Table_error("empty table");
	int id = 0;
	for (; id < size() && table[id].name != p; ++id);

	if (id == size()) throw Error::Table_error("no exist variable");
	else return table[id].value;
}


int TablePair::Table::size() const
{
	return static_cast<int>(table.size());
}

void TablePair::Table::push(Variable v)
{
	for (int i = 0; i < size(); ++i)
	{
		if (table[i].name == v.name)
		{
			table[i].value = v.value;
		}
	}
	table.push_back(v);
}


