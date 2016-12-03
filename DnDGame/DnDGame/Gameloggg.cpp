
#include "stdafx.h"
#include "Gameloggg.h"
#include <iostream>


Gameloggg::Gameloggg() {
	oss = new std::ostream(std::cout.rdbuf());
	toggled = true;

}

Gameloggg::Gameloggg(bool toggled) {
	this->toggled = toggled;
	oss = new std::ostream(std::cout.rdbuf());
}


void Gameloggg::operator <<(const std::string input)
{
	if (toggled)
		*oss << input;
	return;
}

void Gameloggg::toggleOnOff() {
	if (toggled == true)
		toggled = false;
	else toggled = true;
}

Gameloggg::~Gameloggg()
{

}
