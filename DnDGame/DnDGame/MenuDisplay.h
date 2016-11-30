#pragma once
#include "Display.h"
#include "GameButton.h"
#include <vector>
#include <string>

class MenuDisplay :
	public Display
{
public:
	MenuDisplay();
	~MenuDisplay();
	void menuDisplay();
	void drawHeader();
	void drawButtons();
	void update();
	void run();
	void buttonAction(int x, int y, bool isclick);
	int getExitType();

private:

	sf::Text buttonname;
	std::vector< GameButton* > buttons;
	int numofbuttons;
	int exitType;

};

