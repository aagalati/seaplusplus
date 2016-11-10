
#ifndef RING_H
#define RING_H

#include "Item.h"

class Ring : public Item
{
public:
	Ring(string name, EnhancementType enhType, int enhBonus);
	Ring();
	~Ring();

	string getItemType() const;

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

