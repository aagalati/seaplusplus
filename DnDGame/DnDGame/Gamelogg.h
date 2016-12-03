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
	//void GameLog1(bool log1); // game setup, map loading and campaign progress, player turns switching, end phase
	//void GameLog2(bool log2); // every movement made on the map
	//void GameLog3(bool log3); // every attack attempted including all factors involved in its calculation and its result
	//void GameLog4(bool log4); // every dice roll



	void operator <<(const std::string input);

	void toggleOnOff();


	Gamelogg(bool toggled);
private:
	std::ostream* oss;
	bool toggled;
};

	Gamelogg GL1; // game setup, map loading and campaign progress, player turns switching, end phase
	Gamelogg GL2; // every movement made on the map
	Gamelogg GL3; // every attack attempted including all factors involved in its calculation and its result
	Gamelogg GL4; // every dice roll
