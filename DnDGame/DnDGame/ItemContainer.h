#pragma once
#define _AFXDLL
#include <afx.h>

#include <iostream>
#include <vector>
#include "DNDObject.h"

#include "Item.h"

using namespace std;

class ItemContainer : public DNDObject, public CObject
{
public:

	DECLARE_SERIAL(ItemContainer,CObject, 2);

	//Constructors
	ItemContainer();
	virtual ~ItemContainer();
	ItemContainer(string containerName);
	ItemContainer(int);
	ItemContainer(const ItemContainer&);
	
	int getContainerSize();


	void storeItem(const Item &it);
	void dropItem(int itemNo);
	void pickupItem(int ItemNo, ItemContainer fromContainer, ItemContainer intoContainer);
	void displayContainer();
	void displayAndDropItem();
	
	//DNDObject virtual method
	string toString();
	
	const ItemContainer& operator=(const ItemContainer&);

	//serialization stuff
	virtual void Serialize(CArchive& ar);
	void save();
	ItemContainer* load();

	//These are supposed to be protected, will be switched back after propper debugging
	vector<Item> contained;
	string containerName;
	bool accessible;

	

};



