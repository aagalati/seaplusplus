#pragma once

#include "Item.h"
using std::string;

class Belt : public Item
{

public:
	
	//Construtcors;
	Belt(std::string name, EnhancementType enhType, int enhBonus);
	Belt(Item*);
	Belt();
	~Belt();

	
	std::string getItemType() const;
	
	const Belt& operator=(const Belt&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



