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
	
	void createButton(int i);
	void sizeTilemap();
	void buildDisplay(Grid* grid);
	void listDisplay();

	void run();
	void paint(int x, int y);
	void update();
	void buttonAction(int x, int y, bool isclick);
	~BuilderDisplay();

	void drawButtons();
	void drawSprites();
	void seButton();
	void drawSameSprites();
	void drawEditButtons(Grid* grid);

private:

	std::vector< Grid* > gridlist;
	vector < vector < vector < sf::Sprite > > > _tilemaps;

	sf::Text buttonname;
	int numofmapbuttons;
	int numofeditbuttons;

	std::vector< GameButton* > buttons;
	std::vector< GameButton* > editButtons;
	GameButton* saveandexit;

	sf::Vector2f _tilesize2;

	int buildMode;
	int workingGrid;
	int brush;

	int exitType;

	

};

