#pragma once
#include "Bulbasaur.h"

class Ivysaur : public Bulbasaur {
public:
	Ivysaur();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;
	void specialAttack(Pokemon& opponent);
};