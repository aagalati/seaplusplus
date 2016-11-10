#pragma once
#include "Observer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Grid.h"

class Display : public Observer
{
public:
	Display(Grid *grid);
	void loadTextures();
	void loadSprites();
	void update();
	bool windowOpen();
	void run();
	void keyPressed(sf::Event event);
	~Display();
	
private:

	sf::RenderWindow _window;

	sf::Vector2i _tilesource;
	sf::Vector2i _tilesize;
	sf::Vector2u _windowsize;

	sf::Texture tileTexture;
	sf::Texture borderTexture;

	sf::Event _event;

	std::vector< std::vector<sf::Sprite> > _tilemap;

	enum tiletype { Space, Wall, Object, Entrance, Exit, Player };
	enum bordertype { tlcorner, top, trcorner, right, brcorner, bottom, blcorner, left };

	int _width;
	int _height;
	int _playerX;
	int _playerY;
	//int _cellValue; use as temp variable
	//bool refresh;

	int BORDER_SIZE;
	int BORDER;
	int PADDING;

	bool key;

	Grid *grid;
	GridObserver *gridObs;

};

