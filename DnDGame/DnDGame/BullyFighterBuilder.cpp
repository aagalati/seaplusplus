#include "stdafx.h"
#include "BullyFighterBuilder.h"

void BullyFighterBuilder::buildCharacterType()
{

	createNewCharacter();
	t_character->abilityScoreGenerator(t_character->getLevel());
	//This is the important part, where attributes are set the "bully" way.
	t_character->setBullyAttributes();
	t_character->setModifiers();
	t_character->setHitPoints(t_character->hitPointsGenerator(t_character->getLevel()));
	t_character->setCurrentHitPoints(t_character->getHitPoints());

}


void BullyFighterBuilder::buildCharacterType(int level)
{

	createNewCharacter(level);
	t_character->abilityScoreGenerator(t_character->getLevel());
	//This is the important part, where attributes are set the "bully" way.
	t_character->setName("Bully Fighter");
	t_character->setBullyAttributes();
	t_character->setModifiers();
	t_character->setHitPoints(t_character->hitPointsGenerator(t_character->getLevel()));
	t_character->setCurrentHitPoints(t_character->getHitPoints());

}