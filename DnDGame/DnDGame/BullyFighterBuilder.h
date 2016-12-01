#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class BullyFighterBuilder : public CharacterBuilder
{

public:
	
	virtual void buildCharacterType();
	virtual void buildCharacterType(int);
	
};

