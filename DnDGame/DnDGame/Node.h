#pragma once
#include <math.h>

class Node
{
public:
	Node();
	~Node();
	Node(int xp, int yp, int d, int p);


	int getx() const { return x; }
	int gety() const { return y; }
	int getl() const { return l; }
	int getPrio() const { return prio; }


	void updateP(const int &xGo, const int &yGo);

	void nextLevel(const int & i, int dir);

	const int & estimate(const int & xGo, const int & yGo);

	bool operator<(const Node & a);


protected:
	int x;
	int y;
	int l;
	int prio;

	

}

