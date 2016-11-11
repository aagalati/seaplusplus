#pragma once
//This method is the ancestor of all map objects.

//Types: 0 is floor, 1 is wall, 2 is treasure, 3 is entrance, 4 is exit, 5 is character, 6 is enemy character
#include <string>
using namespace std;
class DNDObject
{
private:
	
	int _type = 666;

public:
	
	
	DNDObject();
	~DNDObject();
	
	virtual int type();

	
	virtual string toString();

	
};

