#include "Monster.h"

Monster::Monster(Type type) :
	Creature{
		monsterData[type].name.data(),
		monsterData[type].symbol,
		monsterData[type].health,
		monsterData[type].minDamage,
		monsterData[type].maxDamage,
		monsterData[type].speed,
		monsterData[type].gold
} {}

Monster::Type Monster::getRandomMonster(int playerLevel)
{
	// Player only encounters dragons after level 5
	Monster::Type maxMonster{};
	if (playerLevel <= 5)
	{
		maxMonster = Monster::Type::ORC;
	}
	else
	{
		maxMonster = Monster::Type::DRAGON;
	}

	std::uniform_int_distribution<> random{ 0, maxMonster };
	Monster::Type monster{ static_cast<Monster::Type>(random(mt)) };

	return monster;
}