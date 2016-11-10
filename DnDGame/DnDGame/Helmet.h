#pragma once

#ifndef HELMET_H
#define HELMET_H

#include "Item.h"

class Helmet : public Item
{
public:
	Helmet(string name, EnhancementType enhType, int enhBonus);
	Helmet();

	~Helmet();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

