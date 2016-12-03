// DnDGame.cpp : Defines the entry point for the console application.

/*----------------------------------------------------------------------


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


*/

//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Grid.h"
#include "Display.h"
#include "MenuDisplay.h"
#include "BuilderDisplay.h"
#include "Character.h"
#include "ItemChoiceDisplay.h"
#include "CharChoiceDisplay.h"



void main()
{

	int exitType = -1;

	while (exitType != 4) {

		if (exitType = -1) {

			MenuDisplay *menu = new MenuDisplay();  //make a menu display

			while (menu->windowOpen()) {  //open the menu

				menu->run();

			}

			exitType = menu->getExitType();

		}

		if (exitType == 0) { //open play 

			Grid *grid = new Grid(10, 10, false);  //random grid

			Display *game = new Display(grid, 1);

			while (game->windowOpen()) {

				game->run();

			}

		}

		if (exitType == 1) {

			ItemChoiceDisplay *item = new ItemChoiceDisplay();

			while (item->windowOpen()) {

				item->run();

			}

		}

		if (exitType == 2) {

			BuilderDisplay *build = new  BuilderDisplay();

			while (build->windowOpen()) {

				build->run();

			}

		}

		if (exitType == 3) {

			CharChoiceDisplay *ch = new CharChoiceDisplay();

			while (ch->windowOpen()) {

				ch->run();

			}

		}

	}

		Shield bobby("memes", Item::ArmorClass, 4);
		Helmet bobby1("wholesome", Item::ArmorClass, 5);
		Ring bobby2("dank", Item::Wisdom, 4);
		Belt bobby3("Snakey", Item::Charisma, 3);
		Weapon bobby4("Epic Trooll", Item::AttackBonus, 3, 1, 2, 8);
		Armor bobby5("No hurt me plz", Item::ArmorClass, 1);
		Boots bobby7("Sanic", Item::Dexterity, 5);
		Weapon bobby8("Ez unly gem", Item::Intelligence, 0, 1, 4, 20);
		Armor bobby9("kk", Item::Constitution, 3);
		Shield bobby10("no dmg if u hit this", Item::Charisma, 0);

		bobby1.save(0);
		bobby.save(0);
		bobby2.save(0);
		bobby3.save(0);
		bobby4.save(0);
		bobby5.save(0);
		bobby7.save(0);
		bobby8.save(0);
		bobby9.save(0);
		bobby10.save(0);



	}


