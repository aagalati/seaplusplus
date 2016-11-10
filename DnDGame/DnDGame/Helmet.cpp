#include "stdafx.h"
#include "Helmet.h"


Helmet::Helmet(string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
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
		cout << "Wrong Enhacement Type for Helmet Item. May only be of type: Intelligence, Wisdom, or ArmorClass." << endl;
	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}

string Helmet::getItemType() const
{
	return "Helmet";
}

