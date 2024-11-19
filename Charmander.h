#pragma once
#include <iostream>
#include "Pokemon.h"

class Charmander : public Pokemon {

public:
	Charmander();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;

};