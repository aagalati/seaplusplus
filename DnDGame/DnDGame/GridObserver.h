#pragma once
#include "Subject.h"
#include "Observer.h"

class GridObserver : public Subject
{
public:
	GridObserver();
	void changeToGrid();
	~GridObserver();
};

