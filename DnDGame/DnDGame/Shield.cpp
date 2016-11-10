#include "stdafx.h"
#include "Shield.h"


Shield::Shield(string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	this->enhType = ArmorClass;
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

string Shield::getItemType() const
{
	return "Shield";
}
