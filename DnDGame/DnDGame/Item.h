#pragma once

//Parent class Item

#define _AFXDLL
#include <afx.h>
#include "DNDObject.h"
#include <iostream>
#include "Dice.h"
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Item : public DNDObject, public CObject
{
public:
	
	DECLARE_SERIAL(Item)

	//Type of Attribute Bonus
	enum EnhancementType { 
		Intelligence=0, Wisdom=1, Strength=2, Constitution=3, Charisma=4, Dexterity=5,
		ArmorClass=6, AttackBonus=7, DamageBonus=8 };
	
	
	//Constructors
	Item();
	Item(std::string name, EnhancementType enhType, int enhBonus);
	Item(std::string name, EnhancementType enhType, int enhBonus, int _range);
	virtual ~Item();
	//Copy
	Item(const Item& orig);

	//Accessor
	std::string getItemName() const;
	
	EnhancementType getEnhancementType() const;
	
	std::string getEnhancementTypeString() const;
	
	int getEnhancementBonus() const;
	
	Dice getDmgRoll() const;
	
	std::string getStringBonus();
	
	virtual std::string getItemType() const;

	int getIntItemType();
	
	virtual int getRange();
	
	int type();

	//Mutators
	void setItemName(std::string itemName);
	virtual void setEnhancement(EnhancementType enhanceType, int enhanceBonus);
	void levelUp(int);
	
	//DNDObject virtual method
	std::string toString();
	virtual void displayItem();

	//Serialization stuff
	virtual void Serialize(CArchive& ar);
	void save(int);
	Item* load(int);
	std::vector<Item*> load();


	const Item& operator=(const Item&);

protected:
	std::string name;
	EnhancementType enhType;
	int enhBonus;
	
	// 1 = armor, 2 = weapon, 3 = shield, 4 = boots, 5 = belt, 6 = ring, 7 = helmet
	int itemType;
	int range;
	Dice dmgRoll;

};


