#pragma once


#include "Item.h"
using namespace std;
class Boots : public Item
{
public:
	Boots(string name, EnhancementType enhType, int enhBonus);
	Boots();
	~Boots();

	string getItemType() const;
	const Boots& operator=(const Boots&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};


