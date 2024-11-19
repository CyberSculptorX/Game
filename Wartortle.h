#pragma once
#include "squirtle.h"

class Wartortle : public Squirtle {
public:
	Wartortle();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;
	void specialAttack(Pokemon& opponent);
};