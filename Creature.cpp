#include "Creature.h"

Creature::Creature(std::string name, char symbol, int health, int minDamage, int maxDamage, int speed, int gold) :
	m_name{ name },
	m_symbol{ symbol },
	m_health{ health },
	m_minDamage{ minDamage },
	m_maxDamage{ maxDamage },
	m_speed{ speed },
	m_gold{ gold }
{
}

// Randomly choose damage between min and max for the creature
int Creature::randomDamage()
{
	std::uniform_int_distribution<> random{ m_minDamage, m_maxDamage };
	return random(mt);
}

