#include "stdafx.h"
#include "CharacterObserver.h"

CharacterObserver::CharacterObserver() : Subject(){}

void CharacterObserver::changeToCharacter()
{		
	Notify();
}


