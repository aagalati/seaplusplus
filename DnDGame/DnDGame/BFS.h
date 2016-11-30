#pragma once
#include "Grid.h"
#include <vector>

class BFS
{
public:
	BFS(Grid, int, int);
	~BFS();

	vector<vector<int>>& toIntGrid(Grid);

private:
	int width;
	int height;
	vector<vector<int>>* intGrid;
	int start;
	int goal;
};

