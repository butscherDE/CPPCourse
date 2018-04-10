#pragma once
#include "Tool.h"
class Paper :
	public Tool
{
public:
	Paper(const int strength, const char type);
	~Paper();
	int getStrength(const char type) const;
};

