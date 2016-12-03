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
			afx:	   Necessary for Serialization.

*/

#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#define _AFXDLL

#include "CharacterObserver.h"
#include "Observer.h"
#include "DnDObject.h"
#include "Item.h"
#include "Armor.h"
#include "Helmet.h"
#include "Belt.h"
#include "Boots.h"
#include "Ring.h"
#include "Shield.h"
#include "Weapon.h"
#include "itemContainer.h"
#include "Grid.h"
#include "Treasure.h"
#include "Combat.h"
#include "Dice.h"

//Serialization library
#include <afx.h>

using std::rand;
using std::cout;
using std::string;
	
	//Class must be a subclass of CObject for MFC Serialization
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

		int nbOfAttacks;
		int nbOfAttacksLeft;
		int movement;
		int remMovement;

		//Integer type used for grid recognition of object type;
		int characterType;
		
		//!Equipment
		Armor armor;
		Shield shield;
		Weapon weapon;
		Boots boots;
		Belt belt;
		Ring ring;
		Helmet helmet;
		ItemContainer equipment;
		ItemContainer backpack;

		//Variables relevant to assignment 2
		CharacterObserver* _char;
		bool inConstructor;

		//Variable relevant to assignment 3
		static const int NB_OF_ABILITIES = 6;
		int abilityScores[NB_OF_ABILITIES];

		//!Other Information
		std::string name;

		Combat combatStats;
		

	public:
		
		DECLARE_SERIAL(Character)
		//!Statistics Mutators
		void setLevel(int) noexcept;
		void setStrength(int) noexcept;
		void setStrengthModifier(int) noexcept;
		void setConstitution(int) noexcept;
		void setConstitutionModifier(int) noexcept;
		void setDexterity(int) noexcept;
		void setDexterityModifier(int) noexcept;
		void setWisdom(int) noexcept;
		void setWisdomModifier(int) noexcept;
		void setCharisma(int) noexcept;
		void setCharismaModifier(int) noexcept;
		void setIntelligence(int) noexcept;
		void setIntelligenceModifier(int) noexcept;
		void setHitPoints(int) noexcept;
		void setCurrentHitPoints(int) noexcept;
		void setArmorClass(int) noexcept;
		void setMeleeAttackBonus(int) noexcept;
		void setMeleeAttackDamage(int) noexcept;
		void setRangedAttackBonus(int) noexcept;
		void setRangedAttackDamage(int) noexcept;

		void setMovement(int) noexcept;
		void setRemMovement(int) noexcept;
		void setNbOfAttacks(int) noexcept;
		void setNbOfAttacksLeft(int) noexcept;
		
		void setCharacterType(int) noexcept;

		void setName(std::string) noexcept;

		void setInConstructor(bool) noexcept;

		void setArmor(Armor) noexcept;
		void setShield(Shield) noexcept;
		void setWeapon(Weapon) noexcept;
		void setBoots(Boots) noexcept;
		void setBelt(Belt) noexcept;
		void setRing(Ring) noexcept;
		void setHelmet(Helmet) noexcept;
		void setEquipment(ItemContainer) noexcept;
		void setBackpack(ItemContainer) noexcept;

		void setAbilityScores(int, int) noexcept;
		void setAbilityScores(int, int, int, int, int, int) noexcept;
		
		void setCombat(Combat);

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

		inline int getMovement();
		inline int getRemMovement();
		inline int getNbOfAttacks();
		inline int getNbOfAttacksLeft();
		
		//State of Characters -> 5 is Player, 6 is Enemy NPC, 7 is Friendly NPC
		int type();

		inline std::string  getName();

		
		inline bool getInConstructor();

		inline Armor getArmor();
		inline Shield getShield();
		inline Weapon getWeapon();
		inline Boots getBoots();
		inline Belt getBelt();
		inline Ring getRing();
		inline Helmet getHelmet();

		inline ItemContainer getEquipment();
		inline ItemContainer getBackpack();
		
		int* getAbilityScores();

		Combat getCombat();

		//!Constructor
		Character() noexcept;
		Character(int) noexcept;
		Character(const int, const std::string) noexcept;
		Character(const int, const std::string, const int) noexcept;
		Character(const int,const int,const int,const int,const int,const int) noexcept;
		Character(int, int, int, int, int, int, int) noexcept;
		//Copy
		Character(Character &c) noexcept;
		~Character();

		//!Methods used for character generation
		int hitPointsGenerator(int) noexcept;
		void abilityScoreGenerator(int) noexcept;
		int extraPoints(int) noexcept;
		void extraAttacks(int) noexcept;
		
		//!Methods relevant to Assignment 3
		void setBullyAttributes();
		void setNimbleAttributes();
		void setTankAttributes();


		//!Functions for modifiers
		void setModifiers();
		void setEquipmentModifiers() noexcept;
		int modifierCalculation(int) noexcept;
		
		void defaultEquip() noexcept;
		void storeEquipment() noexcept;
		void equip(Item*) noexcept;

		//!Other Methods
		bool validateNewCharacter() noexcept;
		static bool validateStatistic(int) noexcept;
		void hit(int) noexcept;

		//Methods for map element adaptation
		void levelUp() noexcept;
		void levelUp(int) noexcept;
		void levelDown() noexcept;
		void levelDown(const int ) noexcept;

		Grid* adapt(Grid*, Character) noexcept;

		//!Printing Information 
		void printCharacter() noexcept;
		std::string toString() noexcept;
		std::string modOP(int) noexcept;
		
		//!New Methods Relevant to Assignment 2
		void checkState();
		void update();
		bool updating = false;

		//!Method relevant to serialization
		virtual void Serialize(CArchive& ar);
		void save();
		static std::vector<Character*> load();
	};

#endif //CHARACTER_H