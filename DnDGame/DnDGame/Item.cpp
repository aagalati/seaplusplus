#include "stdafx.h"
#include "Item.h"


Item::Item(){

}
Item::Item(string name, EnhancementType enhType, int enhBonus)
{
	this->name = name;
	this->enhType = enhType;
	if (enhBonus >= 0 && enhBonus <= 5)
		this->enhBonus = enhBonus;
	else
		this->enhBonus = 0;
}


Item::~Item()
{
}

//copy constructor
Item::Item(const Item& orig) {
	this->name = orig.name;
	this->enhType = orig.enhType;
	this->enhBonus = orig.enhBonus;
}

string Item::getItemName() const
{
	return name;
}

Item::EnhancementType Item::getEnhancementType() const
{
	return enhType;
}

string Item::getEnhancementTypeString() const {
	switch (getEnhancementType()) {
		case 0: return "Intelligence";
		case 1: return "Wisdom";
		case 2: return "Strength";
		case 3: return "Constitution";
		case 4: return "Charisma";
		case 5: return "Dexterity";
		case 6: return "ArmorClass";
		case 7: return "AttackBonus";
		case 8: return "DamageBonus";
		default:
				return " ";
	}
}

int Item::getEnhancementBonus() const
{
	return enhBonus;
}

string Item::getItemType() const
{
	return "Item";
}

void Item::setItemName(string itemName) 
{
	name = itemName;
}

void Item::setEnhancement(EnhancementType enhanceType, int enhanceBonus)
{
	enhType = enhanceType;
	enhBonus = enhanceBonus;
}

string Item::toString()
{
	string item = "";
	item += getItemName() + " ";
	switch (getEnhancementType())
	{
	case 0:
		item += "Int (+ " + getEnhancementBonus();
		break;
	case 1:
		item += "Wis (+ " + getEnhancementBonus();
		break;
	case 2:
		item += "Str (+ " + getEnhancementBonus();
		break;
	case 3:
		item += "Con (+ " + getEnhancementBonus();
		break;
	case 4:
		item += "Cha (+ " + getEnhancementBonus();
		break;
	case 5:
		item += "Dex (+ " + getEnhancementBonus();
		break;
	case 6:
		item += "AC (+ " + getEnhancementBonus();
		break;
	case 7:
		item += "Melee Damage (+ " + getEnhancementBonus();
		break;
	case 8:
		item += "Ranged Damage (+ " + getEnhancementBonus();
		break;
	}
}

void Item::displayItem() {
	cout << this->getItemType() << " | Name: " << this->getItemName() << " | Enhancement: " << this->getEnhancementTypeString() << " +" << this->getEnhancementBonus() << endl;
} 

