#pragma once
#include "DNDObject.h"
#include "ItemContainer.h"
#include <string>

using namespace std;

//Item container in map;
class Treasure : public ItemContainer
{
private:
	
	int _type = 2;

public:

	Treasure();
	~Treasure();

	int type();
	string toString();
};

