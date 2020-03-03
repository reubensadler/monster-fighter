#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include <string_view>


class Monster : public Creature
{
public:
	enum Type
	{
		SLIME,
		GOBLIN,
		ORC,
		DRAGON,
		MAX_TYPES
	};

private:
	struct MonsterData
	{
		std::string_view name;
		char symbol;
		int health;
		int minDamage;
		int maxDamage;
		int speed;
		int gold;
	};

	static constexpr std::array<MonsterData, Monster::MAX_TYPES> monsterData{
		// {name, symbol, health, minDamage, maxDamage, speed, gold}
		{	{ "slime",	's', 3,	 1, 1, 1, 5 },
			{ "goblin", 'g', 4,  1, 3, 5, 15},
			{ "orc",	'o', 8,  2, 4, 2, 25 },
			{ "dragon", 'D', 16, 4, 6, 3, 100 }}
	};

public:
	Monster(Type type);

	static Type getRandomMonster(int playerLevel);
};

#endif MONSTER_H