#include "stdafx.h"

#include <iostream>
using std::cout;
#include "Structure.h"

using namespace std;

Structure::Structure()
{

}

Structure::Structure(int st)
{		//floor     wall        entrance   exit
	if (st == 0 || st == 1 || st == 3 || st == 4)
		typeOfStructure = st;
	else
		cout << "Wrong integer value for structure" << endl;
}

Structure::~Structure()
{
}

int Structure::type()
{
	return typeOfStructure;
}

string Structure::toString()
{
	if (typeOfStructure = 0)
		return "Floor";
	if (typeOfStructure = 1)
		return "Wall";
	if (typeOfStructure = 3)
		return "Entrance";
	if (typeOfStructure = 4)
		return "Exit";
}
