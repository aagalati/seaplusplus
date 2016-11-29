#pragma once

#include "Item.h"

using std::string;

class Shield : public Item
{
public:

	//Constructors;
	Shield(std::string name, EnhancementType enhType, int enhBonus);
	Shield(Item*);
	Shield();
	~Shield();

	std::string getItemType() const;
	const Shield& operator=(const Shield&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};


