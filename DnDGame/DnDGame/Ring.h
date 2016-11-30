#pragma once
#include "Item.h"

using std::string;

class Ring : public Item
{
public:

	//Constructors
	Ring(std::string name, EnhancementType enhType, int enhBonus);
	Ring(Item*);
	Ring();
	~Ring();

	std::string getItemType() const;
	const Ring& operator=(const Ring&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



