// OOP ex 4.1 - Monsters
// Description : Battling program
// Author : Duncan Bourquard
// Date : 03.10.2017

#include <iostream>

#include "Monster.h"

int main()
{
	Monster m1 = Monster();
	Monster m2 = Monster();
	
	if (m1.race == m2.race)
	{
		std::cout << "Same classes monsters can't battle against !\n";
	}
	else
	{
		int round = 0;
		bool ism1CurrentMonster;
		m1.speed > m2.speed ? ism1CurrentMonster = true : ism1CurrentMonster = false;
		do 
		{
			ism1CurrentMonster ? m1.attack(m2) : m2.attack(m1);
			ism1CurrentMonster = !ism1CurrentMonster;
			round++;
		} while (m1.health > 0 && m2.health > 0);

		std::cout << "Monster ";
		m1.health == 0 ? std::cout << "1" : std::cout << "2";
		std::cout << " has won in " << round << "rounds !\n";
	}

	std::cout << "HP: " << m1.health << " AP: " << m1.attackPower << " DP: " << m1.defensivePower << " S: " << m1.speed << " race: " << m1.race << ".\n";
	std::cout << "HP: " << m2.health << " AP: " << m2.attackPower << " DP: " << m2.defensivePower << " S: " << m2.speed << " race: " << m2.race << ".\n";


	system("pause");
	return EXIT_SUCCESS;
}
