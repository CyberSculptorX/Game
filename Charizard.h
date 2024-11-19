#pragma once
#include "Charmeleon.h"

class Charizard : public Charmeleon {
public:
	Charizard();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;
	void specialAttack(Pokemon& opponent);
	void bonusAttack(Pokemon& opponent);

};
