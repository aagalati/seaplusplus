#include "stdafx.h"
#include "TankFighterBuilder.h"

void TankFighterBuilder::buildCharacterType()
{
	createNewCharacter();
	t_character->abilityScoreGenerator(t_character->getLevel());
	//This is the important part, where attributes are set in a "tank" way
	t_character->setTankAttributes();
	t_character->setModifiers();
	t_character->setHitPoints(t_character->hitPointsGenerator(t_character->getLevel()));
	t_character->setCurrentHitPoints(t_character->getHitPoints());

}

void TankFighterBuilder::buildCharacterType(int level)
{
	createNewCharacter(level);
	t_character->abilityScoreGenerator(t_character->getLevel());
	//This is the important part, where attributes are set in a "tank" way
	t_character->setName("Tank Fighter");
	t_character->setTankAttributes();
	t_character->setModifiers();
	t_character->setHitPoints(t_character->hitPointsGenerator(t_character->getLevel()));
	t_character->setCurrentHitPoints(t_character->getHitPoints());

}


