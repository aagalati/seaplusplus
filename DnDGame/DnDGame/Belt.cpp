#include "stdafx.h"
#include "Belt.h"


Belt::Belt(string name, EnhancementType enhType, int enhBonus) : Item(name, enhType, enhBonus)
{
}
Belt::Belt(){}
Belt::~Belt()
{
}

void Belt::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	if ((enhanceType == Constitution) || (enhanceType == Strength))
		enhType = enhanceType;
	else {
		cout << "Wrong Enhacement Type for Belt Item. May only be of type: Constitution or Strength." << endl
			<< "Making Enhancement Type: Constitution" << endl;
		enhType = Constitution;
	}
	if (enhanceBonus >= 0 && enhanceBonus <= 5)
		enhBonus = enhanceBonus;
	else if (enhBonus > 5)
		enhBonus = (enhanceBonus % 6) + 1;
	else
		enhBonus = 0;
}
 
string Belt::getItemType() const
{
	return "Belt";
}
