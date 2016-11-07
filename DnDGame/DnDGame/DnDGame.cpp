// DnDGame.cpp : Defines the entry point for the console application.

/*----------------------------------------------------------------------
--------------------------Part 2: MapObserver---------------------------
Adam Galati 26944094

This program uses the DnDGame.cpp as the driver. The code has the observer pattern
implemented (Subject and Observer as a superclass are used), this observer pattern
will notify all the observable objects when a Subject::Notify has been called.
This program uses the SFML library (available at www.sfml-dev.org) to create a 
graphical user interface (GUI) for the map of the game.

Libraries used:

	-SFML Library: This library was used because is it a flexible way to implement
				  a GUI. It allows for images to imported as textures which is
				  useful when creating a game. The SFML libraries allows for good
				  visual and audio which makes it a great platform for this game.
	
	-Vector:	Vectors are a good way of keeping a list of data, this program uses
				mostly 2D vectors. Vectors will throw exceptions for out of bounds
				which is helpful for debugging as arrays would not behave the same.

	-iostream:	Used mostly for debugging purposes, but it is a fallback to the GUI
				as all the information on the GUI is represented in ASCII in the 
				console.

	-String:	Used for manipulating strings


Important info:

	To install SFML:	1- Visit http://www.sfml-dev.org/download.php and download Visual C++ 14 (2015) - 64-bit

						2- After downloading, extract the files onto the C drive

						3- The file is typically named SFML-2.4.1 however in this application rename it to SFML 2.4.1 (ex. C:\SFML 2.4.1)

						4-The code should now work, if the error persists it could be an issue with include or library path
						  If the code cannot be run after troubleshooting, contact galati_ator@msn.com (my email) if you would
						  like to get it to work. 
						 (This tutorial is extremely helpful http://www.cplusplus.com/forum/beginner/95295/#msg511543 see 9) Configure Visual Studio)


Relevant changes since Assignment 1:
	-GUI:
		-DnDgame.cpp
	-Observer Pattern:
		-Subject class (Subject.h & Subject.cpp)
		-Observer class (Oberser.h)
		-Grid::Update()
		-GridObserver

Game Rules:
	-Player can move
	-Map had entrance and exit

Future goals:
	-Implement A* pathing for any character/enemy and for better optimized Grid::checkValid()

*/

//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Grid.h"



int main()
{

	sf::RenderWindow window(sf::VideoMode(1000, 600), "Dungeons and Dragons");   //creating window for the game to be played

	window.setKeyRepeatEnabled(false); 

	enum tiletype {Space, Wall, Object, Entrance, Exit, Player};  //enum type for tile types inside the grid
	enum bordertype { tlcorner, top, trcorner, right, brcorner, bottom, blcorner, left }; //enumtype for the border type, not being used right now

	sf::Vector2i tilesource(32, Wall);    //using vector2 ints to keep tilesize and texture sources
	sf::Vector2i tilesize(32, 32);

	std::vector< std::vector<sf::Sprite> > tilemap;  //2d vector of sprites to be used to draw the grid

	int width, height;
	int playerX, playerY;
	int cellValue;
	bool refresh = false;

	const int BORDER_SIZE = 1;
	const int BORDER = BORDER_SIZE * 2;

	const int PADDING = 32;

	width = 6;
	height = 6;

	Grid *grid = new Grid(width, height, false);

	width += BORDER;
	height += BORDER;

	std::cout << "Creating map... Please wait for the map to be validated" << std::endl;

	while (!grid->checkValid()) {    //if the map is not valid, remake it
		grid->fillMapRandom();
	}

	playerX = grid->getEntranceX();   //setting player coordinates
	playerY = grid->getEntranceY();

	sf::Texture tileTexture;  //using 2 textures, one for the map area and one for the border
	sf::Texture borderTexture;

	if (!tileTexture.loadFromFile("texture/tiletexture.png"))   //load and verify textures
		std::cout << "Error: Tile texture not loaded" << std::endl;
	else
		std::cout << "Tile texture loaded.." << std::endl;

	if (!borderTexture.loadFromFile("texture/wall.png"))  //load and verify textures
		std::cout << "Error: Border texture not loaded" << std::endl;
	else
		std::cout << "Border texture loaded.." << std::endl;
	

	tilemap.resize(width);
	
	for (int i = 0; i < width; i++) {     //for loop to instantiate all the sprites and apply textures to them

		tilemap[i].resize(height);
		//std::cout << i << std::endl;

		for (int j = 0; j < height; j++) {

			if (i == 0 || j == 0 || i == width - 1 || j == height - 1) {

				tilemap[i][j].setTexture(borderTexture);  //setting border texture
				tilemap[i][j].setTextureRect(sf::IntRect(32, 32, 32, 32));
				//std::cout << "Creating border at " << i << ", " << j << std::endl;



				/*

				THIS CODE IS FOR FRAMED BORDER, NOT IN USE RIGHT NOW

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
				//std::cout << "Creating tile at " << i << ", " << j << std::endl;
				cellValue = grid->getCellValue(i - 1, j - 1);   //using enum types, refer to grid to apply corresponding textures
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

			tilemap[i][j].setPosition(tilesize.x * i + PADDING, tilesize.y * j + PADDING);  //setting position

		}


	}

	std::cout << "Map Displaying.." << std::endl << "Map will also be represented in ASCII in the command prompt" << std::endl;

	refresh = true;

	while (window.isOpen())
	{
		 
		sf::Event event;  //event used for getting player input

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Event::KeyPressed) {  //player input for getting keys pressed
				switch (event.key.code) {  //this code currently generates double events, not sure why, must fix (events trigger twice, ex. Left Left Right Right)

					//Checking if moving will be valid, if so, it will trigger the move function which will trigger Subject::Notify

				case sf::Keyboard::Up: 
					if (grid->getCellValue(playerX, playerY - 1) == 0 || grid->getCellValue(playerX, playerY - 1) == 2) {  //checking if next cell is open space or object, if so, player can move
						grid->move(playerX, playerY, playerX, playerY - 1);
						playerY--;
						std::cout << "Up" << std::endl;
						refresh = true;
					}
					break;

				case sf::Keyboard::Down:
					if (grid->getCellValue(playerX, playerY + 1) == 0 || grid->getCellValue(playerX, playerY + 1) == 2) { //checking if next cell is open space or object, if so, player can move
						grid->move(playerX, playerY, playerX, playerY + 1);
						playerY++;
						std::cout << "Down" << std::endl;
						refresh = true;
					}
					break;

				case sf::Keyboard::Left:
					if (grid->getCellValue(playerX - 1, playerY) == 0 || grid->getCellValue(playerX - 1, playerY) == 2) { //checking if next cell is open space or object, if so, player can move
						grid->move(playerX, playerY, playerX - 1, playerY);
						playerX--;
						std::cout << "Left" << std::endl;
						refresh = true;
					}
					break;

				case sf::Keyboard::Right:
					if (grid->getCellValue(playerX + 1, playerY) == 0 || grid->getCellValue(playerX + 1, playerY) == 2) { //checking if next cell is open space or object, if so, player can move
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

			//std::cout << "Refreshing..";

			for (int i = 0; i < width; i++) {

				for (int j = 0; j < height; j++) {

					if (!(i == 0 || j == 0 || i == width - 1 || j == height - 1)) {

						cellValue = grid->getCellValue(i - 1, j - 1);  //refreshing map, rechecking all values
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

	}

    return 0;
}

