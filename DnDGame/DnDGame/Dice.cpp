#include "stdafx.h"
#include "Dice.h"


Dice::Dice(int x, int s)
{
	rolls = x;
	sides = s;
	value = 0;
}

Dice::Dice(const Dice& d)
{
	
	rolls = d.rolls;
	sides = d.sides;
	value = d.value;
	
}

// roll dice method
int Dice::roll()
{	//double check to see if all the values are good to go
	value = 0;
	int ran, ran2;
	
	//calculate the rolls and total value
	for (int i = 0; i < rolls + 1; i++)
	{
		srand(time(0));
		ran = (rand() % sides) + 1;
		value = value + ran;
	}
	
	return value;
}

string Dice::toString()
{
	string dice = std::to_string(rolls) += " D";
	dice += std::to_string(sides);
	return dice;
}

const Dice& Dice::operator=(const Dice& d)
{
	rolls = d.rolls;
	sides = d.sides;
	value = d.value;
	return *this;
}