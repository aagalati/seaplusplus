#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class BullyFighterBuilder : public CharacterBuilder
{

public:
	
	virtual void buildCharacterType();

	BullyFighterBuilder();
	~BullyFighterBuilder();
};

