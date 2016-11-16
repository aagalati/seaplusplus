#include "Character.h"

class CharacterBuilder
{
public:

	Character* getCharacter();
	void createNewCharacter();
	virtual void buildCharacterType() = 0;

	CharacterBuilder();
	~CharacterBuilder();
		
protected:
	Character* t_character;
};

