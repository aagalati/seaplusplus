#pragma once
#include "Observer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Grid.h"
#include "DNDObject.h"
#include "GameButton.h"
#include "TextButton.h"

class Display : public Observer
{
public:

	//Constructors
	Display(Grid *grid, int type);
	Display();
	~Display();

	//Loading map visuals
	void loadFonts();
	void loadTextures();
	void loadSprites();

	//Main menu
	void menuDisplay();
	void buttonAction(int x, int y, bool isClick);

	void builderDisplay();

	//Program maintenance
	void update();
	bool windowOpen();
	void run();

	//Information Relayer to User
	void showInfo(DNDObject* hover);
	void gridHover(int x, int y);
	void keyPressed(sf::Event event);


	//Maintenance booleans
	bool goplay;
	bool gobuilder;
	bool goitem;
	bool goexit;

private:

	//Relevant GUI attributes.
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

	sf::RectangleShape button1;
	sf::RectangleShape button2;
	sf::RectangleShape button3;
	sf::RectangleShape button4;

	vector< TextButton* > textbuttons; //for menu

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

