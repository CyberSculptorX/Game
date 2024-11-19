#pragma once
#include "Charmander.h"


class Charmeleon : public Charmander {
public:
	Charmeleon();
	
	Pokemon* actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;
	void specialAttack(Pokemon& opponent);
};
