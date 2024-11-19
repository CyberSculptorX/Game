
#include <iostream>
#include "Venusaur.h"

//Constructor
Venusaur::Venusaur() : Ivysaur() {
	name = "Venusaur";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Venusaur::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Seed Beam\n   2.Seed Strike\n   3.Seed Cannon\n   4.Heal\n   5.Run Away" << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		basicAttack(opponent);
	}
	else if (choice == 2) {
		specialAttack(opponent);
	}
	else if (choice == 3) {
		bonusAttack(opponent);
	}
	else if (choice == 4) {
		heal(20);
	}
	else if (choice == 5) {
		if (runAway()) {
			health = 0; //end the battle using health=0 for now.
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

void Venusaur::basicAttack(Pokemon& opponent) {
	std::cout << name << " zapps " << opponent.getName() << " with Seed Beam!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Venusaur::specialAttack(Pokemon& opponent) {
	std::cout << "\nSeed Strikes and lightning, very, very frightnening me!\n" << std::endl;
	std::cout << "\n" << opponent.getName() << " was hit by a Seed Blast.\nAny way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+30));
}

void Venusaur::bonusAttack(Pokemon& opponent) {
	std::cout << "Seed Cannons and lightning, very, very frightnening me!" << std::endl;
	std::cout << opponent.getName() << " was hit by a Seed cannon.\nAny way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+60));
}