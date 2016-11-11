#pragma once

#ifndef HELMET_H
#define HELMET_H

#include "Item.h"

using namespace std;
class Helmet : public Item
{

public:
	
	//Constructors
	Helmet(string name, EnhancementType enhType, int enhBonus);
	Helmet();
	~Helmet();

	string getItemType() const;
	const Helmet& operator=(const Helmet&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

