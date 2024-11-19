#pragma once
#include <iostream>
#include "Pokemon.h"

class Squirtle : public Pokemon {

public:
	Squirtle();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;

};