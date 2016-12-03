#include "stdafx.h"
#include "Treasure.h"


Treasure::Treasure() : ItemContainer()
{
	accessible = false;
}



Treasure::~Treasure()
{
	
}



Treasure::Treasure(ItemContainer loot) : ItemContainer(loot)
{
	accessible = false;
}

int Treasure::type()
{
	return _type;
}

std::string Treasure::toString()
{
	if (!accessible)
		return "Treasure";
	else
		return ItemContainer::toString();
}

Treasure Treasure::toTreasure(ItemContainer loot)
{
	Treasure treasure(loot);
	return treasure;

}