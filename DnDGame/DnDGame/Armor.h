#pragma once

#include "Item.h"
using std::string;

class Armor : public Item

{
public:

	//Constructors;
	Armor(std::string name, EnhancementType enhType, int enhBonus);
	Armor(Item*);
	Armor();
	~Armor();

	
	std::string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

	const Armor& operator=(const Armor&);

};


