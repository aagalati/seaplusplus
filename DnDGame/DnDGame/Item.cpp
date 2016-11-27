#include "stdafx.h"
#include "Item.h"

IMPLEMENT_SERIAL(Item, CObject, 4)

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
	range = 0;
}
Item::Item(string name, EnhancementType enhType, int enhBonus, int _range) : Item(name, enhType, enhBonus)
{
	range = _range;
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

string Item::getStringBonus()
{
	return to_string(enhBonus);
}

string Item::getItemType() const
{
	return "Item";
}

int Item::getRange()
{
	return range;
}

int Item::type()
{
	return itemType;
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

void Item::levelUp(int level)
{
	if (level > 0 && level < 4)
		enhBonus = 0;
	else if (level >= 4 && level < 8)
		enhBonus = 1;
	else if (level >= 8 && level < 11)
		enhBonus = 2;
	else if (level >= 11 && level < 14)
		enhBonus = 3;
	else if (level >= 14 && level < 17)
		enhBonus = 4;
	else if (level >= 18 && level <= 20)
		enhBonus = 5;
}

string Item::toString()
{
	string item = "";
	item += getItemName() + " ";
	switch (getEnhancementType())
	{
	case 0:
		item += "[Int + " + getStringBonus();
		item += "]";
		break;
	case 1:
		item += "[Wis + " + getStringBonus();
		item += "]";
		break;
	case 2:
		item += "[Str + " + getStringBonus();
		item += "]";
		break;
	case 3:
		item += "[Con + " + getStringBonus();
		item += "]";
		break;
	case 4:
		item += "[Cha + " + getStringBonus();
		item += "]";
		break;
	case 5:
		item += "[Dex + " + getStringBonus();
		item += "]";
		break;
	case 6:
		item += "[AC + " + getStringBonus();
		item += "]";
		break;
	case 7:
		item += "[Melee Damage + " + getStringBonus();
		item += "]";
		break;
	case 8:
		item += "[Ranged Damage + " + getStringBonus();
		item += "]";
		break;
	}

	if (range == 1)
		item += " Melee";
	if (range >= 2)
		item += "Ranged";

	return item;
}

void Item::displayItem() {
	cout << this->getItemType() << " | Name: " << this->getItemName() << " | Enhancement: " << this->getEnhancementTypeString() << " +" << this->getEnhancementBonus() << endl;
} 

const Item& Item::operator=(const Item& i) 
{
	name = i.name;
	enhType = i.enhType;
	enhBonus = i.enhBonus;
	return *this;
}

void Item::Serialize(CArchive& archie)
{
	CObject::Serialize(archie);
	
	if (archie.IsStoring())
	{
		CString n(name.c_str());
		archie << n << (int)enhType << enhBonus;
	}

	else
	{
		CString n; int type;
		archie >> n >> type >> enhBonus;

		CT2CA converter(n);
		string nameTemp(converter);
		name = nameTemp;
		
		switch (type)
		{
		case 0:
			enhType = Intelligence;
			break;
		case 1:
			enhType = Wisdom;
			break;
		case 2:
			enhType = Strength;
			break;
		case 3:
			enhType = Constitution;
			break;
		case 4:
			enhType = Charisma;
			break;
		case 5:
			enhType = Dexterity;
			break;
		case 6:
			enhType = ArmorClass;
			break;
		case 7:
			enhType = AttackBonus;
			break;
		case 8:
			enhType = DamageBonus;
			break;
		}

	}

}
void Item::save(int _case)
{
	if (_case == 0)
	{
		CFile save;
		save.Open(_T("ItemSaved.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		CArchive archie(&save, CArchive::store);

		Item* _item = new Item(*this);
		_item->Serialize(archie);

		delete _item;
		archie.Close();
		save.Close();
	}
	else
	{
		CFile save;
		save.Open(_T("MapSave.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		CArchive archie(&save, CArchive::store);

		Item* _item = new Item(*this);
		_item->Serialize(archie);

		delete _item;
		archie.Close();
		save.Close();
	}


}
Item* Item::load(int _case)
{
	if (_case == 0)

	{
		CFile load;
		load.Open(_T("ItemSaved.txt"), CFile::modeRead);
		CArchive archie(&load, CArchive::load);

		Item* _item = new Item();
		_item->Serialize(archie);

		archie.Close();
		load.Close();

		return _item;
	}
	else
	{
		CFile load;
		load.Open(_T("MapeSave.txt"), CFile::modeRead);
		CArchive archie(&load, CArchive::load);

		Item* _item = new Item();
		_item->Serialize(archie);

		archie.Close();
		load.Close();

		return _item;
	}


}