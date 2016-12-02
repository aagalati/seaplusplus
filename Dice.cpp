
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

#include "Dice.h"

Dice::Dice(int s)
{
	sides = s;
}


//roll dice method
int roll(int rolls);
{	//double check to see if all the values are good to go
	if ((rolls < 1 | rolls > 999) | (sides != (4 | 6 | 8 | 12 | 20 | 100)) | (rolls < 1 | rolls > 999))
		return(0);

	
	switch (sides)
	{
		case '4':
			sides = 4;
		case '6':
			sides = 6;
		case '8':
			sides = 8;
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