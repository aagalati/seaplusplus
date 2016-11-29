#pragma once
#define _AFXDLL
#include <afx.h>

#include "DNDObject.h"

using std::string;


//Representation of physical objects in Map
class Structure : public DNDObject, public CObject
{

private:
	//0 : floor 1: wall 3: entrance 4: exit
	int typeOfStructure;
	bool canGo;
	Structure* toNextMap;

public:
	DECLARE_SERIAL(Structure)
	
	int type();
	std::string toString();
	void setToNextMap(Structure);
	
	
	//Constructors
	Structure();
	Structure(int);
	Structure(const Structure&);
	~Structure();

	//serial stuff
	virtual void Serialize(CArchive& ar);
	void save();
	Structure* load();
	

};

