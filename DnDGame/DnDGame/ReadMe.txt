//Pierre-Anthony Moffet 40008016
//Adam Galati 26944094
//Carlo Baccalaro 26296440
//Lucas Brancatella

Note To Dr. Taleb,

This version of the game is not as complete as we wish it could have been due to time limitations. As of now, the game:
-Is presented to the user as a basic GUI
-Creates a menu with 2 working button, which generates the map.
-Is randomly generated, and its validity is verified.
-Generates a random Character which follows all Dungeons and Dragons rules is generated.
	-With attributes which are rolled and follow the rules.
	-With default equipment which affect the statistics of the character.
	-There is however no backpack.
-The user can move the character around.
-The user can hover over all objects to see a description of them.
-The game terminates when the player reaches the exit.

The following were partially coded and almost implement:
-Serialization of all the objects of the map is coded, but the feature is not yet implemented for user access.
	The following can be demonstrated in a main by calling the save method of the particular object.
	-1 character can be saved and loaded (Tested);
	-Multiple items should be able to be saved and then loaded(Not Tested);
	-Item Containers should be able to be saved and then loaded(Not Testesd);
-Characters and Items scaling in comparison to the level of the introduced Character was planned with a level up method, but was not implemented during map generation
-The Item Enyclopedia was meant to be a way for a player to create item and store them, as well as load all created items.
-The Map Editor is very crude and needs additional work.
-The Character Creator was not implemented in the GUI, but the character can be easily created in a driver.
-The Inventory Panel was not implemented in the GUI, but the Equipment is displayed along with the Character info with the mouse hover.

DNDGAME.ccp is the Driver

Important information to run the GUI


