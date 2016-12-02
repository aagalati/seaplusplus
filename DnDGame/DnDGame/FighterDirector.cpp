#include "stdafx.h"
#include "FighterDirector.h"


void FighterDirector::setCharacterBuilder(CharacterBuilder* chBuild)
{
	t_chBuilder = chBuild;
}

Character* FighterDirector::getCharacter()
{
	return t_chBuilder->getCharacter();
}

void FighterDirector::constructCharacter()
{
	t_chBuilder->buildCharacterType();
}

void FighterDirector::constructCharacter(int level)
{
	t_chBuilder->buildCharacterType(level);
}