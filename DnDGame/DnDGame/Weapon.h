

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(string name, EnhancementType enhType, int enhBonus);
	Weapon();
	~Weapon();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

