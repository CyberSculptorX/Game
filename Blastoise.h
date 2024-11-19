#pragma once
#include "Wartortle.h"

class Blastoise : public Wartortle {
public:
	Blastoise();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;
	void specialAttack(Pokemon& opponent);
	void bonusAttack(Pokemon& opponent);

};
