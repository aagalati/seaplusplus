#include "stdafx.h"
#include "Ring.h"


Ring::Ring(string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	itemType = 6;
}

Ring::Ring(Item* i)
{
	this->name = i->getItemName();
	this->enhType = i->getEnhancementType();
	this->enhBonus = i->getEnhancementBonus();
	itemType = 6;
}
Ring::Ring(){}
Ring::~Ring()
{
}

void Ring::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	if ((enhanceType == ArmorClass) || (enhanceType == Strength) || (enhanceType == Constitution) || (enhanceType == Wisdom) || (enhanceType == Charisma))
		enhType = enhanceType;
	else {
		std::cout << "Wrong Enhacement Type for Belt Item. May only be of type: ArmorClass, Strength, Constitution, Wisdom, or Charisma." << std::endl
			<< "Making Enhancement Type: ArmorClass" << std::endl;
		enhType = ArmorClass;
	}
	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}

string Ring::getItemType() const
{
	return "Ring";
}

const Ring& Ring:: operator=(const Ring& i)
{
	name = i.name;
	enhType = i.enhType;
	enhBonus = i.enhBonus;
	return *this;
}
