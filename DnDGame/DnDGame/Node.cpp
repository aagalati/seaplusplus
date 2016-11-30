#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}

Node::Node(int xp, int yp, int d, int p)
{
	x = xp; y = yp; l = d; prio = p;
}


void Node::updateP(const int &xGo, const int &yGo)
{
	prio = l + estimate(xGo, yGo) * 10;
}

void Node::nextLevel(const int &i, int dir)
{
	l += (dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
}

const int& Node::estimate(const int &xGo, const int &yGo)
{
	static int xd, yd, d;
	xd = xGo - x;
	yd = yGo - y;

	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	return(d);
}

bool Node::operator<(const Node &a)
{
	return getPrio() > a.getPrio();
}
};