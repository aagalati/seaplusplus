#include "stdafx.h"
#include "BFS.h"


BFS::BFS(Grid g, int s, int e)
{
	height = g.getHeight;
	width = g.getWidth;
	start = s;
	goal = e;
	toIntGrid(g);
}


BFS::~BFS()
{
}

void BFS::toIntGrid(Grid g)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; i < width; i++)
			intGrid[i][j] = g.getGridData[i][j].type();

}