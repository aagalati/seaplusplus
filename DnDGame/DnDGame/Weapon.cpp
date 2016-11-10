#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
}
Weapon::Weapon(){}
Weapon::~Weapon()
{
}

void Weapon::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	if ((enhanceType == AttackBonus) || (enhanceType == DamageBonus))
		enhType = enhanceType;
	else {
		cout << "Wrong Enhacement Type for Weapon Item. May only be of type: AttackBonus or DamageBonus." << endl
			<< "Making Enhancement Type: AttackBonus" << endl;
		enhType = AttackBonus;
	}
	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}

string Weapon::getItemType() const
{
	return "Weapon";
}
