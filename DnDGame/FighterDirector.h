#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class FighterDirector : public CharacterBuilder
{
public:
	void setCharacterBuilder(CharacterBuilder *);
	Character* getCharacter();
	void constructCharacter();
private:
	CharacterBuilder* t_chBuilder;
	
	FighterDirector();
	~FighterDirector();
};

