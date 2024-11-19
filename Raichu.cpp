
#include <iostream>
#include "Raichu.h"

//Constructor

Raichu::Raichu() {
	name = "Raichu";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Raichu::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Electric Beam\n   2.Electric Blast\n   3.Heal\n   4.Run Away";

	std::cout << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		basicAttack(opponent);
	}
	else if (choice == 2) {
		specialAttack(opponent);
	}
	else if (choice == 3) {
		heal(20);
	}
	else if (choice == 4) {
		if (runAway()) {
			health = 0; //end the battle using health=0 for now.
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

void Raichu::basicAttack(Pokemon& opponent) {
	std::cout << name << " zapps " << opponent.getName() << " with Electric Beam!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Raichu::specialAttack(Pokemon& opponent) {
	std::cout << "\nElectric blasts and lightning, very, very frightnening me!\n" << std::endl;
	std::cout << "\n" << opponent.getName() << " was hit by a Electric Blast.\n Any way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+30));
}