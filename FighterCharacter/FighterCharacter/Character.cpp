// FighterCharacter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"



namespace std {

	IMPLEMENT_SERIAL(Character, CObject, 1)
	
	////////Statistics Mutators////////
	//!Ability Scores and Level
	

	//The mutators have been modified from assignment 1 with the addition of a checkState() method, which is what triggers the Observer pattern
	void Character::setLevel(int l)
	{
			level = l;
			checkState();
	}

	void Character::setStrength(int s)
	{
		if (validateStatistic(s))
		{
			strength = s;
			checkState();
		}
	}

	void Character::setConstitution(int c)
	{
		if (validateStatistic(c))
		{
			constitution = c;
			checkState();
		}
	}

	void Character::setDexterity(int d)
	{
		if (validateStatistic(d))
		{
			dexterity = d;
			checkState();
		}
	}

	void Character::setWisdom(int w)
	{
		if (validateStatistic(w))
		{
			wisdom = w;
			checkState();
		}
	}

	void Character::setCharisma(int ch)
	{
		if (validateStatistic(ch))
		{
			charisma = ch;
			checkState();
		}
	}

	void Character::setIntelligence(int i)
	{
		if (validateStatistic(i))
		{
			intelligence = i;
			checkState();
		}
	}

	//!Ability Modifiers
	void Character::setStrengthModifier(int sM)
	{
		strengthModifier = sM;
		checkState();
	}

	void Character::setConstitutionModifier(int cM)
	{
		constitutionModifier = cM;
		checkState();
	}

	void Character::setDexterityModifier(int dM)
	{
		dexterityModifier = dM;
		checkState();
	}

	void Character::setWisdomModifier(int wM)
	{
		wisdomModifier = wM;
		checkState();
	}

	void Character::setCharismaModifier(int chM)
	{
		charismaModifier = chM; 
		checkState();
	}

	void Character::setIntelligenceModifier(int iM)
	{
		intelligenceModifier = iM;
		checkState();
	}


	//!Combat Statistics
	void Character::setHitPoints(int hP)
	{
		hitPoints = hP;
		checkState();
	}

	void Character::setCurrentHitPoints(int cHP)
	{
		currentHitPoints = cHP;
		checkState();
	}

	void Character::setArmorClass(int aC)
	{
		armorClass = aC;
		checkState();
	}

	void Character::setMeleeAttackBonus(int mAB)
	{

		meleeAttackBonus = mAB;
		checkState();
	}

	void Character::setMeleeAttackDamage(int mAD)
	{
		meleeAttackDamage = mAD;
		checkState();
	}

	void Character::setRangedAttackBonus(int rAB)
	{
		rangedAttackBonus = rAB;
		checkState();
	}

	void Character::setRangedAttackDamage(int rAD)
	{
		rangedAttackDamage = rAD; 
		checkState();
	}

	void Character::setCharacterType(int st)
	{
		if (st < 5 || st > 7)
			characterType = 0;
		else characterType = st;
	}

	//!Other Information
	void Character::setName(string n)
	{
		name = n;
	}

	void Character::setInConstructor(bool i)
	{
		inConstructor = i;
	}

	//!Equipment
	void Character::setArmor(string a)
	{
		armor = a;
	}

	void Character::setShield(string s)
	{
		shield = s;
	}

	void Character::setWeapon(string w)
	{
		weapon = w;
	}

	void Character::setBoots(string b)
	{
		boots = b;
	}

	void Character::setRing(string r)
	{
		ring = r;
	}

	void Character::setHelmet(string h)
	{
		helmet = h;
	}

	
	
	///////Statistics Accessors////////
	//!Ability Scores and Level
	inline int Character::getLevel()
	{
		return level;
	}

	inline int Character::getStrength()
	{
		return strength;
	}

	inline int Character::getConstitution() 
	{
		return constitution;
	}

	inline int Character::getDexterity()
	{
		return dexterity;
	}

	inline int Character::getWisdom() 
	{
		return wisdom;
	}

	inline int Character::getCharisma()
	{
		return charisma;
	}

	inline int Character::getIntelligence() 
	{
		return intelligence;
	}

	//!Ability Modifiers
	inline int Character::getStrengthModifier()
	{
		return strengthModifier;
	}

