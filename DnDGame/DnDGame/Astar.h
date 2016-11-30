#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <vector>
#include "Grid.h"
#include "Node.h"


class Astar
{
public:
	Astar();
	Astar(Grid*);
	~Astar();

	string pathFind(const int&, const int&, const int&, const int&);

	int getVertical() const { return vertical; }
	int getHorizontal() const { return horizontal; }

protected:
	
	int horizontal;
	int vertical;
	Grid* grid;
	vector <vector <int>> openmap;
	vector <vector <int>> closedmap;
	vector <vector <int>> directionmap;
	static const int dir = 8;

	vector <int> dx;
	vector <int> dy;

	

	
};

