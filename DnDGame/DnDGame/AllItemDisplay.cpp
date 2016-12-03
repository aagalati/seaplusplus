#include "stdafx.h"
#include "AllItemDisplay.h"


AllItemDisplay::AllItemDisplay()
{

	_tilesize.x = 32;
	_tilesize.y = 32;

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeons and Dragons");

	loadFonts();
	loadTextures();

}


AllItemDisplay::~AllItemDisplay()
{
}

void AllItemDisplay::loadItems()
{

	Item* item = new Item();

	container = item->load();

}

void AllItemDisplay::displayfour(int a) {

	int count = 0;
	for (int i = a; i < container.size() && count < 4; i++) {
		count++;
		itemname[i].setString(container[i]->toString());
		//itempack[i].setTextureRect
	}

}

void AllItemDisplay::itemDisplay()
{

	for (int i = 0; i < container.size(); i++) {

		

	}

}
