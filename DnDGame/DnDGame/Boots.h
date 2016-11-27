#pragma once


#include "Item.h"
using namespace std;

class Boots : public Item
{
public:

	//Contstructors
	Boots(string name, EnhancementType enhType, int enhBonus);
	Boots(Item*);
	Boots();
	~Boots();

	string getItemType() const;
	const Boots& operator=(const Boots&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};


