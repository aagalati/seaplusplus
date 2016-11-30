#include "stdafx.h"
#include "Helmet.h"


Helmet::Helmet(std::string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	itemType = 7;
}


Helmet::Helmet(Item* i)
{
	this->name = i->getItemName();
	this->enhType = i->getEnhancementType();
	this->enhBonus = i->getEnhancementBonus();
	itemType = 7;
}

Helmet::~Helmet()
{
}

Helmet::Helmet(){}

void Helmet::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	if ((enhanceType == Intelligence) || (enhanceType == Wisdom) || (enhanceType == ArmorClass))
		enhType = enhanceType;
	else
		std::cout << "Wrong Enhacement Type for Helmet Item. May only be of type: Intelligence, Wisdom, or ArmorClass." << std::endl;
	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}

std::string Helmet::getItemType() const
{
	return "Helmet";
}

const Helmet& Helmet:: operator=(const Helmet& i)
{
	name = i.name;
	enhType = i.enhType;
	enhBonus = i.enhBonus;
	return *this;
}
