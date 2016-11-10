#pragma once

#ifndef BOOTS_H
#define BOOTS_H

#include "Item.h"

class Boots : public Item
{
public:
	Boots(string name, EnhancementType enhType, int enhBonus);
	Boots();
	~Boots();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

