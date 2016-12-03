#pragma once
#include "Display.h"
#include "GameButton.h"

class EditCharDisplay :
	public Display
{
public:
	EditCharDisplay();
	~EditCharDisplay();

private:

	std::vector < GameButton* > statButtons;

};

