#pragma once
#include "DNDObject.h"
class Structure : public DNDObject
{

private:

	int typeOfStructure;

public:

	int type();
	
	Structure();
	Structure(int);
	~Structure();
};

