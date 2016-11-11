#pragma once
#include "Item.h"

using namespace std;

class Weapon : public Item
{
public:

	//Constructors
	Weapon(string name, EnhancementType enhType, int enhBonus);
	Weapon();
	~Weapon();

	string getItemType() const;
	const Weapon& operator=(const Weapon&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



