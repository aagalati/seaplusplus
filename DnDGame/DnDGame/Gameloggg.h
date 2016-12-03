#pragma once


#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::string;


class Gameloggg
{
public:
	Gameloggg();
	~Gameloggg();
	//void GameLog1(bool log1); // game setup, map loading and campaign progress, player turns switching, end phase
	//void GameLog2(bool log2); // every movement made on the map
	//void GameLog3(bool log3); // every attack attempted including all factors involved in its calculation and its result
	//void GameLog4(bool log4); // every dice roll



	void operator <<(const std::string input);

	void toggleOnOff();


	Gameloggg(bool toggled);
private:
	std::ostream* oss;
	bool toggled;
};

Gameloggg GL1; // game setup, map loading and campaign progress, player turns switching, end phase
Gameloggg GL2; // every movement made on the map
Gameloggg GL3; // every attack attempted including all factors involved in its calculation and its result
Gameloggg GL4; // every dice roll

