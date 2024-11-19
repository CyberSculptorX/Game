#pragma once
#include "Pikachu.h"

class Raichu : public Pikachu {
public:
	Raichu();

	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;
	void specialAttack(Pokemon& opponent);
};
