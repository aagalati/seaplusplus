#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class TankFighterBuilder : public CharacterBuilder
{

public:

	void buildCharacterType();

	TankFighterBuilder();
	~TankFighterBuilder();
};

