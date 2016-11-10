

#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

class Shield : public Item
{
public:
	Shield(string name, EnhancementType enhType, int enhBonus);
	Shield();
	~Shield();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

