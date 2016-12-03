#pragma once
#include "Display.h"
#include "Item.h"
#include <vector>
#include "GameButton.h"

class AllItemDisplay :
	public Display
{
public:
	AllItemDisplay();
	~AllItemDisplay();
	void loadItems();
	void displayfour(int i);
	void drawMoveButtons();
	void itemDisplay();
	void run();
	void buttonAction(int x, int y, bool isclick);
	void update();

private:

	std::vector < Item* > container;
	std::vector < sf::Sprite > itempack;
	std::vector < sf::Text > itemname;

	std::vector < GameButton* > moveButtons;
	std::vector < GameButton* > itemButtons;

	int numofmovebuttons;
	int currentShow;
	int source;
	enum itemtype {empty, armor, weapon, shield, boots, belt, ring, helmet};

};

