#pragma once
#include "DNDObject.h"

class Treasure : public DNDObject
{
private:
	
	int _type = 2;

public:

	Treasure();
	~Treasure();

	int type();
};

