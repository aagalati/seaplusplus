#include "stdafx.h"
#include "CharacterBuilder.h"


CharacterBuilder::CharacterBuilder()
{
}


CharacterBuilder::~CharacterBuilder()
{
}

Character* CharacterBuilder::getCharacter()
{
	return t_character;
}

void CharacterBuilder::createNewCharacter()
{
	t_character = new Character();
}