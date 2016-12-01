#pragma once
#include <vector>
using std::vector;

class Node
{
public:

	Node(){}
	Node(int xp, int yp) {
		x = xp; y = yp;}
	
	Node(int xp, int yp, int d) {
		x = xp; y = yp; t = d;}
	~Node() {};

	Node(const Node &n) {
		x = n.x; y = n.y; t = n.t;
	}
	
	int getX() const { return x; }
	int getY() const { return y; }
	int getT() const { return t; }
	vector<Node> getNeighbours() { return neighbours; }
	
	inline bool operator==(const Node &n) const {
		return (x == n.x && y == n.y);
	}

	inline void operator=(const Node &n) {
		x = n.x; y = n.y; t = n.t;
	}

	inline bool operator!=(const Node &n) const {
		return (x != n.x && y != n.y && t != n.t);
	}
	//void setNeighbours(Node);


protected:
	int x;
	int y;
	int t;
	std::vector<Node> neighbours;
	
	
	

};

