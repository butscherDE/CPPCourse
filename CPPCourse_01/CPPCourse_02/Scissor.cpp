#include "stdafx.h"
#include "Scissor.h"


Scissor::Scissor(const int strength, const char type) : Tool(strength, type)
{
}


Scissor::~Scissor()
{
}

int Scissor::getStrength(const char type) const {
	if (type == 'p') {
		return 2;
	}
	else {
		return 1;
	}
}