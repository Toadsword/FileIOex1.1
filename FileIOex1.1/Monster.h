#ifndef MONSTER_H
#define MONSTER_H

enum Race
{
	ORC = 1,
	TROLL = 2,
	GOBLIN = 3
};

class Monster
{
public:
	Monster(double health, double attackPower, double defensivePower, double speed, Race race);
	~Monster();
	void attack(Monster* enemy);

	double health;
	double attackPower;
	double defensivePower;
	double speed;
	Race race;
};

#endif

