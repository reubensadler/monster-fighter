#include "Player.h"
#include "Monster.h"

// Extract and discard characters in stream if player entered invalid characters
void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Monster attacks player
void monsterAttack(Monster& m, Player& p)
{
	int damage{ m.randomDamage() };
	p.reduceHealth(damage);
	std::cout << "The monster hits you for " << damage << " damage.\n";
}

// Player attacks monster - when monster is killed, give reward and level up
void playerAttack(Monster& m, Player& p)
{
	int damage{ p.randomDamage() };
	m.reduceHealth(damage);
	std::cout << "You hit the " << m.getName() <<  " for " << damage << " damage.\n";

	if (m.getHealth() <= 0)
	{
		p.addGold(m.getGold());
		std::cout << "You killed the " << m.getName() << ".\nYou found "
			<< m.getGold() << " gold.\n";

		if (m.getName() == "dragon")
		{
			std::cout << "You also found a health potion. You gain 10 health.\n";
			p.increaseHealth(10);
		}

		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << "!\n\n";
	}
}

void fightMonster(Player& p)
{
	Monster m{ Monster::getRandomMonster(p.getLevel()) };
	std::cout << "\nYou have enountered a " << m.getName() << ".\n";
		
	// Loop until player runs, kills monster, or is killed
	while (!p.isDead() && !m.isDead())
	{
		std::cout << "Would you like to (R)un, (F)ight or check your (H)ealth or (G)old? ";
		char runOrFight{};
		std::cin >> runOrFight;
		clearInput();

		if (toupper(runOrFight) == 'R')
		{
			// Escape is more likely if player has higher speed
			std::uniform_int_distribution<> random{ 0, p.getSpeed() };
			if (random(mt))
			{
				std::cout << "You fled!\n\n";
				return;
			}
			else
			{
				std::cout << "Can't escape!\n";
				monsterAttack(m, p);
			}
		}
		if (toupper(runOrFight) == 'F')
		{
			// If player is the same speed or faster than the monster
			if (p.getSpeed() >= m.getSpeed())
				playerAttack(m, p);

			// Monster attacks if it is still alive
			if (!m.isDead())
				monsterAttack(m, p);

			// If player is slower than the monster
			if (p.getSpeed() < m.getSpeed())
			{
				if (!p.isDead())
					playerAttack(m, p);
			}
		}
		if (toupper(runOrFight) == 'H')
			std::cout << "You have " << p.getHealth() << " hp.\n";
		if (toupper(runOrFight) == 'G')
			std::cout << "You have " << p.getGold() << " gold.\n";
	}
}

int main()
{
	std::cout << "What is your name? ";
	std::string playerName;
	std::cin >> playerName;

	Player p{ playerName };
	clearInput();

	std::cout << "Welcome " << p.getName() << ". You goal is to get to level 20 and get as much gold as you can along the way" << '\n';
	
	p.chooseStats();

	// Fight monsters until player dies or reaches level 20 and wins
	while (!p.isDead() && p.getLevel() < 20)
		fightMonster(p);

	if (p.getLevel() == 20)
	{
		std::cout << "\nCongratulations " << p.getName() << ", you have reached level 20! You win!\nYou found "
			<< p.getGold() << " gold on your adventure.";
	}
	else
		std::cout << "\nBetter luck next time.\n";

	return 0;
}