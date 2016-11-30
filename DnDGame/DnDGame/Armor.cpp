#include "stdafx.h"
#include "Armor.h"


Armor::Armor(std::string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	this->enhType = ArmorClass;
	itemType = 1;
}

Armor::Armor(Item *i)
{
	this->name = i->getItemName();
	this->enhType = i->getEnhancementType();
	this->enhBonus = i->getEnhancementBonus();
	itemType = 1;
}

Armor::~Armor()
{
}
Armor::Armor(){}

void Armor::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	if (enhanceType == ArmorClass)
		enhType = enhanceType;
	else {
		std::cout << "Wrong Enhacement Type for Armor Item. May only be of type: ArmorClass." << std::endl
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

std::string Armor::getItemType() const
{
	return "Armor";
}

const Armor& Armor:: operator=(const Armor& i)
{
	name = i.name;
	enhType = i.enhType;
	enhBonus = i.enhBonus;
	return *this;
}