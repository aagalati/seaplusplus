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
