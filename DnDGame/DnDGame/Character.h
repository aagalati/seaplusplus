/*!\brief 1) Game Rules Implemented
			A character is made up of 6 core ability statistics, a level statistics, hitpoints and
			additional combat information and can also equip items.

			For ability points, the generation is done as follows, as per the rules :
			-The 3 best out of 4 rolls of a 6 sided die generates a value.
			- This process is repeated 6 times, such that 6 values are generated.
			- A player who creates a character would usually apply those stats as he desires.To
			  avoid further user interaction, I have decided to hand the best statistics to the
			  attributes which are most desirable to the Fighter Class, and the worst statistic
			  to the attributs which are not as desirable.
			- At certain levels, players are given additional ability points, which they can
			  assign as they wish.In this implementation, extra points are given in accordance
			  to the level given in the constructor.
			- All of this is impletemented in the abilityScoreGenerator.

			For abilitiy modifiers, the values of the modifiers are related to the value of the
			respective ability point.As such, every ability point goes through a switch case,
			such that the ability modifiers respect the DnD guidelines.

			For hitpoints, this value depends on the level of the character.At level 1, hitPoints are
			equal to 10 plus the Constitution modifier.For every additional level, the play rolls a d10
			and add his constitution modifier to the roll.In this implementation, the hitpoints assigned
			depend on the level chosen during character creation.

			For the combat related statistics :
			- The Armor Class is 10 + the Dexterity modifier.
			- The Melee Attack Bonus and Damage are equal to the Strength modifier
			- The Ranged Attack Bonus and Damare are equal to the Dexterity modifier.

			For the equipment, it is simply represented by string values.I was however still
			conscious of the starting gear of a fighter, such that he starts with basic equipment.
			2) Design
			In the driver, the a character can be created by calling the Character constructor. Arguments
			can be used such that the level of the character can be chosen, as well as its name. The
			Abilities Points can be selected or they can be randomly generated in a way that would
			favor a Character of class Fighter.
			When the constructor is called, the level is either set to 1 or one chosen which respects
			the dungeons and dragons guideling. Then the statistics are either generated or immediately
			set depending on the constructor called. The generation is done through many iterations of
			the rand() function. When all the statistics have been initliazed to the character, they are
			printed to the console. The program is then finished.

			3) Libraries used

			cstdlib:   This library is specifically used for the rand() function, which is used for the 
				       generation of the ability points. Specifically, the scope of the namespace std is
					   thus reduced to the function rand();
			iostream:  This library is used for the cout function, for printing the character information
					   to the screen. I limited the scope of the namespace to cout while excluding cin,
					   since I did not design my program with user interaction through the console. I 
					   assume that for the scope of this assignment, modifying the code in the Driver is 
					   sufficient.
			string:	   This library allows to usage and manipulation of strings, which are used for
					   implementing the equipment and the name of the character. I tried to limit the 
					   scope to increase efficiency but was having difficulties printing string information
					   to the console without using the entire library.


*/


#ifndef CHARACTER_H
#define CHARACTER_H
#define _AFXDLL
#include <cstdlib>
using std::rand;

#include <iostream>
using std::cout;
#include <string>
#include "CharacterObserver.h"
#include "Observer.h"
#include "DnDObject.h"

//Serialization library
#include <afx.h>


namespace std

{
	
	class Character : public Observer , public CObject, public DNDObject
	{
	private:
		//!Statistics 
		int level;
		int strength;
		int strengthModifier;
		int constitution;
		int constitutionModifier;
		int dexterity;
		int dexterityModifier;
		int wisdom;
		int wisdomModifier;
		int charisma;
		int charismaModifier;
		int intelligence;
		int intelligenceModifier;
		int hitPoints;
		int currentHitPoints;
		int armorClass;
		int meleeAttackBonus;
		int meleeAttackDamage;
		int rangedAttackBonus;
		int rangedAttackDamage;

		int characterType;
		
		//!Equipment
		string armor;
		string shield;
		string weapon;
		string boots;
		string ring;
		string helmet;

		//Variables relevant to assignment 2
		CharacterObserver* _char;
		bool inConstructor;

		//!Other Information
		string name;


		//!Methods used for character generation
		int hitPointsGenerator(int);
		void abilityScoreGenerator(int);
		int extraPoints(int);
		


	public:
		
		DECLARE_SERIAL(Character)
		//!Statistics Mutators
		void setLevel(int);
		void setStrength(int);
		void setStrengthModifier(int);
		void setConstitution(int);
		void setConstitutionModifier(int);
		void setDexterity(int);
		void setDexterityModifier(int);
		void setWisdom(int);
		void setWisdomModifier(int);
		void setCharisma(int);
		void setCharismaModifier(int);
		void setIntelligence(int);
		void setIntelligenceModifier(int);
		void setHitPoints(int);
		void setCurrentHitPoints(int);
		void setArmorClass(int);
		void setMeleeAttackBonus(int);
		void setMeleeAttackDamage(int);
		void setRangedAttackBonus(int);
		void setRangedAttackDamage(int);
		
		void setCharacterType(int);

		void setName(string);

		void setInConstructor(bool);

		void setArmor(string);
		void setShield(string);
		void setWeapon(string);
		void setBoots(string);
		void setRing(string);
		void setHelmet(string);

		//!Statistics Accessors
		inline int getLevel();
		inline int getStrength();
		inline int getConstitution();
		inline int getDexterity();
		inline int getWisdom();
		inline int getCharisma();
		inline int getIntelligence();

		inline int getStrengthModifier();
		inline int getConstitutionModifier();
		inline int getDexterityModifier();
		inline int getWisdomModifier();
		inline int getCharismaModifier();
		inline int getIntelligenceModifier();

		inline int getHitPoints();
		inline int getCurrentHitPoints();
		inline int getArmorClass();
		inline int getMeleeAttackBonus();
		inline int getMeleeAttackDamage();
		inline int getRangedAttackBonus();
		inline int getRangedAttackDamage();

		//State of Characters -> 5 is Player, 6 is Enemy NPC, 7 is Friendly NPC
		int type();

		inline string getName();

		
		inline bool getInConstructor();

		inline string getArmor();
		inline string getShield();
		inline string getWeapon();
		inline string getBoots();
		inline string getRing();
		inline string getHelmet();


		//!Constructor
		Character();
		Character(int);
		Character(int, string);
		Character(int, string, int);
		Character(int, int, int, int, int, int);
		Character(int, int, int, int, int, int, int);
		Character(Character &c);
		~Character();

		
		//!Functions for modifiers
		void setModifiers();
		int modifierCalculation(int);
		
		
		void setEquipment();

		//!Other Methods
		bool validateNewCharacter();
		static bool validateStatistic(int);
		void hit(int);
		void levelUp();
		void levelUp(int);

		//!Printing Information 
		void printCharacter();
		string modOP(int);
		
		//!New Methods Relevant to Assignment 2
		void checkState();
		void update();
		bool updating = false;

		//!Method relevant to serialization
		virtual void Serialize(CArchive& ar);
		void save();
		static Character* load();
	};
};
#endif //CHARACTER_H