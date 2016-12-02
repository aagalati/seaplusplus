#include "stdafx.h"
#include "Combat.h"


Combat::Combat()
{
}

Combat::Combat(Weapon w)
{
	Dice a (1, 20);
	Dice b (1, 20);

	initiative = a;
	attackRoll = b;
	dmg = &w.getDmgRoll();

}

void Combat::rollInitiative()
{
	initiative.roll();
}

int Combat::attack(int strMod, int AC, int MDam)
{
	attackRoll.roll();
	attackRoll.setValue(attackRoll.getValue() + strMod);
	if (attackRoll.getValue() > AC)
	{
		dmg->roll();
		dmg->setValue(dmg->getValue() + MDam);
		return dmg->getValue();
		
	}
	return 0;
	
}

Combat::~Combat()
{

}
