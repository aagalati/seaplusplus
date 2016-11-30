#pragma once

#ifndef HELMET_H
#define HELMET_H

#include "Item.h"

using std::string;

class Helmet : public Item
{

public:
	
	//Constructors
	Helmet(std::string name, EnhancementType enhType, int enhBonus);
	Helmet(Item*);
	Helmet();
	~Helmet();

	std::string getItemType() const;
	const Helmet& operator=(const Helmet&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};

#endif

