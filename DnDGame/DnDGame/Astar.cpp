#include "stdafx.h"
#include "Astar.h"


Astar::Astar()
{
	horizontal = 0;
	vertical = 0;
}

Astar::Astar(Grid* g)
{
	grid = g;
	const int n = grid->getWidth();
	const int m = grid->getHeight();
	horizontal = n;
	vertical = m;

	dx = {1,1,0,-1,-1,-1,0,1 };
	dy = { 0,1,1,1,0,-1,-1,-1 };


}

Astar::~Astar()
{
	
}



string Astar::pathFind(const int &xstart, const int &ystart, const int &xdone, const int &ydone)
{
	priority_queue<Node> priorityQ[2];
	int pQindex = 0;
	Node* nstart;
	Node* mstartl;
	
	int i, j, px, py, xdx, ydy;
	char c;

	for (py = 0; py < vertical; py++)
	{
		for (px = 0; px < horizontal; px++)
		{
			closedmap[px][py] = 0;
			openmap[px][py] = 0;
		}
	}
	
	nstart = new Node(xstart, ystart, 0, 0);
	nstart->updateP(xdone, ydone);
	priorityQ[pQindex].push(*nstart);
	openmap[px][py] = nstart->getPrio();

	while (!priorityQ[pQindex].empty())
	{
		nstart = new Node(priorityQ[pQindex].top().getx(), priorityQ[pQindex].top().gety(), 
						priorityQ[pQindex].top().getl(), priorityQ[pQindex].top().getPrio());

		//nstart->

	}
}