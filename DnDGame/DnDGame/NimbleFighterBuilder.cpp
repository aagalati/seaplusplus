#include "stdafx.h"
#include "NimbleFighterBuilder.h"

void NimbleFighterBuilder::buildCharacterType()

{
		createNewCharacter();
		t_character->abilityScoreGenerator(t_character->getLevel());
		//This is the important part, where attributes are set in a "nimble" way
		t_character->setNimbleAttributes();
		t_character->setModifiers();
		t_character->setHitPoints(t_character->hitPointsGenerator(t_character->getLevel()));
		t_character->setCurrentHitPoints(t_character->getHitPoints());

}
void NimbleFighterBuilder::buildCharacterType(int level)

{
	createNewCharacter(level);
	t_character->abilityScoreGenerator(t_character->getLevel());
	//This is the important part, where attributes are set in a "nimble" way
	t_character->setName("Nimble Fighter");
	t_character->setNimbleAttributes();
	t_character->setModifiers();
	t_character->setHitPoints(t_character->hitPointsGenerator(t_character->getLevel()));
	t_character->setCurrentHitPoints(t_character->getHitPoints());

}


NimbleFighterBuilder::NimbleFighterBuilder()
{
}


NimbleFighterBuilder::~NimbleFighterBuilder()
{
}
