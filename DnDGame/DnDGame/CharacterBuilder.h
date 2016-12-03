#pragma once
#include "Character.h"

class CharacterBuilder
{
public:

	Character* getCharacter();
	void createNewCharacter();
	void createNewCharacter(int);
	virtual void buildCharacterType() = 0;
	virtual void buildCharacterType(int) = 0;

	CharacterBuilder();
	~CharacterBuilder();
		
protected:
	Character* t_character;
};

