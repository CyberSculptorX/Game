#pragma once
#include <iostream>
#include "Pokemon.h"

class Bulbasaur : public Pokemon {

public:
	Bulbasaur();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;

};