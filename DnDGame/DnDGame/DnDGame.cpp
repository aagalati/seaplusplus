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

	window.setKeyRepeatEnabled(false);

	enum tiletype {Space, Wall, Object, Entrance, Exit, Player};
	enum bordertype {tlcorner, top, trcorner, right, brcorner, bottom, blcorner, left};

	sf::Vector2i tilesource(32, Wall);
	sf::Vector2i tilesize(32, 32);

	std::vector< std::vector<sf::Sprite> > tilemap;

	int width, height;
	int playerX, playerY;
	int cellValue;
	int frames = 0;
	bool refresh = false;

	const int BORDER_SIZE = 1;
	const int BORDER = BORDER_SIZE * 2;

	const int PADDING = 32;

	width = 5;
	height = 5;

	Grid *grid = new Grid(width, height, false);

	width += BORDER;
	height += BORDER;

	while (!grid->checkValid()) {
		grid->fillMapRandom();
	}

	playerX = grid->getEntranceX();
	playerY = grid->getEntranceY();

	//sf::CircleShape shape(200.f);
	//shape.setFillColor(sf::Color::Blue);

	sf::Texture tileTexture;
	sf::Texture borderTexture;

	if (!tileTexture.loadFromFile("texture/tiletexture.png"))
		std::cout << "Error: Tile texture not loaded" << std::endl;
	else
		std::cout << "Tile texture loaded" << std::endl;

	if (!borderTexture.loadFromFile("texture/wall.png"))
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
				cellValue = grid->getCellValue(i - 1, j - 1);
				if (cellValue == Space)
					tilesource.y = Space;
				else if (cellValue == Wall)
					tilesource.y = Wall;
				else if (cellValue == Object)
					tilesource.y = Space;
				else if (cellValue == Entrance)
					tilesource.y = Entrance;
				else if (cellValue == Exit)
					tilesource.y = Exit;
				else if (cellValue == Player)
					tilesource.y = Player;

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

	for (int i = 0; i < width; i++) {

		for (int j = 0; j < height; j++) {


			//if (!(i == 0 || j == 0 || i == width - 1 || j == height - 1))
			//tilemap[i][j].setTextureRect(sf::IntRect(tilesource.x, tilesource.y * 32, 32, 32));

			//std::cout << "Drawing tilemap at " << i << ", " << j << std::endl;
			window.draw(tilemap[i][j]);

		}


	}

	window.display();

	while (window.isOpen())
	{

		

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Event::KeyPressed) {
				switch (event.key.code) {

				case sf::Keyboard::Up: 
					if (grid->getCellValue(playerX, playerY - 1) == 0 || grid->getCellValue(playerX, playerY - 1) == 2) {
						grid->move(playerX, playerY, playerX, playerY - 1);
						playerY--;
						std::cout << "Up" << std::endl;
						refresh = true;
					}
					break;

				case sf::Keyboard::Down:
					if (grid->getCellValue(playerX, playerY + 1) == 0 || grid->getCellValue(playerX, playerY + 1) == 2) {
						grid->move(playerX, playerY, playerX, playerY + 1);
						playerY++;
						std::cout << "Down" << std::endl;
						refresh = true;
					}
					break;

				case sf::Keyboard::Left:
					if (grid->getCellValue(playerX - 1, playerY) == 0 || grid->getCellValue(playerX - 1, playerY) == 2) {
						grid->move(playerX, playerY, playerX - 1, playerY);
						playerX--;
						std::cout << "Left" << std::endl;
						refresh = true;
					}
					break;

				case sf::Keyboard::Right:
					if (grid->getCellValue(playerX + 1, playerY) == 0 || grid->getCellValue(playerX + 1, playerY) == 2) {
						grid->move(playerX, playerY, playerX + 1, playerY);
						playerX++;
						std::cout << "Right" << std::endl;
						refresh = true;
					}
					break;

				}
					
			}


		}

		
		if (refresh) {

			std::cout << frames++ << std::endl;

			std::cout << "Refreshing..";

			for (int i = 0; i < width; i++) {

				for (int j = 0; j < height; j++) {

					if (!(i == 0 || j == 0 || i == width - 1 || j == height - 1)) {

						cellValue = grid->getCellValue(i - 1, j - 1);
						if (cellValue == Space)
							tilesource.y = Space;
						else if (cellValue == Wall)
							tilesource.y = Wall;
						else if (cellValue == Object)
							tilesource.y = Space;
						else if (cellValue == Entrance)
							tilesource.y = Entrance;
						else if (cellValue == Exit)
							tilesource.y = Exit;
						else if (cellValue == Player)
							tilesource.y = Player;

						//std::cout << "Texture will be " << tilesource.y << std::endl;

						tilemap[i][j].setTextureRect(sf::IntRect(0, tilesource.y * 32, 32, 32));
						
					}

					window.draw(tilemap[i][j]);
				}

				refresh = false;
			}

			window.display();


		}
		

		//window.draw(tilemap[0][0]);

		//playtile.setTextureRect(sf::IntRect(tilesource.x, tilesource.y * 32, 32, 32));
		//window.clear();
		//window.draw(playtile);
		

	}

    return 0;
}

