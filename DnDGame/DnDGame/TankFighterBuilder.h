#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class TankFighterBuilder : public CharacterBuilder
{

public:

	virtual void buildCharacterType();
	virtual void buildCharacterType(int);

	
};

