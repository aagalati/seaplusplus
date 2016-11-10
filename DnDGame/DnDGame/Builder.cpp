#include "stdafx.h"
#include "Builder.h"


Builder::Builder()
{

}

Builder::Builder(int t)
{
	_type = t;
}


Builder::~Builder()
{
}

DNDObject* Builder::build(int i)
{
	int t = i;

	switch (t)
	{
	case -1:
		{
			Structure* floor = new Structure(-1);
			return floor;
		}
	case 0:
		{
				Structure* floor = new Structure(0);
				return floor;
		}
	case 1:
		{
				Structure* wall = new Structure(1);
				return wall;
		}
	case 2:
		{
				Treasure* treasure = new Treasure();
				return treasure;
		}
	case 3:
		{
				Structure* entrance = new Structure(3);
				return entrance;
		}
	case 4:
		{		
				Structure* exit = new Structure(4);
				return exit; 
		}
	case 5:
		{		Character* player = new Character(1, "Hero");
				return player;
		}
	case 6:
		{		Character* enemy = new Character(1, "Possibly A Spooky Skeleton", 6);
				return enemy;
		}
	case 7:
		{		Character* aFriend = new Character(1, "Harambe", 7);
				return aFriend;
		}
	default:
		{
			   DNDObject* p = NULL;
			   return p;
		}
	}
}

