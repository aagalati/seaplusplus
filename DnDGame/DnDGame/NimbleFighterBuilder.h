#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class NimbleFighterBuilder : public CharacterBuilder
{

public:

	virtual void buildCharacterType();
	virtual void buildCharacterType(int);
	NimbleFighterBuilder();
	~NimbleFighterBuilder();
};
