#include "stdafx.h"
#include "Boots.h"


Boots::Boots(string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	itemType = 4;
}

Boots::Boots(Item* i)
{
	this->name = i->getItemName();
	this->enhType = i->getEnhancementType();
	this->enhBonus = i->getEnhancementBonus();
}
Boots::Boots(){}
Boots::~Boots()
{
}

void Boots::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	if ((enhanceType == ArmorClass) || (enhanceType == Dexterity))
		enhType = enhanceType;
	else {
		cout << "Wrong Enhacement Type for Boots Item. May only be of type: ArmorClass or Dexterity." << endl
			<< "Making Enhancement Type: ArmorClass" << endl;
		enhType = ArmorClass;
	}
	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}

string Boots::getItemType() const
{
	return "Boots";
}

const Boots& Boots:: operator=(const Boots& i)
{
	name = i.name;
	enhType = i.enhType;
	enhBonus = i.enhBonus;
	return *this;
}
