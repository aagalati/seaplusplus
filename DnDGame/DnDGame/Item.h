#pragma once

//Parent class Item

#define _AFXDLL
#include <afx.h>

#include <iostream>
#include <string>
#include "DNDObject.h"

using namespace std;

class Item : public DNDObject, public CObject
{
public:
	
	DECLARE_SERIAL(Item)

	enum EnhancementType { 
		Intelligence=0, Wisdom=1, Strength=2, Constitution=3, Charisma=4, Dexterity=5,
		ArmorClass=6, AttackBonus=7, DamageBonus=8 };
	
	Item();
	Item(string name, EnhancementType enhType, int enhBonus);
	virtual ~Item();
	
	Item(const Item& orig);

	string getItemName() const;
	EnhancementType getEnhancementType() const;
	string getEnhancementTypeString() const;
	int getEnhancementBonus() const;
	virtual string getItemType() const;

	void setItemName(string itemName);
	virtual void setEnhancement(EnhancementType enhanceType, int enhanceBonus);
	string toString();
	virtual void displayItem();

	//serialization stuff
	virtual void Serialize(CArchive& ar);
	void save(int);
	Item* load(int);


	const Item& operator=(const Item&);

protected:
	string name;
	EnhancementType enhType;
	int enhBonus;

};


