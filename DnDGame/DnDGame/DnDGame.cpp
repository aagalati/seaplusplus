// DnDGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Grid.h"



int main()
{

	sf::RenderWindow window(sf::VideoMode(1000, 600), "Dungeons and Dragons");

	enum tiletype {Space, Wall, Object, Entrance, Exit};
	enum bordertype {tlcorner, top, trcorner, right, brcorner, bottom, blcorner, left};

	sf::Vector2i tilesource(32, Wall);
	sf::Vector2i tilesize(32, 32);

	std::vector< std::vector<sf::Sprite> > tilemap;



	int width, height;

	const int BORDER_SIZE = 1;
	const int BORDER = BORDER_SIZE * 2;

	const int PADDING = 32;

	Grid *grid = new Grid(10, 15, false);

	width = 10 + BORDER;
	height = 15 + BORDER;

	


	//sf::CircleShape shape(200.f);
	//shape.setFillColor(sf::Color::Blue);

	sf::Texture tileTexture;
	sf::Texture borderTexture;

	if (!tileTexture.loadFromFile("texture/tiletexture.png"))
		std::cout << "Error: Tile texture not loaded" << std::endl;
	else
		std::cout << "Tile texture loaded" << std::endl;

	if (!borderTexture.loadFromFile("texture/red.png"))
		std::cout << "Error: Border texture not loaded" << std::endl;
	else
		std::cout << "Border texture loaded" << std::endl;
	

	tilemap.resize(width);
	
	for (int i = 0; i < width; i++) {

		tilemap[i].resize(height);
		std::cout << i << std::endl;

		for (int j = 0; j < height; j++) {

			if (i == 0 || j == 0 || i == width - 1 || j == height - 1) {

				tilemap[i][j].setTexture(borderTexture);
				tilemap[i][j].setTextureRect(sf::IntRect(32, 32, 32, 32));
				std::cout << "Creating border at " << i << ", " << j << std::endl;



				/*
				if (i == 0 && j == 0)
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * tlcorner, tilesize.x, tilesize.y));

				else if (j == 0 && (i != width-1 && i != 0))
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * top, tilesize.x, tilesize.y));

				else if (i == width-1 && j == 0)
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * trcorner, tilesize.x, tilesize.y));

				else if (i == width-1 && j != 0 && j != height-1)
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * right, tilesize.x, tilesize.y));

				else if (i == width-1 && j == height-1)
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * blcorner, tilesize.x, tilesize.y));

				else if (i != 0 && j == height-1 && i != width-1)
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * bottom, tilesize.x, tilesize.y));

				else if (i == 0 && j == height-1)
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * blcorner, tilesize.x, tilesize.y));

				else if (i == 0 && j != 0 && j!= height-1)
					tilemap[i][j].setTextureRect(sf::IntRect(tilesize.x, tilesize.y * left, tilesize.x, tilesize.y));
				*/
			}
			else {


				tilemap[i][j].setTexture(tileTexture);
				std::cout << "Creating tile at " << i << ", " << j << std::endl;
				if (grid->getCellValue(i - 1, j - 1) == Space)
					tilesource.y = Space;
				else if (grid->getCellValue(i - 1, j - 1) == Wall)
					tilesource.y = Wall;
				else if (grid->getCellValue(i - 1, j - 1) == Object)
					tilesource.y = Space;
				else if (grid->getCellValue(i - 1, j - 1) == Entrance)
					tilesource.y = Entrance;
				else if (grid->getCellValue(i - 1, j - 1) == Exit)
					tilesource.y = Exit;

				std::cout << "Texture will be " << tilesource.y << std::endl;

				tilemap[i][j].setTextureRect(sf::IntRect(0, tilesource.y * 32, 32, 32));
			}

			tilemap[i][j].setPosition(tilesize.x * i + PADDING, tilesize.y * j + PADDING);
			//tilemap[i][j].setTextureRect(sf::IntRect(tilesource.x, 64, 32, 32));
			


		}


	}


	//std::cout << "Get cell value: " << grid->getCellValue(-1, -1);

	//playtile.setTexture(tileTexture);
	//playtile.setPosition(100, 100);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Event::KeyPressed) {
				switch (event.key.code) {

				//case sf::Keyboard::Up: 
					//if(grid->getCellValue()
					//break;



				}
					
			}


		}

		for (int i = 0; i < width; i++) {

			for (int j = 0; j < height; j++) {


				//if (!(i == 0 || j == 0 || i == width - 1 || j == height - 1))
					//tilemap[i][j].setTextureRect(sf::IntRect(tilesource.x, tilesource.y * 32, 32, 32));

				//std::cout << "Drawing tilemap at " << i << ", " << j << std::endl;
				window.draw(tilemap[i][j]);

			}


		}

		

		//window.draw(tilemap[0][0]);

		//playtile.setTextureRect(sf::IntRect(tilesource.x, tilesource.y * 32, 32, 32));
		//window.clear();
		//window.draw(playtile);
		window.display();

	}

    return 0;
}

