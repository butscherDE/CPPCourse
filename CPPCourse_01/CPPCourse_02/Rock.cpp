#include "stdafx.h"
#include "Rock.h"


Rock::Rock(const int strength, const char type) : Tool(strength, type) {
}

Rock::~Rock()
{
}

int Rock::getStrength(char type) const {
	if (type == 's') {
		return 2;
	}
	else {
		return 1;
	}
}
