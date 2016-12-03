#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(std::string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	itemType = 2;
	range = 1;
}
Weapon::Weapon(std::string name, EnhancementType enhType, int enhBonus, int _range, int x, int diceType) : Weapon (name, enhType, enhBonus)
{
	range = _range;
	Dice d(x, diceType);
	dmgRoll = d;
}

Weapon::Weapon(Item* i)
{
	
	this->name = i->getItemName();
	this->enhType = i->getEnhancementType();
	this->enhBonus = i->getEnhancementBonus();
	this->range = i->getRange();
	itemType = 2;
	this->dmgRoll = i->getDmgRoll();
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
		std::cout << "Wrong Enhacement Type for Weapon Item. May only be of type: AttackBonus or DamageBonus." << std::endl
			<< "Making Enhancement Type: AttackBonus" << std::endl;
		enhType = AttackBonus;
	}
	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}

std::string Weapon::getItemType() const
{
	return "Weapon";
}

const Weapon& Weapon:: operator=(const Weapon& i)
{
	name = i.name;
	enhType = i.enhType;
	enhBonus = i.enhBonus;
	range = i.range;
	dmgRoll = i.dmgRoll;
	return *this;
}
