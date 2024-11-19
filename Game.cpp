/* GAME CLASS METHODS
 */

#include <iostream>
#include "Game.h"
#include "Pikachu.h"
#include "Squirtle.h"
#include "Bulbasaur.h"
#include "Charmander.h"

/// <summary>
/// Start the Simulator by choosing pokemon and battling.
/// </summary>
void Game::start() {
	playerPokemon = SelectPokemon("Choose Your Pokemon");
	opponentPokemon = SelectPokemon("Choose Your Opponent");
	Battle();
}

/// <summary>
/// Select a pokemon and return it.
/// </summary>
/// <param name="prompt">Prompt who the pokemon is for</param>
/// <returns>new Pokemon object</returns>
Pokemon* Game::SelectPokemon(std::string prompt) {
	int choice;
	std::cout << std::endl;
	std::cout << "   1. Pikachu\n   2. Charmander\n   3. Squirtle\n   4. Bulbasaur" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 1: std::cout << " \nPikachu pops up on to his feet and is ready to battle." << std::endl;
		return new Pikachu();
	case 2: std::cout << " \nCharmander clambers to his feet and is ready to battle." << std::endl;
		return new Charmander();
	case 3: std::cout << " \nSquirtle splashes with his feet and is ready to battle." << std::endl;
		return new Squirtle();
	case 4: std::cout << " \nBulbasaur bounces into action and is ready to battle." << std::endl;
		return new Bulbasaur();
	default:
		std::cout << "Invalid Choice! You're getting a Jigglypuff!" << std::endl;
		return new Pokemon("JigglyPuff", "Fairy", 10, 1);
	}
}

/// <summary>
/// Run the battle simulator while nobody is dead. Take turns.
/// </summary>
void Game::Battle() {
	while ((playerPokemon->getHealth() > 0) && (opponentPokemon->getHealth() > 0)) {
		std::cout << "\nYour Turn!\n"<< "\n" << * playerPokemon << std::endl;
		playerPokemon = playerPokemon->actionMenu(*opponentPokemon);
		playerPokemon->gainExperience();

		if (opponentPokemon->getHealth() > 0) {
			std::cout << "\nOpponent's Turn!\n" << "\n" << * opponentPokemon << std::endl;
			opponentPokemon = opponentPokemon->actionMenu(*playerPokemon);
			opponentPokemon->gainExperience();
		}
	}
	std::cout << "\n\nBATTLE ENDS!" << std::endl;
}

