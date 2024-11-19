
/* POKEMON CLASS METHODS
 */

#include <iostream>
#include "Pokemon.h"

//Constructor
Pokemon::Pokemon(std::string n, std::string t, int h, int s) {
	name = n;
	type = t;
	health = h;
	strength = s;
	max_health = health;
	experience = 0;
}

//Methods

/// <summary>
/// Ask to perform an action for this pokemon. attack, heal, or run.
/// </summary>
/// <param name="opponent">Pokemon opponent</param>
Pokemon* Pokemon::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Attack\n   2.Heal\n   3.Run Away" << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		basicAttack(opponent);
	}
	else if (choice == 2) {
		heal(20);
	}
	else if (choice == 3) {
		if (runAway()) {
			health = 0; //end the battle using health=0 for now.
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

/// <summary>
/// This pokemon performs a basic attack on opponent
/// </summary>
/// <param name="opponent">Opposing Pokemon</param>
void Pokemon::basicAttack(Pokemon& opponent) {
	std::cout << name << " attacks " << opponent.name << " with a basic attack " << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

/// <summary>
/// Calculate the new damage adjusting to strengths and weaknesses against types
/// </summary>
/// <param name="opponent">Opposing pokemon</param>
/// <param name="damage">original damage</param>
/// <returns></returns> 
int Pokemon::calculateDamage(Pokemon& opponent, int damage) {
	if (type == "Grass") {
		if (opponent.type == "Fire") {
			//Grass is weak against fire so reduce the damage the fire type receives
			return damage / 2; //this is an integer division
		}
		else if (opponent.type == "Water") {
			//Grass is strong against water so multiply the damage to the water type.
			return damage * 2;
		}
		else if (opponent.type == "Electric") {
			//Grass is weak against electric so damage the grass type.
			return damage * 2;
		}
	}
	if (type == "Water") {
		if (opponent.type == "Fire") {
			//Water is strong against fire types, double the damage
			return damage * 2;
		}
		else if (opponent.type == "Grass") {
			//Water is stron to grass so half the damage
			return damage * 2;
		}
		else if (opponent.type == "Electric") {
			//Grass is weak against electric so damage the grass type.
			return damage / 2;
		}
	}
	if (type == "Fire") {
		if (opponent.type == "Water") {
			//Fire is weak to water, so half the damage
			return damage / 2;
		}
		else if (opponent.type == "Grass") {
			//Fire is strong against grass so double the damage
			return damage * 2;
		}
		else if (opponent.type == "Electric") {
			//Fire is stron against electric so damage the grass type.
			return damage * 2;
		}
	}
	if (type == "Electric") {
		if (opponent.type == "Water") {
			//Electric is weak to water, so half the damage
			return damage / 2;
		}
		else if (opponent.type == "Grass") {
			//Electric is strong against grass so double the damage
			return damage * 2;
		}
		else if (opponent.type == "Fire") {
			//Electric is weak against electric so damage the grass type.
			return damage / 2;
		}
	}
}

/// <summary>
/// Heal a pokemon by an amount. health can't be greater than max_health.
/// </summary>
/// <param name="amount">amount to heal</param>
void Pokemon::heal(int amount) {
	std::cout << "You heal " << name << "." << std::endl;
	health += amount;
	if (health > max_health){
		health = max_health;
		std::cout << name << " is fully healed!" << std::endl;
	}
}

/// <summary>
/// There's a 25% chance they will successfully flee the fight.
/// </summary>
/// <returns>True if successful, false if not.</returns>
bool Pokemon::runAway() {
	if (rand() % 100 < 25) {
		std::cout << name << " successfully flees from the fight and clambers back into his Pokeball." << std::endl;
		return true;
	}
	else {
		std::cout << name << " couldn't get away!" << std::endl;
	}
	return false;
}


/// <summary>
/// Pokemon takes an amount of damage sapping his health
/// </summary>
/// <param name="damage">amount of damage taken.</param>
void Pokemon::takeDamage(int damage) {
	health -= damage;
	std::cout << name << " takes " << damage << " damage! Health is now " << health << "." << std::endl;
	if (health <= 0) {
		std::cout << name << " has fainted!" << std::endl;
		health = 0;  // Ensure health does not go below zero
	}
}

/// <summary>
/// Getter for pokemon's health.
/// </summary>
/// <returns>Health as integer</returns>
int Pokemon::getHealth() {
	return health;
}

/// <summary>
/// Getter for Pokemon's Name.
/// </summary>
/// <returns>Pokemon's name</returns>
std::string Pokemon::getName() {
	return name;
}

/// <summary>
/// function to gain a bit of experience.
/// </summary>
void Pokemon::gainExperience() {
	experience += 10;
}

std::ostream& operator<<(std::ostream& os, const Pokemon& p) {
	os << "___" << p.name << " the " << p.type << " pokemon ____________________" << "\n" <<
		"  Health:     " << p.health << "\n" <<
		"  Strength:   " << p.strength << "\n" <<
		"  Experience: " << p.experience << "\n" <<
		"___________________________________________________" << std::endl;
	return os;
}
