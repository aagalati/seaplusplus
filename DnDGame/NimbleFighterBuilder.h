#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class NimbleFighterBuilder : public CharacterBuilder
{

public:

	virtual void buildCharacterType();

	NimbleFighterBuilder();
	~NimbleFighterBuilder();
};