	inline int Character::getConstitutionModifier()
	{
		return constitutionModifier;
	}

	inline int Character::getDexterityModifier()
	{
		return dexterityModifier;
	}

	inline int Character::getWisdomModifier()
	{
		return wisdomModifier;
	}

	inline int Character::getCharismaModifier()
	{
		return charismaModifier;
	}

	inline int Character::getIntelligenceModifier()
	{
		return intelligenceModifier;
	}

	//!Combat Statistics
	inline int Character::getHitPoints()
	{
		return hitPoints;
	}

	inline int Character::getCurrentHitPoints()
	{
		return currentHitPoints;
	}

	inline int Character::getArmorClass()
	{
		return armorClass;
	}

	inline int Character::getMeleeAttackBonus()
	{
		return meleeAttackBonus;
	}

	inline int Character::getMeleeAttackDamage()
	{
		return meleeAttackDamage;
	}

	inline int Character::getRangedAttackBonus()
	{
		return rangedAttackBonus;
	}

	inline int Character::getRangedAttackDamage()
	{
		return rangedAttackDamage;
	}


	//!Other Information Accessor
	inline string Character::getName()
	{
		return name;
	}

	inline bool Character::getInConstructor()
	{
		return inConstructor;
	}

	//!Equipment
	inline string Character::getArmor()
	{
		return armor;
	}

	inline string Character::getWeapon()
	{
		return weapon;
	}

	inline string Character::getShield()
	{
		return shield;
	}

	inline string Character::getBoots()
	{
		return boots;
	}
	
	inline string Character::getRing()
	{
		return ring;
	}

	inline string Character::getHelmet()
	{
		return helmet;
	}

	int Character::type()
	{
		return characterType;
	}
	

	//!Constructor////////
	Character::Character() 
	{
		//This is done so the mutators will not trigger the Observer Pattern.
		setInConstructor(true);

		//Every new character is attached to the _char CharacterObserver object, which is a subclass of Subject.
		//This algorithm is repeated in all of the constructors. 
		CharacterObserver *_charObservers = new CharacterObserver();
		_char = _charObservers;
	    _char->Attach(this);
		setCharacterType(0);
		setName("Default Joe");
		setLevel(1);
		abilityScoreGenerator(1);
		setModifiers();
		setHitPoints(hitPointsGenerator(getLevel()));
		setCurrentHitPoints(getHitPoints());
		setEquipment();

		setInConstructor(false);
		delete _charObservers;
	}

	Character::Character(int level) 
	{
		setInConstructor(true);
		
		CharacterObserver *_charObservers = new CharacterObserver();
		_char = _charObservers;
		_char->Attach(this);

		setName("John The Jolly Friend");
		if (level > 20)
		{
			cout << "Set Level is greater than 20. Level will be set to 20." << endl;
			level = 20;
		}

		if (level < 1)
		{
			cout << "Set level is smaller than 1. Level will be set to 1." << endl;
			level = 1;
		}

		setCharacterType(5);
		setLevel(level);
		abilityScoreGenerator(level);
		setModifiers();
		setHitPoints(hitPointsGenerator(getLevel()));
		setCurrentHitPoints(getHitPoints());
		setEquipment();

		setInConstructor(false);
		delete _charObservers;
		
	}

	Character::Character(int level, string name) : Character(level)
	{
		setInConstructor(true);
		setName(name);
		setInConstructor(false);
	}

	Character::Character(int level, string name, int state) : Character(level, name)
	{
		setInConstructor(true);
		setCharacterType(state);
		setInConstructor(false);
	}

	Character::Character(int s, int d, int c, int i, int w, int ch)
	{
		setInConstructor(true);
		
		CharacterObserver *_charObservers = new CharacterObserver();
		_char = _charObservers;
		_char->Attach(this);

		setCharacterType(5);
		setName("Billy");
		setEquipment();
		setLevel(1);
		setStrength(s);
		setDexterity(d);
		setConstitution(c);
		setIntelligence(i);
		setWisdom(w);
		setCharisma(ch);
		setModifiers();
		setHitPoints(10);
		setCurrentHitPoints(getHitPoints());
		
		setInConstructor(false);
		delete _charObservers;
	}
	
	Character::Character(int s, int d, int c, int i, int w, int ch, int t) : Character(s, d, c, i, w, ch, t)
	{
		setCharacterType(t);
	}

