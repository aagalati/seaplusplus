#pragma once

#include "Item.h"

using namespace std;

class Belt : public Item
{

public:
	
	//Construtcors;
	Belt(string name, EnhancementType enhType, int enhBonus);
	Belt(Item*);
	Belt();
	~Belt();

	
	string getItemType() const;
	
	const Belt& operator=(const Belt&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



