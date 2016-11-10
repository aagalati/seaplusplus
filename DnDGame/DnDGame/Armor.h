#pragma once

#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item
{
public:
	Armor(string name, EnhancementType enhType, int enhBonus);
	Armor();
	~Armor();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

