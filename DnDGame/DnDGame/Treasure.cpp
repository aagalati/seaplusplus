#include "stdafx.h"
#include "Treasure.h"


Treasure::Treasure() : ItemContainer(1)
{
	
}


Treasure::~Treasure()
{
	
}

int Treasure::type()
{
	return _type;
}

string Treasure::toString()
{
	if (!accessible)
		return "Treasure";
	
	else
	{
		/*string content = "";
		while (contained);
		{
			content += contained.iter.toString();
		}*/
	}
}
