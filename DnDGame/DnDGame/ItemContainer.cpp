#include "stdafx.h"
#include "ItemContainer.h"


ItemContainer::ItemContainer()
{
}


ItemContainer::~ItemContainer()
{
}

ItemContainer::ItemContainer(string containerName) {
	this->containerName = containerName;
}
int ItemContainer::getContainerSize(){
	return contained.size();
}


void ItemContainer::storeItem(const Item &it){
	contained.push_back(it);
}
void ItemContainer::dropItem(int itemNo){
	contained.erase(contained.begin()+itemNo);
}
void ItemContainer::pickupItem(int itemNo, ItemContainer fromContainer, ItemContainer intoContainer){
	intoContainer.storeItem(contained[itemNo]);
	fromContainer.dropItem(itemNo);
}
void ItemContainer::displayContainer(){
	cout << "INVENTORY OF " << containerName << endl;
	int i = 0;
	for (vector<Item>::iterator iter = contained.begin(); iter != contained.end(); ++iter) {
		cout << i << " | ";
		iter->displayItem();
		i++;
	}
	cout << endl;
}

void ItemContainer::displayAndDropItem() {
	this->displayContainer();
	cout << "Input # of Item you wish to drop: ";
	int dropNo;
	cin >> dropNo;
	if (dropNo >= 0 && dropNo < contained.size()) {

		this->dropItem(dropNo);
		this->displayContainer();
	}
	else
		cout << "Wrong # input, no Item will be dropped.";
}