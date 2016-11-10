#pragma once
#include "DNDObject.h"
#include <string>
using namespace std;
class Structure : public DNDObject
{

private:

	int typeOfStructure;

public:

	int type();
	string toString();
	
	Structure();
	Structure(int);
	~Structure();
};

