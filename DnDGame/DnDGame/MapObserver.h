#pragma once
#include "Subject.h"
#include "Observer.h"

class MapObserver : public Subject
{
public:
	MapObserver();
	void changeToGrid();
	~MapObserver();
};

