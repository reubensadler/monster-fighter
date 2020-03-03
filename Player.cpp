#include "Player.h"

Player::Player(std::string name) :
	Creature{ name, '@', 12, 1, 3, 1, 0 }
{
}

void Player::levelUp()
{
	++m_level;
	++m_minDamage;
	++m_maxDamage;
}

void Player::chooseStats()
{
	int totalPoints{ 5 };
	int healthPoints{};
	int damagePoints{};
	int speedPoints{};

	bool pointsToSpend{ true };

	// Keep asking player to spent points until they use all 5, or agree to continue with points leftover
	while (pointsToSpend)
	{
		std::cout << "\nYour current stats are:\nHealth - " << m_health << "\nMaximum Damage - " << m_maxDamage << "\nSpeed - " << m_speed 
			<< "\nYou have " << totalPoints << " points to increase stats.\n"
			<< "How many points would you like to put into Health? Max health will increase by three for each point spent. ";
		std::cin >> healthPoints;
		totalPoints -= healthPoints;
		clearInput();

		std::cout << "How many points would you like to put into Max Damage? ";
		std::cin >> damagePoints;
		totalPoints -= damagePoints;
		clearInput();

		std::cout << "How many points would you like to put into Speed? ";
		std::cin >> speedPoints;
		totalPoints -= speedPoints;
		clearInput();

		if (totalPoints == 0)
			pointsToSpend = false;

		if (totalPoints > 0)
		{
			std::cout << "You still have " << totalPoints << " points to spend. Are you sure you want to continue? y/n ";
			char yesOrNo{};
			std::cin >> yesOrNo;
			clearInput();
			if (tolower(yesOrNo) == 'y')
				pointsToSpend = false;
			totalPoints = 5;
		}

		if (totalPoints < 0)
		{
			std::cout << "You only have 5 points, try again.\n";
			totalPoints = 5;
		}
	}
	m_health += (healthPoints * 3);
	m_maxDamage += damagePoints;
	m_speed += speedPoints;
}