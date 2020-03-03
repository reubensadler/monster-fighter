#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature
{
private:
	int m_level{ 1 };

public:
	Player(std::string name);

	void levelUp();
	void chooseStats();
	int getLevel() { return m_level; }

	void addGold(int gold) { m_gold += gold; }
	void increaseHealth(int health) { m_health += health; }
	bool hasWon() { return m_level == 20; }
};

#endif PLAYER_H