// fileIO1.1 - Monsters but with files
// Description : Instead of taking the informations from the user, takes them from an easily readable file
// Author : Duncan Bourquard
// Date : 13.10.2017

#include <iostream>
#include <fstream>
#include <list>
#include <string>

#include "Monster.h"

void battleMonster(Monster* m1, Monster* m2)
{
	if (m1->race == m2->race)
	{
		std::cout << "Same classes monsters can't battle against !\n";
	}
	else
	{
		int round = 0;
		bool ism1CurrentMonster;
		m1->speed > m2->speed ? ism1CurrentMonster = true : ism1CurrentMonster = false;
		do
		{
			ism1CurrentMonster ? m1->attack(m2) : m2->attack(m1);
			ism1CurrentMonster = !ism1CurrentMonster;
			round++;
		} while (m1->health > 0 && m2->health > 0);

		std::cout << "Monster ";
		m1->health == 0 ? std::cout << "1" : std::cout << "2";
		std::cout << " has won in " << round << " rounds !\n";
	}

	std::cout << "Monster 1 stats : HP: " << m1->health << " AP: " << m1->attackPower << " DP: " << m1->defensivePower << " S: " << m1->speed << " race: " << m1->race << ".\n";
	std::cout << "Monster 2 stats : HP: " << m2->health << " AP: " << m2->attackPower << " DP: " << m2->defensivePower << " S: " << m2->speed << " race: " << m2->race << ".\n";
}

std::list<Monster> readMonsterFile()
{
	std::list<Monster> listMonster;
	std::ifstream monsterFile("test.txt");

	if (monsterFile.is_open())
	{
		std::string nameValue;
		double health = -1,
			attackPower = -1,
			defensePower = -1,
			speed = -1,
			value;
		int race = -1;

		while (!monsterFile.eof())
		{
			if (monsterFile >> nameValue >> value)
			{
				if (nameValue == "health")
					health = value;
				else if (nameValue == "attack")
					attackPower = value;
				else if (nameValue == "defense")
					defensePower = value;
				else if (nameValue == "speed")
					speed = value;
				else if (nameValue == "race")
					race = value;
			}

			if (health != -1 && attackPower != -1 && defensePower != -1 && speed != -1 && race != -1) {
				listMonster.push_back(Monster(health, attackPower, defensePower, speed, static_cast<Race>(race)));
				health = -1;
				attackPower = -1;
				defensePower = -1;
				speed = -1;
				race = -1;
			}
		}
		monsterFile.close();
	}
	else
		std::cout << "the file is not opened\n";

	return listMonster;
}


int main()
{
	std::list<Monster> monsters = readMonsterFile();
	auto it = monsters.begin();

	battleMonster(&*it, &*it++);

	system("pause");
	return EXIT_SUCCESS;
}
