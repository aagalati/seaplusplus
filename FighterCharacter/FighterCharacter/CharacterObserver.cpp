#include "stdafx.h"
#include "CharacterObserver.h"
namespace std
{
	CharacterObserver::CharacterObserver() : Subject(){}

	void CharacterObserver::changeToCharacter()
	{
		Notify();
	}

}
