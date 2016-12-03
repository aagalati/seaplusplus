#pragma once
#include "Grid.h"
#include "Node.h"
#include <vector>
using std::vector;
#include <queue>

class BFS
{
public:

	BFS();
	BFS(Grid*, int, int, int, int);
	~BFS();

	void toNodeGrid(Grid*);
	
	std::vector<std::vector<Node>> search();
	std::vector<Node> get(std::vector<std::vector<Node>>);
	std::vector<Node> search(int);

	inline bool canGo(Node*);

	inline bool canPass(Node*);

	vector<Node> neighbor(Node);

	//void addWalls(Node);

private:
	int width;
	int height;
	
	int start;
	int goal;
	
	Node startN;

	
	
	std::vector<std::vector<Node>> nodeGrid;
	std::queue <Node> flag;
	std::vector<Node> walls;
	std::vector<std::vector<int>> move = {{0,1},{1,0}, {0,-1}, {-1,0}};
	
	std::vector <std::vector<Node>> keepTrack;
	
	std::vector <Node> keepT;
	
};

