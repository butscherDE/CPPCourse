#pragma once
class Tool
{
public:
	Tool(int strength, char type);
	virtual ~Tool();
	bool fight(const Tool& tool);
	virtual int getStrength(char type) const = 0;
	const char getType() const;

private:
	int m_strength;
	char m_type;
};

