#pragma once

#include <regex>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "DNDObject.h"

class Dice
{
public:
	Dice(){}
	Dice(int, int);
	Dice(const Dice&);
	int roll();
	string toString();

	inline int getSides() { return sides; }
	inline int getRolls() { return rolls; }
	inline int getValue() { return value; }

	void setSides(int s) { sides = s; }
	void setRolls(int r) { rolls = r; }
	void setValue(int v) { value = v; }

	 const Dice& operator=(const Dice&);

private:
	int sides;
	int rolls;
	int value;
};

#include "Dice.h"


