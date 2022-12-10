#include"stdafx.h"

namespace Error
{
	struct Zero_devide
	{
		Zero_devide() {}
	};

	struct Syntax_error
	{
		const char* p;
		Syntax_error(const char* p) :p(p) {}
	};

	struct Table_error
	{
		const char* p;
		Table_error(const char* p) : p(p) {}
	};
}
