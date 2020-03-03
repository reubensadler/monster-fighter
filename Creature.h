#ifndef CREATURE_H
#define CREATURE_H

#include <random>
#include <ctime>
#include <iostream>
#include <string>
#include <string_view>
#include <array>

// Use same seed for all random numbers
static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

// Forward declare clear input function, so it can be used in any class
void clearInput();

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_minDamage{};
	int m_maxDamage{};
	int m_speed;
	int m_gold;

public:
	// Forward declare Constructor
	Creature(std::string name, char symbol, int health, int minDamage, int maxDamage, int speed, int gold);

	// Accessors
	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getMinDamage() { return m_minDamage; }
	int getMaxDamage() { return m_maxDamage; }
	int getHealth() const { return m_health; }
	int getSpeed() const { return m_speed; }
	int getGold() const { return m_gold; }

	// Trivial functions
	void reduceHealth(int damage) { m_health -= damage; }
	bool isDead() { return m_health <= 0; }
	
	// Forward declare complex functions, implemented in Creature.cpp 
	int randomDamage();

};

#endif CREATURE_H
