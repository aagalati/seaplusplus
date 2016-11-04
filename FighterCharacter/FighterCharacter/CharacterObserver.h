#pragma once
#include "Observer.h"
#include "Subject.h"
#include "Character.h"
#include <list>

namespace std{


	class CharacterObserver : public Subject

	{
	public:
		CharacterObserver();
		void changeToCharacter();
	};
}

