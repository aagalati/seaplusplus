// FighterCharacter.cpp : Defines the entry point for the console application.
//
#include <memory>
#include "stdafx.h"
#include "Character.h"


using std::string;

	IMPLEMENT_SERIAL(Character, CObject, 0)

		Character::Character() noexcept
	{
		setInConstructor(true);
		defaultEquip();
		setCharacterType(5);
		setMovement(3);
		setRemMovement(3);
		setLevel(1);
		extraAttacks(1);
		setNbOfAttacksLeft(getNbOfAttacks());
	}
	Character::Character(int lvl) noexcept
	{
		setInConstructor(true);
		defaultEquip();
		setCharacterType(5);
		setMovement(3);
		setRemMovement(3);
		setLevel(lvl);
		extraAttacks(lvl);
		setNbOfAttacksLeft(getNbOfAttacks());
	}


	Character::Character(const int level,const std::string name) noexcept : Character(level)
	{
		setInConstructor(true);
		setName(name);
		setInConstructor(false);
	}

	Character::Character(const int level, const std::string name, const int state) noexcept : Character(level, name)
	{
		setInConstructor(true);
		setCharacterType(state);
		setInConstructor(false);
	}

	Character::Character(const int s, const int d, const int c, const int i, const int w, const int ch) noexcept
	{
		setInConstructor(true);

		CharacterObserver *_charObservers = new CharacterObserver();
		_char = _charObservers;
		_char->Attach(this);

		setCharacterType(5);
		setName("Billy");
		defaultEquip();
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

	Character::Character(const int s, const int d, const int c, const int i, const int w, const int ch, const int t) noexcept : Character(s, d, c, i, w, ch, t)
	{
		setCharacterType(t);
	}

	Character::Character(Character &c) noexcept
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

		setMovement(c.getMovement());
		setNbOfAttacks(c.getNbOfAttacks());

		setBackpack(c.getBackpack());
		setEquipment(c.getEquipment());

		setInConstructor(false);
		delete _charObservers;

	}
		////////Statistics Mutators////////
		//!Ability Scores and Level

		
		//The mutators have been modified from assignment 1 with the addition of a checkState() method, which is what triggers the Observer pattern
		void Character::setLevel(const int l) noexcept
	{
		level = l;
		//checkState();
	}

	void Character::setStrength(const int s) noexcept
	{
		if (validateStatistic(s))
		{
			strength = s;
			//checkState();
		}
	}

	void Character::setConstitution(const int c) noexcept
	{
		if (validateStatistic(c))
		{
			constitution = c;
			//checkState();
		}
	}

	void Character::setDexterity(const int d) noexcept
	{
		if (validateStatistic(d))
		{
			dexterity = d;
			//checkState();
		}
	}

	void Character::setWisdom(const int w) noexcept
	{
		if (validateStatistic(w))
		{
			wisdom = w;
			//checkState();
		}
	}

	void Character::setCharisma(const int ch) noexcept
	{
		if (validateStatistic(ch))
		{
			charisma = ch;
			//checkState();
		}
	}

	void Character::setIntelligence(const int i) noexcept
	{
		if (validateStatistic(i))
		{
			intelligence = i;
			//checkState();
		}
	}

	//!Ability Modifiers
	void Character::setStrengthModifier(const int sM) noexcept
	{
		strengthModifier = sM;
		//checkState();
	}

	void Character::setConstitutionModifier(const int cM) noexcept
	{
		constitutionModifier = cM;
		//checkState();
	}

	void Character::setDexterityModifier(const int dM) noexcept
	{
		dexterityModifier = dM;
		//checkState();
	}

	void Character::setWisdomModifier(const int wM) noexcept
	{
		wisdomModifier = wM;
		//checkState();
	}

	void Character::setCharismaModifier(const int chM) noexcept
	{
		charismaModifier = chM;
		//checkState();
	}

	void Character::setIntelligenceModifier(const int iM) noexcept
	{
		intelligenceModifier = iM;
		//checkState();
	}


	//!Combat Statistics
	void Character::setHitPoints(const int hP) noexcept
	{
		hitPoints = hP;
		//checkState();
	}

	void Character::setCurrentHitPoints(const int cHP) noexcept
	{
		currentHitPoints = cHP;
		//checkState();
	}

	void Character::setArmorClass(const int aC) noexcept
	{
		armorClass = aC;
		//checkState();
	}

	void Character::setMeleeAttackBonus(const int mAB) noexcept
	{

		meleeAttackBonus = mAB;
		//checkState();
	}

	void Character::setMeleeAttackDamage(const int mAD) noexcept
	{
		meleeAttackDamage = mAD;
		//checkState();
	}

	void Character::setRangedAttackBonus(const int rAB) noexcept
	{
		rangedAttackBonus = rAB;
		//checkState();
	}

	void Character::setRangedAttackDamage(const int rAD) noexcept
	{
		rangedAttackDamage = rAD;
		//checkState();
	}

	void Character::setMovement(const int m) noexcept
	{
		movement = m;
	}

	void Character::setRemMovement(int m) noexcept
	{
		remMovement = m;
	}

	void Character::setNbOfAttacks(const int nb) noexcept
	{
		nbOfAttacks = nb;
	}

	void Character::setNbOfAttacksLeft(int b) noexcept
	{
		nbOfAttacksLeft = b;
	}
	void Character::setCharacterType(const int st) noexcept
	{
		if (st < 5 || st > 7)
			characterType = 0;
		else characterType = st;
	}

	//!Other Information
	void Character::setName(const string n) noexcept
	{
		name = n;
	}

	void Character::setInConstructor(const bool i) noexcept
	{
		inConstructor = i;
	}

	//!Equipment
	void Character::setArmor(const Armor a) noexcept
	{
		armor = a;
	}

	void Character::setShield(const Shield s) noexcept
	{
		shield = s;
	}

	void Character::setWeapon(const Weapon w) noexcept
	{
		weapon = w;
	}

	void Character::setBoots(const Boots b) noexcept
	{
		boots = b;
	}

	void Character::setBelt(const Belt b) noexcept
	{
		belt = b;
	}

	void Character::setRing(const Ring r) noexcept
	{
		ring = r;
	}

	void Character::setHelmet(const Helmet h) noexcept
	{
		helmet = h;
	}

	void Character::setEquipment(const ItemContainer e) noexcept
	{
		equipment = e;
	}

	void Character::setBackpack(const ItemContainer b) noexcept
	{
		backpack = b;
	}

	void Character::setAbilityScores(const int stat, const int change) noexcept
	{
		switch (stat)
		{
		case 0:
			{
				abilityScores[0] = change;
				break;
			}
		case 1:
		{
			abilityScores[1] = change;
			break;
		}
		case 2:
		{
			abilityScores[2] = change;
			break;
		}
		case 3:
		{
			abilityScores[3] = change;
			break;
		}
		case 4:
		{
			abilityScores[4] = change;
			break;
		}
		case 5:
		{
			abilityScores[6] = change;
			break;
		}
		case 6:
		{
			abilityScores[6] = change;
			break;
		}
		default:
			cout << "Bad value";

		}
	}

	void Character::setAbilityScores(const int str, const int cons, const int dex, const int wis, const int cha, const int inte) noexcept
	{
		abilityScores[0] = str;
		abilityScores[1] = cons;
		abilityScores[2] = dex;
		abilityScores[3] = wis;
		abilityScores[4] = cha;
		abilityScores[5] = inte;

	}
	

	void Character::setCombat(Combat e)
	{
		combatStats = e;
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

	inline int Character::getMovement()
	{
		return movement;
	}

	inline int Character::getRemMovement()
	{
		return remMovement;
	}

	inline int Character::getNbOfAttacks()
	{
		return nbOfAttacks;
	}

	inline int Character::getNbOfAttacksLeft()
	{
		return nbOfAttacksLeft;
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
	inline Armor Character::getArmor()
	{
		return armor;
	}

	inline Weapon Character::getWeapon()
	{
		return weapon;
	}

	inline Shield Character::getShield()
	{
		return shield;
	}

	inline Boots Character::getBoots()
	{
		return boots;
	}

	inline Belt Character::getBelt()
	{
		return belt;
	}
	
	inline Ring Character::getRing()
	{
		return ring;
	}

	inline Helmet Character::getHelmet()
	{
		return helmet;
	}

	inline ItemContainer Character::getEquipment()
	{
		return equipment;
	}

	inline ItemContainer Character::getBackpack()
	{
		return backpack;
	}

	int Character::type()
	{
		return characterType;
	}

	int* Character::getAbilityScores()
	{
		int* abScores;
		abScores = abilityScores;
		return abScores;
	}
	
	Combat Character::getCombat()
	{
		return combatStats;
	}

	

	Character::~Character()
	{
		//delete _char;
	}


	//!Generators///////
	/*!The hitpoints are generated as per the rules of dungeon and dragons and
	int accordance to the level provided.*/
	int Character::hitPointsGenerator(const int lvl) noexcept 
	{
		int hP = 0;
		if (lvl == 0)
			hP = hP + rand() % 10 + getConstitutionModifier();
		
		
		for (int i = 0; i < lvl; i++)
		{
			if (i == 0)
				hP = 10 + getConstitutionModifier();
			else
				hP = hP + rand() % 10 + getConstitutionModifier();
		}
		return hP;
	}

	void Character::abilityScoreGenerator(const int level) noexcept
	{
	
		const int MAX_ROLLS = 4;
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

	
	}

	void Character::setBullyAttributes()
	{
	
		setStrength(abilityScores[0]);
		setConstitution(abilityScores[1]);
		setDexterity(abilityScores[2]);
		setIntelligence(abilityScores[3]);
		setCharisma(abilityScores[4]);
		setWisdom(abilityScores[5]);

	}

	void Character::setNimbleAttributes()
	{

		setDexterity(abilityScores[0]);
		setConstitution(abilityScores[1]);
		setStrength(abilityScores[2]);
		setIntelligence(abilityScores[3]);
		setCharisma(abilityScores[4]);
		setWisdom(abilityScores[5]);

	}

	void Character::setTankAttributes()
	{

		setConstitution(abilityScores[0]);
		setDexterity(abilityScores[1]);
		setStrength(abilityScores[2]);
		setIntelligence(abilityScores[3]);
		setCharisma(abilityScores[4]);
		setWisdom(abilityScores[5]);

	}

	
	int Character::extraPoints(const int lvl) noexcept
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

	void Character::extraAttacks(const int level) noexcept
	{
		if (level < 5)
			setNbOfAttacks(1);
		if (level >= 5 && level < 11)
			setNbOfAttacks(2);
		if (level >= 11 && level < 20)
			setNbOfAttacks(3);
		if (level == 20)
			setNbOfAttacks(4);
			
	}

	//The modifiers are set as per the DnD guidelines by calling the
	//modifierCalculation() function. 
	//Take note that the seemin
	//y over-complex implementation of
	//these attributes is to facilitate the development of the
	//classe project in the long run.
	void Character::setModifiers() {

		setStrengthModifier  (modifierCalculation  (getStrength()  )  );
		setConstitutionModifier(modifierCalculation  (getConstitution()  )  );
		setDexterityModifier  (modifierCalculation  (getDexterity()  )  );
		setWisdomModifier  (modifierCalculation  (getWisdom()  )  );
		setCharismaModifier  (modifierCalculation  (getCharisma()  )  );
		setIntelligenceModifier  (modifierCalculation  (getIntelligence()  )  );

		setArmorClass(16);
		setMeleeAttackBonus(getStrengthModifier());
		setMeleeAttackDamage(getStrengthModifier());
		setRangedAttackBonus(getDexterityModifier());
		setRangedAttackDamage(getDexterityModifier());

		setEquipmentModifiers();

	}

	int Character::modifierCalculation(const int stat) noexcept 
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
	void Character::hit(const int dmg) noexcept
	{
		currentHitPoints = currentHitPoints - dmg;
		if (currentHitPoints < 0)
			currentHitPoints = 0;
	}

	
	void Character::levelUp() noexcept
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
	void Character::levelUp(const int x) noexcept
	{
		for (int i = 0; i < x; i++)
			levelUp();
	}

	void Character::levelDown() noexcept
	{
		int lvl = getLevel();
		setLevel(lvl--);
		
		if (lvl == 3 || lvl == 5 || lvl == 7 || lvl == 11 || lvl == 13 || lvl == 15 || lvl == 18)
		{
			for (int i = 0; i < 2; i++)
			{
				int point = rand() % 6;
				switch (point)
				{
				case 0:
					setStrength(getStrength() - 1);
				case 1:
					setDexterity(getDexterity() - 1);

				case 2:
					setConstitution(getConstitution() - 1);
				case 3:
					setIntelligence(getIntelligence() - 1);
				case 4:
					setWisdom(getWisdom() - 1);
				case 5:
					setCharisma(getCharisma() - 1);
				default:
					break;
				}
			}
		}
	}

	void Character::levelDown(const int x) noexcept
	{
		for (int i = 0; i < x; i++)
			levelDown();
	}

	Grid* Character::adapt(Grid *g, Character hero) noexcept
	{

		for (int i = 0; i < g->getWidth(); i++)
			for (int j = 0; i < g->getHeight(); i++)
			{

				if (g->getGridData()[i][j]->type() == 2)
				{
					Treasure* t = dynamic_cast<Treasure*> (g->getGridData()[i][j]);
					t->levelUpContainer(hero.getLevel());
					DNDObject* o = dynamic_cast<DNDObject*> (t);
					g->getGridData()[i][j] = o;
				}

				if (g->getGridData()[i][j]->type() == 5)
				{
					Character* p = dynamic_cast<Character*> (g->getGridData()[i][j]);
					int lvlDiff = hero.getLevel() - p->getLevel();
					if (lvlDiff == 0)
						continue;
					if (lvlDiff >  0)
						p->levelUp();
					if (lvlDiff < 0)
						p ->levelDown();
					DNDObject* o = dynamic_cast<Character*> (p);
					g->getGridData()[i][j] = p;
				}
			}
		return g;
	}

	//checks that the attributes of a character respect the DnD guidelines 
	//(3 <= attribute <= 18)
	bool Character::validateNewCharacter() noexcept
	{
		if (3 > getStrength() || getStrength() > 18 ||
			3 > getConstitution() || getConstitution() > 18 ||
			3 > getDexterity() || getDexterity() > 18 ||
			3 > getIntelligence() || getIntelligence() > 18 ||
			3 > getWisdom() || getWisdom() > 18 ||
			3 > getCharisma() || getCharisma() > 18)
		{
			std::cout << "This character is invalid" << std::endl;
			return false;
		}
			
		else
			return true;
	}

	bool Character::validateStatistic(const int s) noexcept
	{
		if (s > 18 || s < 3)
			return false;
		else
			return true;
	}
	

	void Character::defaultEquip() noexcept
	{
		
		Armor chainmail("Chain Mail", Item::ArmorClass, 0);
		setArmorClass(16);

		Weapon longsword("Longsword", Item::AttackBonus , 0, 1, 1, 8);
		Shield shield("Iron Shield", Item::ArmorClass, 1);
		Boots boots("Leather Boots", Item::Dexterity, 0);
		Ring ring("Papa's Ring", Item::Constitution, 1);
		Belt belt("Mama's Belt", Item::Intelligence, 1);
		Helmet helmet("Harambe's Wisdom", Item::Wisdom, 2);

		setArmor(chainmail); 
		setWeapon(longsword);
		setShield(shield);
		setBoots(boots);
		setRing(ring);
		setBelt(belt);
		setHelmet(helmet);
		
		storeEquipment();
	
	}

	void Character::storeEquipment() noexcept
	{

		Item* a = new Armor(getArmor());
		Item* b = new Shield(getShield());
		Item* c = new Weapon(getWeapon());
		Item* d = new Boots(getBoots());
		Item* e = new Ring(getRing());
		Item* f = new Belt(getBelt());
		Item* g = new Helmet(getHelmet());
		
		equipment.contained.clear();
		equipment.contained.push_back(a);
		equipment.contained.push_back(b);
		equipment.contained.push_back(c);
		equipment.contained.push_back(d);
		equipment.contained.push_back(e);
		equipment.contained.push_back(f);
		equipment.contained.push_back(g);

		setEquipmentModifiers();
	}

	void Character::equip(Item* i) noexcept
	{
		int type = i->type();

		if (type == 1)
		{
			Armor* a = new Armor(getArmor());
			getBackpack().storeItem(a);
			Armor newArmor(i);
			setArmor(newArmor);
		}

		else if (type == 2)
		{
			Weapon* a = new Weapon(getWeapon());
			getBackpack().storeItem(a);
			Weapon newWeapon(i);
			setWeapon(newWeapon);
		}

		else if (type == 3)
		{
			Shield* a = new Shield(getShield());
			getBackpack().storeItem(a);
			Shield newShield(i);
			setShield(newShield);
		}
		else if (type == 4)
		{
			Boots* a = new Boots(getBoots());
			getBackpack().storeItem(a);
			Boots newBoots(i);
			setBoots(newBoots);
		}
		else if (type == 5)
		{
			Belt* a = new Belt(getBelt());
			getBackpack().storeItem(a);
			Belt newBelt(i);
			setBelt(newBelt);
		}
		else if (type == 6)
		{
			Ring* a = new Ring(getRing());
			getBackpack().storeItem(a);
			Ring newRing(i);
			setRing(newRing);
		}
		else if (type == 7)
		{
			Helmet* a = new Helmet(getHelmet());
			getBackpack().storeItem(a);
			Helmet newHelmet(i);
			setHelmet(i);
		}
		else
			return;
		
		storeEquipment();
	}
	

	
	void Character::setEquipmentModifiers() noexcept
	{
		for (int i = 0; i < equipment.contained.size(); i++)
		{
			int type = equipment.contained[i]->getEnhancementType();
			int bonus = equipment.contained[i]->getEnhancementBonus();
			switch (type)
			{
			case 0:
				setIntelligenceModifier(getIntelligenceModifier() + bonus);
				break;
			case 1:
				setWisdomModifier(getWisdomModifier() + bonus);
				break;
			case 2:
				setStrengthModifier(getStrengthModifier() + bonus);
				break;
			case 3:
				setConstitutionModifier(getConstitutionModifier() + bonus);
				break;
			case 4:
				setCharismaModifier(getCharismaModifier() + bonus);
				break;
			case 5:
				setDexterityModifier(getDexterityModifier() + bonus);
				break;
			case 6:
				setArmorClass(getArmorClass() + bonus);
				break;
			case 7:
				setMeleeAttackDamage(getMeleeAttackDamage() + bonus);
				break;
			case 8:
				setRangedAttackDamage(getRangedAttackDamage() + bonus);
			default:
				break;
			}
		}
		
	}
	
	

	void Character::printCharacter() noexcept
	{
		cout << toString() << std::endl;
	}

	string Character::toString() noexcept
	{
		string i = "";
		i += ("********* " + getName() + "********\n ");
		i += (" Level: "  + std::to_string(getLevel()));
		i += ("\n Strength: " + std::to_string(getStrength()) + modOP(getStrengthModifier())); i += (std::to_string(getStrengthModifier()) + ")\t");
		i += (" Dexterity: " + std::to_string(getDexterity()) + modOP(getDexterityModifier())); i += (std::to_string(getDexterityModifier()) + ")\n");
		i += (" Constitution: " + std::to_string(getConstitution()) + modOP(getConstitutionModifier())); i += (std::to_string(getConstitutionModifier()) + ")\t");
		i += (" Intelligence: " + std::to_string(getIntelligence()) + modOP(getIntelligenceModifier())); i += (std::to_string(getIntelligenceModifier()) + ")\n");
		i += (" Wisdom: " + std::to_string(getWisdom()) + modOP(getWisdomModifier())); i += (std::to_string(getWisdomModifier()) + ")\t");
		i += (" Charisma: " + std::to_string(getCharisma()) + modOP(getCharismaModifier())); i += (std::to_string(getCharismaModifier()) + ")\n");
		i += (" HitPoints: " + std::to_string(getCurrentHitPoints())); i += ("/" + std::to_string(getHitPoints()));
		i += ("\t ArmorClass: " + std::to_string(getArmorClass()));
		i += ("\n Melee Attack Bonus +" + std::to_string(getMeleeAttackBonus())); i += ("    Melee Damage Bonus: +" + std::to_string(getMeleeAttackDamage()));
		i += ("\n Ranged Attack Bonus: +" + std::to_string(getRangedAttackBonus())); i += ("    Ranged Damage Bonus: +" + std::to_string(getRangedAttackDamage()));
		i += ("\n Equipment:\n Armor: "); i += getArmor().toString(); // i += " ("; i += getArmor().getEnhancementType()
		i += ("\n Shield: " + (getShield().toString())); i += ("\n Weapon: " + (getWeapon().toString())); 
		i += ("\n Boots: " + (getBoots().toString())); i += ("\n Belt: " + (getBelt().toString()));
		i += ("\n Ring: " + (getRing().toString())); i += ("\n Helmet: " + (getHelmet().toString()));
		return i;

		
	}
	
	//method to print a "+" or "-" depending on value of modifier
	string Character::modOP(int m) noexcept
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
				<< meleeAttackDamage << rangedAttackBonus << rangedAttackDamage
				<< nbOfAttacks << movement;
		    ItemContainer* e = &equipment;
			ItemContainer* b = &backpack;
			e->Serialize(arch);
			b->Serialize(arch);

			
		}

		else
		{
			
			CString n;
			arch >> n >> level >> strength >> dexterity >> constitution >> wisdom
				>> intelligence >> charisma >> strengthModifier >> dexterityModifier
				>> constitutionModifier >> wisdomModifier >> intelligenceModifier
				>> charismaModifier >> hitPoints >> armorClass >> meleeAttackBonus
				>> meleeAttackDamage >> rangedAttackBonus >> rangedAttackDamage 
				>> nbOfAttacks >> movement;
			ItemContainer* e = new ItemContainer();
			ItemContainer* b = new ItemContainer();
			e->Serialize(arch);
			equipment = *e;
			b->Serialize(arch);
			backpack = *b;

		
			std::string tempName(CW2A(n.GetString()));
			name = tempName;
		}
	}

	void Character::save()
	{
		
		CFile save;
		save.Open(_T("CharacterSave.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		CArchive archie(&save, CArchive::store);

		Character* _character = new Character(*this);
		_character->Serialize(archie);

		delete _character;
		archie.Close();
		save.Close();
		
	}
	
	std::vector<Character*> Character::load()
	{

		std::vector <Character*> characters;
		CFile load;
		load.Open(_T("CharacterSave.txt"), CFile::modeRead);
		CArchive archie(&load, CArchive::load);

		ULONGLONG _position = load.GetPosition();
		while (_position != NULL)
		{
			Character* _character = new Character();
			_character->Serialize(archie);
			characters.push_back(_character);
			_position = load.GetPosition();
			
		}

			 archie.Close();
			 load.Close();
			 return characters;
		 
		
	}




