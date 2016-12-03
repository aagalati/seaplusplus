#pragma once
#include "DNDObject.h"
#include "ItemContainer.h"

using std::string;



//Item container in map;
class Treasure : public ItemContainer
{
private:
	
	int _type = 2;

public:

	Treasure();
	Treasure(ItemContainer);
	~Treasure();

	int type();

	Treasure toTreasure(ItemContainer);
	std::string toString();
};

