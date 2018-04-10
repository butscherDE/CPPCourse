#pragma once
#include "Tool.h"
class Scissor : public Tool
{
public:
	Scissor(const int strength, const char type);
	~Scissor();
	int getStrength(char type) const;
};

