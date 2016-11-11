#pragma once

#include "Item.h"
using namespace std;
class Belt : public Item
{
public:
	Belt(string name, EnhancementType enhType, int enhBonus);
	Belt();
	~Belt();

	string getItemType() const;
	const Belt& operator=(const Belt&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



