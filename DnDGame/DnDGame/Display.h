#pragma once
#include "Observer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Grid.h"
#include "DNDObject.h"

class Display : public Observer
{
public:
	Display(Grid *grid);
	Display();

	void loadFonts();
	void loadTextures();
	void loadSprites();

	void menuDisplay();
	void buttonToRight();
	void buttonToLeftBottom();

	void update();
	bool windowOpen();
	void run();

	void showInfo(DNDObject* hover);
	void gridHover(int x, int y);
	void keyPressed(sf::Event event);

	~Display();
	
private:

	sf::RenderWindow _window;

	sf::Vector2i _tilesource;
	sf::Vector2i _tilesize;
	sf::Vector2u _windowsize;

	sf::Vector2f _buttonposition;
	sf::Vector2f _buttonsize;

	sf::Vector2f _headersize;
	sf::Vector2f _headerposition;

	sf::Texture tileTexture;
	sf::Texture borderTexture;

	sf::Font font;
	sf::Text text;

	sf::Event _event;

	std::vector< sf::RectangleShape > _buttonmap;
	std::vector< std::vector<sf::Sprite> > _tilemap;

	enum tiletype { Space, Wall, Object, Entrance, Exit, Player };
	enum bordertype { tlcorner, top, trcorner, right, brcorner, bottom, blcorner, left };
	enum windowtype {menu, game, itemcreator, mapcreator};

	int _type;
	int _width;
	int _height;
	int _playerX;
	int _playerY;
	//int _cellValue; use as temp variable
	//bool refresh;

	int BORDER_SIZE;
	int BORDER;
	int PADDINGX;
	int PADDINGY;

	Grid *grid;
	GridObserver *gridObs;

};

