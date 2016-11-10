#include "stdafx.h"

#include <iostream>
using std::cout;
#include "Structure.h"

using namespace std;

Structure::Structure()
{

}

Structure::Structure(int st)
{		//outofmap   floor     wall       entrance   exit
	if (st == -1 || st == 0 || st == 1 || st == 3 || st == 4)
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
	switch (typeOfStructure) {

	case 0: 
		return "Floor";
		break;
	case 1:
		return "Wall";
		break;
	case 3:
		return "Entrance";
		break;
	case 4:
		return "Exit";
		break;
	default: 
		return "Hover over objects to view stats";
		break;


	}
}
