#pragma once
#define _AFXDLL
#include <afx.h>

#include "DNDObject.h"
#include <string>
using namespace std;
class Structure : public DNDObject, public CObject
{

private:

	int typeOfStructure;

public:
	DECLARE_SERIAL(Structure)
	
	int type();
	string toString();
	
	Structure();
	Structure(int);
	Structure(const Structure&);
	~Structure();

	//serial stuff
	virtual void Serialize(CArchive& ar);
	void save();
	Structure* load();

};

