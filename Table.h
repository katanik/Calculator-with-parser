#include"stdafx.h"
#include"Variable.h"
#include<set>
#include<vector>

namespace TablePair
{
	class Table
	{
	private:
		std::vector <Variable> table;
	public:
		Table() = default;
		~Table() = default;
		double& operator[] (std::string &);
		double& operator[] (const char*);
		int size() const;
		void push(Variable);
	};

	extern Table table;
}