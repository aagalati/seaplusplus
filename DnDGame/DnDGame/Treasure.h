#pragma once
#include "DNDObject.h"
#include <string>

using namespace std;
class Treasure : public DNDObject
{
private:
	
	int _type = 2;

public:

	Treasure();
	~Treasure();

	int type();
	string toString();
};

