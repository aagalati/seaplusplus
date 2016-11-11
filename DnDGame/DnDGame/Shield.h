#pragma once

#include "Item.h"
using namespace std;

class Shield : public Item
{
public:

	//Constructors;
	Shield(string name, EnhancementType enhType, int enhBonus);
	Shield();
	~Shield();

	string getItemType() const;
	const Shield& operator=(const Shield&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};


