#include "stdafx.h"
#include "Armor.h"


Armor::Armor(string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
	this->enhType = ArmorClass;
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
		cout << "Wrong Enhacement Type for Armor Item. May only be of type: ArmorClass." << endl
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

string Armor::getItemType() const
{
	return "Armor";
}