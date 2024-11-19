#pragma once
#include <iostream>
#include "Pokemon.h"

class Game {
public:
	Pokemon* playerPokemon;
	Pokemon* opponentPokemon;

	void start();

private:
	Pokemon* SelectPokemon(std::string Prompt);
	void Battle();
};
