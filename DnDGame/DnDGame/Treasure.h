#pragma once
#include "DNDObject.h"
#include "ItemContainer.h"
#include <string>

using namespace std;
class Treasure : public DNDObject, public ItemContainer
{
private:
	
	int _type = 2;

public:

	Treasure();
	~Treasure();

	int type();
	string toString();
};

