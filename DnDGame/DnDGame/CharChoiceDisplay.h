#pragma once
#include "Display.h"
#include "GameButton.h"

class CharChoiceDisplay :
	public Display
{
public:

	CharChoiceDisplay();
	void choiceDisplay();
	void drawButtons();
	~CharChoiceDisplay();
	void run();
	void update();
	void openAll();
	void openEdit();
	void buttonAction(int x, int y, bool isclick);

	int getExitType();

private:

	int numofbuttons;

	std::vector < GameButton* > buttons;

};



