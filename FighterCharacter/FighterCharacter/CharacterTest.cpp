#include "stdafx.h"
#include "CharacterTest.h"
#include "Character.h"
//! test method to test the validateNewCharacter() method of the Character class 
//! Test Case: a valid newly created character should have all its ability scores in the [3-18] range
//! Tested item: Character::validateNewCharacter()
	void CharacterTest::testValidNewCharacter()
	{
		Character *conan = new Character(12, 12, 12, 12, 12, 12);
		CPPUNIT_ASSERT(conan->validateNewCharacter());
		delete conan;
	}

	//! test method to test the validateNewCharacter() method of the Character class 
	//! Test Case: an invalid newly created character should have any of its ability scores outside the [3-18] range
	//! Tested item: Character::validateNewCharacter()
	void CharacterTest::testInvalidNewCharacter()
	{
		Character *conan = new Character(20, 12, 12, 12, 12, 12);
		CPPUNIT_ASSERT(conan->validateNewCharacter() == false);
		delete conan;
	}

	//! test method to test the hit() method of the Map class 
	//! Test Case: a character that has been hit(x) should have its hit points reduced by x 
	//! Tested item: Character::hit()
	void CharacterTest::testHit()
	{
		Character *conan = new Character(12, 12, 12, 12, 12, 12);
		conan->hit(4);
		CPPUNIT_ASSERT(conan->getHitPoints() == 6);
		delete conan;
	}

	//THE 2 FOLLOWING FUNCTIONS ARE PERTINANT TO ASSIGNMENT 1, PLEASE SCROLL DOWN TO LINE 59 FOR ASSIGNMENT 2 TEST CASES
	//! test method to test the abilityPointsGenerator() method of the Character class
	//! Test Case: the generator should give the highest roll to the strength attribute
	//! Tested item: Character::abilityScoreGenerator
	void CharacterTest::testHighestStat()
	{
		Character *conan = new Character(1, "conan");
		CPPUNIT_ASSERT(conan->getStrength() > conan->getDexterity() &&
					   conan->getStrength() > conan->getConstitution() &&
					   conan->getStrength() > conan->getIntelligence() &&
					   conan->getStrength() > conan->getWisdom() &&
					   conan->getStrength() > conan->getCharisma());
		delete conan;
	}
	//! test method to test the  hitPointGenerator() method of the Character class
	//! Test Case: the character at level 2 should have no less than 19 hp and no more than 28
	//! Test intem: Character::hitPointsGenerator()
	void CharacterTest::testHitPointGenerator()
	{
		Character *conan = new Character(2, "conan");
		CPPUNIT_ASSERT((conan->getHitPoints() >= 19) && (conan->getHitPoints() <= 28));
		delete conan;
	}

	//!test method to test the invocation of the update method through the Observer pattern
	//!Test case: Boolean value updating should only be true if update is invoked through the observer pattern
	//!Test intem: Character::Update()
	void CharacterTest::testUpdate()
	{
		Character* conan = new Character(2, "conan");
		conan->setStrength(16);
		CPPUNIT_ASSERT(conan->updating == true);
		delete conan;
	}