#include "stdafx.h"
#include "DNDObject.h"
#include <string>

using namespace std;

DNDObject::DNDObject()
{
}


DNDObject::~DNDObject()
{
}

int DNDObject::type()
{
	return _type;
}

string DNDObject::toString()
{
	return "a";
}
