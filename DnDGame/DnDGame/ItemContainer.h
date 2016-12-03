#pragma once
#define _AFXDLL
#include <afx.h>

#include <iostream>
#include <vector>
#include "DNDObject.h"

#include "Item.h"

using std::string;

class ItemContainer : public DNDObject, public CObject
{
public:

	DECLARE_SERIAL(ItemContainer);

	//Constructors
	ItemContainer();
	virtual ~ItemContainer();
	ItemContainer(std::string containerName);
	ItemContainer(int);
	ItemContainer(const ItemContainer&);
	ItemContainer(ItemContainer*);
	
	int getContainerSize();

	void storeItem(Item*);
	void dropItem(int itemNo);
	void pickupItem(int ItemNo, ItemContainer fromContainer, ItemContainer intoContainer);
	void levelUpContainer(int);
	
	
	

	//DNDObject virtual method
	std::string toString();
	
	const ItemContainer& operator=(const ItemContainer&);

	//serialization stuff
	virtual void Serialize(CArchive& ar);
	void save(int);
	ItemContainer* load(int);
	

	//These are supposed to be protected, will be switched back after propper debugging
	std::vector<Item*> contained;
	std::string containerName;
	bool accessible;

	

};



