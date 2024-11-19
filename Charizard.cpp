
#include <iostream>
#include "Charizard.h"

//Constructor
Charizard::Charizard() : Charmeleon() {
	name = "Charizard";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Charizard::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Fire Beam\n   2.Fire Blast\n   3.Fire Cannon\n   4.Heal\n   5.Run Away" << std::endl;
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

void Charizard::basicAttack(Pokemon& opponent) {
	std::cout << "\n" << name << " zapps " << opponent.getName() << " with a fire beam!\n" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Charizard::specialAttack(Pokemon& opponent) {
	std::cout << "\nFire Blast and lightning, very, very frightnening me!\n" << std::endl;
	std::cout << "\n" << opponent.getName() << " was hit by a Fire Blast.\n Any way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+30));
}

void Charizard::bonusAttack(Pokemon& opponent) {
	std::cout << "Fire Cannons and lightning, very, very frightnening me!" << std::endl;
	std::cout << opponent.getName() << " was hit by a Fire Cannon.\n Any way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+60));
}