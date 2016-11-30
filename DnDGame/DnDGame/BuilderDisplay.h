#pragma once
#include "Display.h"
#include "Grid.h"
#include "GameButton.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using std::vector;

class BuilderDisplay :
	public Display
{
public:

	BuilderDisplay();
	BuilderDisplay(std::vector< Grid*> gridlist);
	void drawSprites();
	void sizeTilemap();
	void buildDisplay();
	void listDisplay();
	void drawButtons();
	void run();
	void update();
	void buttonAction(int x, int y, bool isclick);
	~BuilderDisplay();

private:

	std::vector< Grid* > gridlist;
	sf::Text buttonname;
	int numofbuttons;
	int exitType;

	vector < vector < vector < sf::Sprite > > > _tilemaps;

};

