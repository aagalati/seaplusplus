#include "stdafx.h"
#include "ItemContainer.h"

IMPLEMENT_SERIAL(ItemContainer, CObject, 3)

ItemContainer::ItemContainer()
{
	accessible = true;
}

ItemContainer::~ItemContainer()
{
	//for (std::vector<Item*>::iterator iter = contained.begin(); iter != contained.end(); iter++)
		//delete (*iter);
}

ItemContainer::ItemContainer(std::string containerName) {
	accessible = true;
	this->containerName = containerName;
}
int ItemContainer::getContainerSize(){
	return contained.size();
}

ItemContainer::ItemContainer(int i)
{
	accessible = false;
}



ItemContainer::ItemContainer(const ItemContainer& i)
{
	accessible = i.accessible;
	
	contained = i.contained;
	
	for (int j = 0; j < i.contained.size(); j++)
	{
		storeItem(contained[j]);
	}

}

ItemContainer::ItemContainer(ItemContainer* i) 
{
	accessible = i->accessible;
	
	contained = i->contained;

	for (int i = 0; i < contained.size(); i++)
	{
		storeItem(contained[i]);
	}
}

void ItemContainer::storeItem(Item* it){
	contained.push_back(it);
}


void ItemContainer::dropItem(int itemNo){
	contained.erase(contained.begin()+itemNo);
}

void ItemContainer::pickupItem(int itemNo, ItemContainer fromContainer, ItemContainer intoContainer){
	intoContainer.storeItem(contained[itemNo]);
	fromContainer.dropItem(itemNo);
}



void ItemContainer::levelUpContainer(int lvl)
{
	for (std::vector<Item*>::iterator iter = contained.begin(); iter != contained.end(); iter++)
		(*iter)->levelUp(lvl);
	
}

std::string ItemContainer::toString()
{
	std::string content = "";
	for (std::vector<Item*>::iterator iter = contained.begin(); iter != contained.end(); ++iter)
	{
		content += (*iter)->toString();
		content += "\n ";
	}
	return content;
}

const ItemContainer& ItemContainer:: operator=(const ItemContainer& i)
{
	std::vector<Item*> iV = i.contained;

	for (int i = 0; i < iV.size(); i++)
	{
		storeItem(iV[i]);
	}
	return *this;
}

void ItemContainer::Serialize(CArchive& archie)
{
	CObject::Serialize(archie);

	if (archie.IsStoring())
	{
		archie << accessible;
		archie << getContainerSize();
		for (std::vector<Item*>::iterator iter = contained.begin(); iter != contained.end(); ++iter)
		{
			(*iter)->Serialize(archie);
		}
	}
	else
	{
		int size;
		archie >> accessible;
		archie >> size;
		for (int i = 0; i < size; i++)
		{
			Item* item = new Item();
			item->Serialize(archie);
			storeItem(item);
			delete item;
		}

	}

}



void ItemContainer::save(int a)
{
	if (a == 0)
	{
		CFile save;
		save.Open(_T("ItemSaved.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		CArchive archie(&save, CArchive::store);

		ItemContainer* _itemContainer = new ItemContainer(*this);
		_itemContainer->Serialize(archie);

		delete _itemContainer;
		archie.Close();
		save.Close();
	}
	else {
		CFile save;
		save.Open(_T("MapSave.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		CArchive archie(&save, CArchive::store);

		ItemContainer* _itemContainer = new ItemContainer(*this);
		_itemContainer->Serialize(archie);

		delete _itemContainer;
		archie.Close();
		save.Close();
	}
}

ItemContainer* ItemContainer::load(int a)
{
	if (a == 0)
	{
		CFile load;
		load.Open(_T("ItemSave.txt"), CFile::modeRead);
		CArchive archie(&load, CArchive::load);

		ItemContainer* _itemContainer = new ItemContainer();
		_itemContainer->Serialize(archie);

		archie.Close();
		load.Close();

		return _itemContainer;
	}
	else {
		CFile load;
		load.Open(_T("MapSave.txt"), CFile::modeRead);
		CArchive archie(&load, CArchive::load);

		ItemContainer* _itemContainer = new ItemContainer();
		_itemContainer->Serialize(archie);

		archie.Close();
		load.Close();

		return _itemContainer;
	}
}