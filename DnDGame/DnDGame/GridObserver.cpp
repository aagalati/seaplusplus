#include "stdafx.h"
#include "GridObserver.h"
#include <iostream>

GridObserver::GridObserver()
{
}

void GridObserver::changeToGrid() {

	//std::cout << "Notify is called" << std::endl;
	Notify(); //uses Subject::Notify

}


GridObserver::~GridObserver()
{
}
