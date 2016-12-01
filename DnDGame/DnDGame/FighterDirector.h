#pragma once
#include "Character.h"
#include "CharacterBuilder.h"

class FighterDirector : public CharacterBuilder
{
public:
	void setCharacterBuilder(CharacterBuilder *);
	Character* getCharacter();
	void constructCharacter();
	void constructCharacter(int);
	
private:
	CharacterBuilder* t_chBuilder;
	
	
};

