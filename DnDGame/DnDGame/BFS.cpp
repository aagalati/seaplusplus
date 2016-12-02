#include "stdafx.h"
#include "BFS.h"

BFS::BFS()
{

}

BFS::BFS(Grid* g, int s, int e, int x, int y)
{
	height = g->getHeight();
	width = g->getWidth();
	start = s;
	startN = Node(x, y, s);
	goal = e;
	toNodeGrid(g);
	
}


BFS::~BFS()
{
}

void BFS::toNodeGrid(Grid* g)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; i < width; i++)
		{
			Node n(i, j, g->getGridData()[i][j]->type());
			nodeGrid[i][j] = n;
		}
}

std::vector<std::vector<Node>> BFS::search()
{
	flag.push(startN);

	keepTrack[startN.getX()][startN.getY()] = startN;

	while (!flag.empty())
	{
		Node current = flag.front();
		flag.pop();

		if (current.getT() == goal)
			break;
		for (Node i : neighbor(current))
		{
			for (int x = 0; x < width; x++)
			{
					vector<Node>::iterator iter;
					vector<Node>& inner = keepTrack[x];
					iter = inner.begin();
					for (iter; iter != inner.end(); iter++)
					{
						if (!(i == *iter))
						{
							flag.push(i);
							keepTrack[i.getX()][i.getY()] = current;
						}
					}
			}
		}
	}
	return keepTrack;
	
}

std::vector<Node> BFS::get(std::vector<std::vector<Node>> n)
{
	vector<Node> sequenceN;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			try
			{
				sequenceN.push_back(n[i][j]);
			}
			catch (const std::out_of_range& e)
			{
				continue;
			}

		}
	}
	return sequenceN;
}

std::vector<Node> BFS::search(int haramboo)
{
	flag.push(startN);

	keepT[0] = startN;

	while (!flag.empty())
	{
		Node current = flag.front();
		flag.pop();

		if (current.getT() == goal)
			break;
		for (Node i : neighbor(current))
		{
			for (vector<Node>::iterator iter = keepT.begin(); iter != keepT.end(); iter++)
				if (*iter != i)
				{
					flag.push(i);
					keepT.push_back(i);
				}
			
			
		}
	}
	return keepT;
}

std::vector<Node> BFS::neighbor(Node n)
{
	vector<Node> neighbo;
	
	for (int i = 0; i < 4; i++)
	{
		int j = i;
		int newX = n.getX() + move[i][j];
		int newY = n.getY() + move[i][j + 1];

		Node* newNode = new Node(nodeGrid[newX][newY]);
		
		if (newNode != NULL && canGo(newNode) && canPass(newNode))
			neighbo.push_back(*newNode);
	}
	return neighbo;
	
}

bool BFS::canGo(Node *n) 
{
	return (0 <= n->getX() && n->getX() < width && 0 <= n->getY() && n->getY() < height);
}

bool BFS::canPass(Node *n)
{
	return (n->getT() != 1);
}



