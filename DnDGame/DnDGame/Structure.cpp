#include "stdafx.h"

#include <iostream>
using std::cout;
#include "Structure.h"



IMPLEMENT_SERIAL(Structure, CObject, 3)

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

Structure::Structure(const Structure& i)
{
	typeOfStructure = i.typeOfStructure;
}

Structure::~Structure()
{
}

int Structure::type()
{
	return typeOfStructure;
}

void Structure::setToNextMap(Structure entrance)
{
	if (typeOfStructure == 4 && entrance.typeOfStructure == 3)
		toNextMap = &entrance;
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

void Structure::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << typeOfStructure;
	}
	else
		ar >> typeOfStructure;

}

void Structure::save()
{
	CFile save;
	save.Open(_T("MapSave.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	CArchive archie(&save, CArchive::store);

	Structure* _structure = new Structure(*this);
	_structure->Serialize(archie);

	delete _structure;
	archie.Close();
	save.Close();
}

Structure* Structure::load()
{
	CFile load;
	load.Open(_T("MapSave.txt"), CFile::modeRead);
	CArchive archie(&load, CArchive::load);

	Structure* _structure = new Structure();
	_structure->Serialize(archie);

	archie.Close();
	load.Close();

	return _structure;

}


