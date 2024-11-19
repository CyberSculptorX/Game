
#include <iostream>
#include "Ivysaur.h"
#include "Venusaur.h"

//Constructor

Ivysaur::Ivysaur() : Bulbasaur() {
	name = "Ivysaur";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Ivysaur::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Seed Beam\n   2.Seed Blast\n   3.Heal\n   4.Run Away";
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
				"In a sudden swirl of light, " << name << " has evolved to Venusaur!\n" <<
				"======================================================================" << std::endl;
			return new Venusaur();
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

void Ivysaur::basicAttack(Pokemon& opponent) {
	std::cout << name << " zapps " << opponent.getName() << " with Seed Beam!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Ivysaur::specialAttack(Pokemon& opponent) {
	std::cout << "\nSeed blasts and lightning, very, very frightnening me!\n" << std::endl;
	std::cout << "\n" << opponent.getName() << " was hit by a Seed Blast.\nAny way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+30));
}
