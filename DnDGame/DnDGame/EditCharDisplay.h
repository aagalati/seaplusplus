#pragma once
#include "Display.h"
#include "GameButton.h"
#include "Character.h"
#include "FighterDirector.h"
#include "BullyFighterBuilder.h"
#include "NimbleFighterBuilder.h"
#include "TankFighterBuilder.h"
#include "CharacterBuilder.h"



class EditCharDisplay :
	public Display
{
public:
	EditCharDisplay();
	void setFonts();
	void placeText();
	void drawText();
	void typeDisplay();
	void drawButtons();
	void run();
	void buttonAction(int x, int y, bool isclick);
	void getStats();
	void update();
	~EditCharDisplay();

private:

	int numoftypebuttons;
	std::vector < GameButton* > typeButtons;
	sf::Text inputname;
	sf::Text inputlevel;
	sf::Text titlename;
	sf::Text titlelevel;
	sf::Text stats;

	BullyFighterBuilder* bs = new BullyFighterBuilder();
	NimbleFighterBuilder* ba = new NimbleFighterBuilder();
	TankFighterBuilder* bb = new TankFighterBuilder();
	Character* ch;
	

	string name, level;

};