	Character::Character(Character &c)
	{
		setInConstructor(true);

		CharacterObserver *_charObservers = new CharacterObserver();
		_char = _charObservers;
		_char->Attach(this);

		setCharacterType(c.type());
		setLevel(c.getLevel());
		setName(c.getName());
		setStrength(c.getStrength());
		setDexterity(c.getDexterity());
		setConstitution(c.getConstitution());
		setIntelligence(c.getIntelligence());
		setWisdom(c.getWisdom());
		setCharisma(c.getCharisma());
		
		setStrengthModifier(c.getStrengthModifier());
		setDexterityModifier(c.getDexterityModifier());
		setConstitutionModifier(c.getConstitutionModifier());
		setIntelligenceModifier(c.getIntelligenceModifier());
		setWisdomModifier(c.getWisdomModifier());
		setCharismaModifier(c.getCharismaModifier());

		setHitPoints(c.getHitPoints());
		setCurrentHitPoints(c.getCurrentHitPoints());
		setArmorClass(c.getArmorClass());
		setMeleeAttackBonus(c.getMeleeAttackBonus());
		setMeleeAttackDamage(c.getMeleeAttackDamage());
		setRangedAttackBonus(c.getRangedAttackBonus());
		setRangedAttackDamage(c.getRangedAttackDamage());

		setEquipment();

		setInConstructor(false);
		delete _charObservers;

	}

	Character::~Character()
	{
		delete _char;
	}


	//!Generators///////
	/*!The hitpoints are generated as per the rules of dungeon and dragons and
	int accordance to the level provided.*/
	int Character::hitPointsGenerator(int lvl) 
	{
		int hP = 0;
		if (lvl == 0)
		{
			hP = hP + rand() % 10 + getConstitutionModifier();
		}
		
		for (int i = 0; i < lvl; i++)
		{
			if (i == 0)
				hP = 10 + getConstitutionModifier();
			else
				hP = hP + rand() % 10 + getConstitutionModifier();
		}
		return hP;
	}

	void Character::abilityScoreGenerator(int level)
	{
	
		const int NB_OF_ABILITIES = 6;
		const int MAX_ROLLS = 4;
		int abilityScores[NB_OF_ABILITIES];
		int rolls[MAX_ROLLS];
	
	//This outer loop is meant to iterate for all of the 6 different
	//ability points.
		for (int i = 0; i < NB_OF_ABILITIES; i++)
		{

			abilityScores[i] = 0;

	//These next two for loops make rolls, then add the best one
	//at one of the indexes of the abilities array
			for (int j = 0; j < MAX_ROLLS; j++)
				rolls[j]= rand() % 6 + 1;
			int worstRoll = rolls[0];

			for (int j = 1; j < MAX_ROLLS; j++)
			{
				if (worstRoll > rolls[j])
					worstRoll = rolls[j];
			}

			for (int j = 0; j < MAX_ROLLS; j++)
			{

				if (rolls[j] == worstRoll)
					continue;
				else
					abilityScores[i] += rolls[j];
			}

		}
	//This is the sorting alorithm such that the array is sorted in
	//decreasing order.
		for (int i = 0; i < NB_OF_ABILITIES; i++)
		{

			int temp = abilityScores[i];
			for (int j = i + 1; j < NB_OF_ABILITIES; j++) 
			{

				if (temp < abilityScores[j]) 
				{
					temp = abilityScores[j];
					abilityScores[j] = abilityScores[i];
				}

			}
			
			abilityScores[i] = temp;
			
		}
	//Extra point allocation if necessary. The allocation is done randomly,
	//as to facilitate the design and avoid user interaction in the console.
		if (level > 3)
		{
			int points = extraPoints(level);
			
			while (points > 0)
			{
				int index = rand() % 6;
				abilityScores[index]++;
				points -= 1;
			}

		}

	//These assignments are done as such that a player who would
	//choose the Fighter class would assign their stats with
	//similar importance.
		setStrength(abilityScores[0]);
		setConstitution(abilityScores[1]);
		setDexterity(abilityScores[2]);
		setWisdom(abilityScores[3]);
		setCharisma(abilityScores[4]);
		setIntelligence(abilityScores[5]);
		
	}

	
	int Character::extraPoints(int lvl)
	{
		switch (lvl)
		{
		case 4:
		case 5:
			return 2;
			
		case 6:
		case 7:
			return 4;
			
		case 8:
		case 9:
		case 10:
		case 11:
			return 6;
			
		case 12:
		case 13:
			return 8;
			
		case 14:
		case 15:
			return 10;

		case 16:
		case 17:
		case 18:
			return 12;
		
		case 19:
		case 20:
			return 14;

		default:
			return 0;
		}
		

	}

