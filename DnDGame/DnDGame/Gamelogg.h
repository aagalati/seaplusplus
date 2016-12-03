#pragma once

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::string;


class Gamelogg
{
public:
	Gamelogg();
	~Gamelogg();

	void operator <<(const std::string input);

	void toggleOnOff();


	Gamelogg(bool toggled);
private:
	std::ostream* oss;
	bool toggled;
};

static Gamelogg GL1; // game setup, map loading and campaign progress, player turns switching, end phase
static Gamelogg GL2; // every movement made on the map
static Gamelogg GL3; // every attack attempted including all factors involved in its calculation and its result
static Gamelogg GL4; // every dice roll
