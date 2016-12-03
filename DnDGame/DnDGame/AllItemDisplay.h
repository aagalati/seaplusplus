#pragma once
#include "Display.h"
#include "Item.h"
#include <vector>

class AllItemDisplay :
	public Display
{
public:
	AllItemDisplay();
	~AllItemDisplay();
	void loadItems();
	void displayfour(int i);
	void itemDisplay();

private:

	std::vector < Item* > container;
	std::vector < sf::Sprite > itempack;
	std::vector < sf::Text > itemname;

	int tilesource;
	enum itemtype {shield, weapon, armor, boots, belt, ring, helmet};

};

