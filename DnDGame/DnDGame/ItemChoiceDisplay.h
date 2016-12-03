#pragma once
#include "Display.h"
#include "GameButton.h"
#include "AllItemDisplay.h"

class ItemChoiceDisplay :
	public Display
{
public:

	ItemChoiceDisplay();
	void choiceDisplay();
	void drawButtons();
	~ItemChoiceDisplay();
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

