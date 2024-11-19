
#include <iostream>
#include "Blastoise.h"

//Constructor
Blastoise::Blastoise() : Wartortle() {
	name = "Blastoise";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Blastoise::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Water Beam\n   2.Water Blast\n   3.Water Cannon\n   4.Heal\n   5.Run Away" << std::endl;
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

void Blastoise::basicAttack(Pokemon& opponent) {
	std::cout << "\n" << name << " blasts " << opponent.getName() << " with a water beam!\n" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Blastoise::specialAttack(Pokemon& opponent) {
	std::cout << "\n" << "Water Blasts and lightning, very, very frightnening me!\n" << std::endl;
	std::cout << "\n" << opponent.getName() << " was hit by a Water Blast.\nAny way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+30));
}

void Blastoise::bonusAttack(Pokemon& opponent) {
	std::cout << "Water Cannons and lightning, very, very frightnening me!" << std::endl;
	std::cout << opponent.getName() << " was hit by a Water Cannon.\nAny way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+60));
}