	//The modifiers are set as per the DnD guidelines by calling the
	//modifierCalculation() function. 
	//Take note that the seemingly over-complex implementation of
	//these attributes is to facilitate the development of the
	//classe project in the long run.
	void Character::setModifiers() {

		setStrengthModifier  (modifierCalculation  (getStrength()  )  );
		setConstitutionModifier(modifierCalculation  (getConstitution()  )  );
		setDexterityModifier  (modifierCalculation  (getDexterity()  )  );
		setWisdomModifier  (modifierCalculation  (getWisdom()  )  );
		setCharismaModifier  (modifierCalculation  (getCharisma()  )  );
		setIntelligenceModifier  (modifierCalculation  (getIntelligence()  )  );

		setArmorClass(10 + getDexterityModifier());
		setMeleeAttackBonus(getStrengthModifier());
		setMeleeAttackDamage(getStrengthModifier());
		setRangedAttackBonus(getDexterityModifier());
		setRangedAttackDamage(getDexterityModifier());

	}

	int Character::modifierCalculation(int stat) 
	{

		switch (stat)
		{
		case 1:
			return -5;
		case 2:
		case 3:
			return -4;
		case 4:
		case 5:
			return -3;
		case 6:
		case 7:
			return -2;
		case 8:
		case 9:
			return -1;
		case 10:
		case 11:
			return 0;
		case 12:
		case 13:
			return 1;
		case 14:
		case 15:
			return 2;
		case 16:
		case 17:
			return 3;
		case 18:
		case 19:
			return 4;
		default:
				return 666;
		}

	}

	//This was only designed as the per the instructions for the proper implementation
	//of the relevant test case.
	void Character::hit(int dmg)
	{
		currentHitPoints = currentHitPoints - dmg;
	}

	void Character::levelUp()
	{
		int lvl = getLevel();
		setLevel(lvl++);
		if (lvl == 4 || lvl == 6 || lvl == 8 || lvl == 12 || lvl == 14 || lvl == 16 || lvl == 19)
		{
			for (int i = 0; i < 2; i++)
			{
				int point = rand() % 6;
				switch (point)
				{
				case 0:
					setStrength(getStrength() + 1);
				case 1:
					setDexterity(getDexterity() + 1);

				case 2:
					setConstitution(getConstitution() + 1);
				case 3:
					setIntelligence(getIntelligence() + 1);
				case 4:
					setWisdom(getWisdom() + 1);
				case 5:
					setCharisma(getCharisma() + 1);
				default:
						 break;
				}
			}
		}
		setModifiers();
		setHitPoints(getHitPoints() + hitPointsGenerator(0));

	}
	void Character::levelUp(int x)
	{
		for (int i = 0; i < x; i++)
			levelUp();
	}

	//This checks that the attributes of a character respect the DnD guidelines 
	//(3 <= attribute <= 18)
	bool Character::validateNewCharacter()
	{
		if (3 > getStrength() || getStrength() > 18 ||
			3 > getConstitution() || getConstitution() > 18 ||
			3 > getDexterity() || getDexterity() > 18 ||
			3 > getIntelligence() || getIntelligence() > 18 ||
			3 > getWisdom() || getWisdom() > 18 ||
			3 > getCharisma() || getCharisma() > 18)
		{
			cout << "This character is invalid" << endl;
			return false;
		}
			
		else
			return true;
	}

	bool Character::validateStatistic(int s)
	{
		if (s > 18 || s < 3)
			return false;
		else
			return true;
	}
	//Setting the equipment is done through strings. This simple implementation
	//was done after discussing with Dr. Taleb.
	void Character::setEquipment()
	{
		setArmor("Chain Mail");
		setShield("Shield");
		setWeapon("Longsword & Light Crossbow");
		setBoots("Leather Boots");
		setRing("None");
		setHelmet("None");
	}
	
