#pragma once
#include "Tool.h"
class Rock :
	public Tool
{
public:
	Rock(int strength, char type);
	~Rock();
	int getStrength(const char type) const;
};

