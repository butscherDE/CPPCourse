#include "stdafx.h"
#include "Paper.h"

Paper::Paper(const int strength, const char type) : Tool(strength, type)
{
}

Paper::~Paper()
{
}

int Paper::getStrength(const char type) const {
	if (type == 'r') {
		return 2;
	}
	else {
		return 1;
	}
}
