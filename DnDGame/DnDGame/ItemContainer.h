#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <iostream>
#include <vector>

#include "Item.h"

using namespace std;

class ItemContainer
{
public:
	ItemContainer();
	virtual ~ItemContainer();
	ItemContainer(string containerName);
	ItemContainer(int);
	int getContainerSize();


	void storeItem(const Item &it);
	void dropItem(int itemNo);
	void pickupItem(int ItemNo, ItemContainer fromContainer, ItemContainer intoContainer);
	void displayContainer();
	void displayAndDropItem();
	

	vector<Item> contained;
	string containerName;
	bool accessible;

};



#endif