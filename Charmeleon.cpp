
#include <iostream>
#include "Charmeleon.h"
#include "Charizard.h"

//Constructor

Charmeleon::Charmeleon() : Charmander() {
	name = "Charmeleon";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Charmeleon::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Fire Beam\n   2.Fire Blast\n   3.Heal\n   4.Run Away";
	if (experience > 50) {
		std::cout << "\n   5.Evolve";
	}
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
	else if (choice == 5) {
		if (experience < 50) {
			std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
		}
		else {
			std::cout << "======================================================================\n" <<
				"In a sudden swirl of light, " << name << " has evolved to Charizard!\n" <<
				"======================================================================" << std::endl;
			return new Charizard();
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

void Charmeleon::basicAttack(Pokemon& opponent) {
	std::cout << "\n" << name << " zapps " << opponent.getName() << " with a fire beam!\n" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Charmeleon::specialAttack(Pokemon& opponent) {
	std::cout << "\nFire blasts and lightning, very, very frightnening me!\n" << std::endl;
	std::cout << "\n" << opponent.getName() << " was hit by a Fire Blast.\n Any way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+30));
}