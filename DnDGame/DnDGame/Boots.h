#pragma once


#include "Item.h"
using std::string;

class Boots : public Item
{
public:

	//Contstructors
	Boots(std::string name, EnhancementType enhType, int enhBonus);
	Boots(Item*);
	Boots();
	~Boots();

	std::string getItemType() const;
	const Boots& operator=(const Boots&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};


