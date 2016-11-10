#pragma once
#include "Character.h"
#include "Structure.h"
#include "Treasure.h"
#include "DNDObject.h"

using namespace std;

class Builder
{
private:
	int _type;

public:
	Builder();
	Builder(int);
	~Builder();

	DNDObject* build(int);

};

