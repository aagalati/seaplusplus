#pragma once

#ifndef BELT_H
#define BELT_H

#include "Item.h"

class Belt : public Item
{
public:
	Belt(string name, EnhancementType enhType, int enhBonus);
	Belt();
	~Belt();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

