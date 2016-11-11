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
	string toString();
	
	const ItemContainer& operator=(const ItemContainer&);

	//serialization stuff
	virtual void Serialize(CArchive& ar);
	void save();
	ItemContainer* load();

	
	vector<Item> contained;
	string containerName;
	bool accessible;

	

};



