/**
* @file DiceRoll.cpp
* @brief: 
	Program to calcuate dungeons and dragons dice rolling simulation
	this program has a driver (the main function) and an additional function
	called rollDice that simulates the dungeon and dragons format to roll the dice.
	The program has a specific regex to take an input from 1-999 for times rolled.
	the specific dice are 4 , 6 , 12 , 20 , 100 and the extra number that can be
	added has to be in between 1 and 999. If an invalid number or format is given 
	the program will exit.
*
* @author Lucas Brancatella
*
* @date 21/10/2016
*/


#include <regex>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
/**
* forward declaration for the roll dice method
*/
int rollDice(int& rolls, int& sides, int& extra);
int main()
{	//regular expression for user input
	std::regex e{ R"-((\d{1,3})[Dd](4|6|12|20|100)\[(\d{1,3})\])-" };
	
	std::cout << "Welcome to Dungeons and Dragons Dice Rolling Simulation" << std::endl;
	std::cout << "Use the format xdy[z], x for times rolled, y for dice type and z for additional" << std::endl;
	std::cout << "Enter dice roll: " << std::flush;

	std::string line;
	std::getline(std::cin, line);
	//checks if regex is a match
	std::smatch m;
	if (!std::regex_match(line, m, e))
	{
		std::cout << "Error: bad format, please use: xdy[z]" << '\n';
		return(0);
	}
	int rolls = std::stoi(m[1]);
	int sides = std::stoi(m[2]);
	int extra = std::stoi(m[3]);
	//roll dice method
	roll(rolls, sides, extra);
											
	return 0;
}
//roll dice method
int roll(int& rolls, int& sides, int& extra)
{	//double check to see if all the values are good to go
	if ((rolls < 1 | rolls > 999) | (sides != (4 | 6 | 12 | 20 | 100)) | (rolls < 1 | rolls > 999)) 
	{
		std::cout << "Error: Invalid inputs exiting" << '\n';
		return(0);
	}

	std::cout << "Rolls: " << rolls << '\n';
	std::cout << "Sides: " << sides << '\n';
	std::cout << "Extra: " << extra << '\n';
	//switch case for the sides of dice
	switch (sides)
	{
		case '4':
			sides = 4;
		case '6':
			sides = 6;
		case '12':
			sides = 12;
		case '20':
			sides = 20;
		case '100':
			sides = 100;
	}

	int ran, ran2;
	std::string x;
	int total = 0;
	//calculate the rolls and total value
	for (int i = 0; i < rolls + 1; i++)
	{
		srand(time(0));
		ran = (rand() % sides) + 1;
		total = total + ran;
	}
	ran2 = (rand() % extra) + 1;
	std::cout << "Your total roll is: " << total << '\n';
	std::cout << "The extra roll is: " << extra << '\n';
	do
	{
		std::cout << "Do you want to add this number [y/n] ? " << std::endl;
		std::cin >> x;
	} while (!std::cin.fail() && x != "y" && x != "n");

	if (x == "y")
	{
		total = total + extra;
		std::cout << "New Total: " << total << std::endl;
	}
	else if (x == "n")
	{
		std::cout << "Your total: " << total << std::endl;
	}
	return total;
}