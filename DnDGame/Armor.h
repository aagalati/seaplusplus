#pragma once

#include "Item.h"

using namespace std;
class Armor : public Item

{
public:

	//Constructors;
	Armor(string name, EnhancementType enhType, int enhBonus);
	Armor(Item*);
	Armor();
	~Armor();

	
	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

	const Armor& operator=(const Armor&);

};


