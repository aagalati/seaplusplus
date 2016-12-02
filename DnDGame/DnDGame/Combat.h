#pragma once
#include "Weapon.h"
class Combat
{
public:
	Combat();
	Combat(Weapon);

	void rollInitiative();
	int attack(int, int, int);

	int getInitiative() { return initiative.getValue(); }
	int getAttackRoll() { return attackRoll.getValue(); }
	int getDmg() { return dmg->getValue(); }

	~Combat();
private:

	Dice initiative;
	Dice *dmg;
	Dice attackRoll;
};

