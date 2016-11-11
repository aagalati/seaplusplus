#pragma once

#include "Item.h"

using namespace std;
class Armor : public Item

{
public:

	
	
	Armor(string name, EnhancementType enhType, int enhBonus);
	Armor();
	~Armor();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

	const Armor& operator=(const Armor&);

};


