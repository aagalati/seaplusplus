#include "stdafx.h"
#include "Shield.h"


Shield::Shield(std::string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	this->enhType = ArmorClass;
	itemType = 3;
}

Shield::Shield(Item* i)
{
	this->name = i->getItemName();
	this->enhType = i->getEnhancementType();
	this->enhBonus = i->getEnhancementBonus();
	itemType = 3;
}
Shield::Shield(){}
Shield::~Shield()
{
}

void Shield::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	if (enhanceType != ArmorClass)
		enhType = ArmorClass;
	else
		enhType = enhanceType;

	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}

std::string Shield::getItemType() const
{
	return "Shield";
}

const Shield& Shield:: operator=(const Shield& i)
{
	name = i.name;
	enhType = i.enhType;
	enhBonus = i.enhBonus;
	return *this;
}