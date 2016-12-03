#pragma once
#include "Character.h"
#include "Structure.h"
#include "Treasure.h"
#include "DNDObject.h"


class Builder
{
private:
	int _type;

public:
	Builder();
	Builder(int);
	~Builder();

	//Method which creates a pointer to a new object for the map
	DNDObject* build(int);

};

