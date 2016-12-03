#include "stdafx.h"
#include "Gamelogg.h"


#include <iostream>


Gamelogg::Gamelogg() {
	oss = new std::ostream(std::cout.rdbuf());
	toggled = true;

}

Gamelogg::Gamelogg(bool toggled) {
	this->toggled = toggled;
	oss = new std::ostream(std::cout.rdbuf());
}


void Gamelogg::operator <<(const std::string input)
{
	if (toggled)
		*oss << input;
	return;
}

void Gamelogg::toggleOnOff() {
	if (toggled == true)
		toggled = false;
	else toggled = true;
}

Gamelogg::~Gamelogg()
{

}
