#pragma once

//Parent class Item
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item    
{
public:

	enum EnhancementType { 
		Intelligence=0, Wisdom=1, Strength=2, Constitution=3, Charisma=4, Dexterity=5, ArmorClass=6, AttackBonus=7, DamageBonus=8 };
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
	virtual void displayItem();

protected:
	string name;
	EnhancementType enhType;
	int enhBonus;

};

#endif
