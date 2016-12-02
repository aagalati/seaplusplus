#pragma once
#include "Item.h"

using std::string;

class Weapon : public Item
{
public:

	//Constructors
	Weapon(std::string name, EnhancementType enhType, int enhBonus);
	Weapon(std::string name, EnhancementType enhType, int enhBonus, int _range, int x, int diceType);
	Weapon(Item*);
	Weapon();
	~Weapon();

	std::string getItemType() const;
	const Weapon& operator=(const Weapon&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



