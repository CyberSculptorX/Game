/* Charmander
   Method Definitions
*/
#include <iostream>
#include "Charmander.h"
#include "Charmeleon.h"

//Constructor
Charmander::Charmander() : Pokemon("Charmander", "Fire", 200, 25) {};

Pokemon* Charmander::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Fire Beam\n   2.Heal\n   3.Run Away";
	if (experience > 50) {
		std::cout << "\n   4.Evolve";
	}
	std::cout << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		std::cout << std::endl;
		basicAttack(opponent);
	}
	else if (choice == 2) {
		std::cout << std::endl;
		heal(20);
	}
	else if (choice == 3) {
		std::cout << std::endl;
		if (runAway()) {
			health = 0; //end the battle using health=0 for now.
		}
	}
	else if (choice == 4) {
		std::cout << std::endl;
		if (experience < 50) {
			std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
		}
		else {
			std::cout << "======================================================================\n" <<
				"In a sudden swirl of light, Charmander has evolved to Charmeleon!\n" <<
				"======================================================================" << std::endl;
			return new Charmeleon();
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

void Charmander::basicAttack(Pokemon& opponent) {
	std::cout << "\n" << name << " zapps " << opponent.getName() << " with a fire beam!\n" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}