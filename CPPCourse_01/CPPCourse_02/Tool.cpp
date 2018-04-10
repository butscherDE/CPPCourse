#include "stdafx.h"
#include "Tool.h"


Tool::Tool(int strength, char type) : m_strength(strength), m_type(type) {
}


Tool::~Tool()
{
}

bool Tool::fight(const Tool & tool )
{
	return getStrength(tool.getType()) > tool.getStrength(getType());
}

const char Tool::getType() const
{
	return m_type;
}