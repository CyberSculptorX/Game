#pragma once
#include "Ivysaur.h"

class Venusaur : public Ivysaur {
public:
	Venusaur();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;
	void specialAttack(Pokemon& opponent);
	void bonusAttack(Pokemon& opponent);

};
