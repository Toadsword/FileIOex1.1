#include "Monster.h"
#include <iostream>
#include <fstream>
#include <string>

Monster::Monster(double health, double attackPower, double defensivePower, double speed, Race race)
	: health(health), attackPower(attackPower), defensivePower(defensivePower), speed(speed), race(race)
{
}


Monster::~Monster()
{
}

void Monster::attack(Monster* enemy)
{
	double damage = this->attackPower - enemy->defensivePower;
	if (damage < 1)
		damage = 1;

	enemy->health = enemy->health - damage;
}