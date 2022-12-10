#pragma once
struct Variable
{
public:
	std::string name;
	double value;
	Variable(std::string s="", double v=0);
	Variable(const Variable&);
	Variable& operator= (const Variable&);
	~Variable();
};