	void Character::printCharacter()
	{

		cout << "*******  " << getName() << " *******\n\n"
			<< "Level: " << getLevel() << endl
			<< "Strength:  " << getStrength() << modOP(getStrengthModifier()) << getStrengthModifier() << ")\n"
			<< "Dexterity:  " << getDexterity() << modOP(getDexterityModifier()) << getDexterityModifier() << ")\n"
			<< "Constitution:  " << getConstitution() << modOP(getConstitutionModifier()) << getConstitutionModifier() << ")\n"
			<< "Intelligence:  " << getIntelligence() << modOP(getIntelligenceModifier()) << getIntelligenceModifier() << ")\n"
			<< "Wisdom:  " << getWisdom() << modOP(getWisdomModifier()) << getWisdomModifier() << ")\n"
			<< "Charisma:  " << getCharisma() << modOP(getCharismaModifier()) << getCharismaModifier() << ")\n"
			<< "Hit Points: " << getCurrentHitPoints() << "     Armor Class: " << getArmorClass() << endl
			<< "Melee Attack Bonus: +" << getMeleeAttackBonus() << "   Melee Damage Bonus: +" << getMeleeAttackDamage() << endl
			<< "Ranged Attack Bonus: +" << getRangedAttackBonus() << "   Ranged Damage Bonus: +" << getRangedAttackBonus() << endl
			<< "Equipment: \nArmor: " << getArmor() << endl
			<< "Shield: " << getShield() << endl
			<< "Weapon: " << getWeapon() << endl
			<< "Boots: " << getBoots() << endl
			<< "Ring: " << getRing()  << endl
			<< "Helmet: " << getHelmet() << endl;

	}
	//method to print a "+" or "-" depending on value of modifier
	string Character::modOP(int m)
	{
		if (m >= 0)
			return (" (+");
		else
			return (" (");
	}
	
	//Character being observable, this is the method which is invoked in Subject when the concrete subject is notified.
	void Character::update() {
		//The boolean value updating is only used for the sake of test cases.
		updating = true;
		printCharacter();
	}
	
	//This method is used to ensure that the Observer pattern is only triggered when the program is not using the mutators within the constructor.
	//If not in the constructor, the CharacterObserver pointer attribute of the Character class invokes the changeToCharacter method to trigger the
	//Observer pattern.
	void Character::checkState()
	{
		if (!getInConstructor())
			_char->changeToCharacter();
	}

	void Character::Serialize(CArchive& arch)
	{
		CObject::Serialize(arch);

		if (arch.IsStoring())
		{
			CString n(name.c_str());
			arch << n << level << strength << dexterity << constitution << wisdom 
				<< intelligence << charisma << strengthModifier << dexterityModifier 
				<< constitutionModifier << wisdomModifier << intelligenceModifier 
				<< charismaModifier << hitPoints << armorClass << meleeAttackBonus 
				<< meleeAttackDamage << rangedAttackBonus << rangedAttackDamage;
		}

		else
		{
			CString n;
			arch >> n >> level >> strength >> dexterity >> constitution >> wisdom
				>> intelligence >> charisma >> strengthModifier >> dexterityModifier
				>> constitutionModifier >> wisdomModifier >> intelligenceModifier
				>> charismaModifier >> hitPoints >> armorClass >> meleeAttackBonus
				>> meleeAttackDamage >> rangedAttackBonus >> rangedAttackDamage;
			
			CT2CA converter(n);
			string nameTemp(converter);
			name = nameTemp;
		}
	}

	void Character::save()
	{
		
		CFile save;
		save.Open(_T("CharacterSave.txt"), CFile::modeCreate | CFile::modeWrite);
		CArchive archie(&save, CArchive::store);

		Character* _character = new Character(*this);
		_character->Serialize(archie);

		delete _character;
		archie.Close();
		save.Close();
		
	}
	

	
	 Character* Character::load()
	{
		CFile load;
		load.Open(_T("CharacterSave.txt"), CFile::modeRead);
		CArchive archie(&load, CArchive::load);

		Character* _character = new Character();
		_character->Serialize(archie);
		
		archie.Close();
		load.Close();
		return _character;
		
	}

}


