// ItemMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ItemContainer.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Weapon.h"
#include <iostream>

using namespace std;

void createItem() {
	string boolAns;
	cout << "Would you like to create an Item?" << endl << "y/n?";
	cin >> boolAns;
	if (boolAns == "y" || boolAns == "Y")
	{
		cout << "Select # of Item Type you wish to create: \n 1. Helmet\n 2. Armor\n 3. Shield\n 4. Ring\n 5. Belt\n 6. Boots\n 7. Weapon" << endl;
		int itemTypeNo;
		cin >> itemTypeNo;
		while (itemTypeNo < 1 || itemTypeNo > 7) {
			cin >> itemTypeNo;
		}
		Item* createdItem = nullptr;
		switch (itemTypeNo) {
		case 1: createdItem = new Helmet(); break;
		case 2: createdItem = new Armor(); break;
		case 3: createdItem = new Shield(); break;
		case 4: createdItem = new Ring(); break;
		case 5: createdItem = new Belt(); break;
		case 6: createdItem = new Boots(); break;
		case 7: createdItem = new Weapon(); break;
		}


		cout << "Input name of Item" << endl;
		string nameItem;
		cin >> nameItem;
		createdItem->setItemName(nameItem);
		cout << "Enhancement Type may be: \n 1. Intelligence\n 2. Wisdom\n 3. Strength\n 4. Constitution\n 5. Charisma\n 6. Dexterity\n 7. ArmorClass\n 8. AttackBonus\n 9. DamageBonus\n" << endl;
		int enhChoice;
		cin >> enhChoice;
		while (enhChoice < 1 || enhChoice > 9) {
			cout << "Wrong Choice. Input again.";
			cin >> enhChoice;
		}
		Item::EnhancementType enType;
		switch (enhChoice) {
		case 1:  enType = Item::Intelligence; break;
		case 2: enType = Item::Wisdom; break;
		case 3: enType = Item::Strength; break;
		case 4: enType = Item::Constitution; break;
		case 5: enType = Item::Charisma; break;
		case 6: enType = Item::Dexterity; break;
		case 7: enType = Item::ArmorClass; break;
		case 8: enType = Item::AttackBonus; break;
		case 9: enType = Item::DamageBonus; break;
		}
		int enBonus;
		cout << "Input a # between 1 and 5 for Enhancement Bonus: ";
		cin >> enBonus;
		while (enBonus < 1 || enBonus > 5) {
			cout << "Wrong Choice. Input again.";
			cin >> enBonus;
		}

		createdItem->setEnhancement(enType, enBonus);
		createdItem->displayItem();
	}
}

/*EXample of equipped container
ItemContainer equipped("Equipped Items");

Helmet* helmet = new Helmet("helmet", Helmet::Wisdom, 2);
Armor* armor = new Armor("armor", Armor::ArmorClass, 1);
Shield* shield = new Shield("shield", Shield::ArmorClass, 3);
Ring* ring = new Ring("ring", Ring::ArmorClass, 2);
Belt* belt = new Belt("belt", Belt::Strength, 1);
Boots* boots = new Boots("boots", Boots::ArmorClass, 3);
Weapon* weapon = new Weapon("weapon", Weapon::AttackBonus, 3);

equipped.storeItem(*helmet);
equipped.storeItem(*armor);
equipped.storeItem(*shield);
equipped.storeItem(*ring);
equipped.storeItem(*belt);
equipped.storeItem(*boots);
equipped.storeItem(*weapon);
equipped.displayContainer();

*/
int main()
{
	int x;
	Helmet* ite = new Helmet("Iron Helm", Helmet::Wisdom, 2);
	Armor* ite2 = new Armor("Iron Armor", Armor::ArmorClass, 1);
	Helmet* ite3 = new Helmet("Crown", Helmet::Intelligence, 3);
	ItemContainer ic("Container1");
	ic.storeItem(*ite);
	ic.storeItem(*ite2);
	ic.storeItem(*ite3);

	ite->displayItem();
	ic.displayContainer();
	createItem();
	ic.displayAndDropItem();
	cin >> x;
    return 0;
	
}

