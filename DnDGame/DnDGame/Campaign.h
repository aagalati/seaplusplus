#pragma once
#define _AFXDLL
#include <afx.h>

#include <iostream>
#include <vector>
#include "DNDObject.h"

#include "Grid.h"

using std::string;

class Campaign : public CObject
{
public:
	DECLARE_SERIAL(Campaign)

	//Constructors
	Campaign();
	~Campaign();
	Campaign(std::string campaignName);
	//Copy
	Campaign(const Campaign& orig);

	
	//Accessor
	std::string getCampaignName() const;
	int getCampaignSize();

	//Mutators
	void addGrid(Grid g);
	//void addGrid(int i, Grid* g);
	void removeGrid(int i);
	//void editCampaign(int n); 
	

	virtual void Serialize(CArchive&);
	void save();
	Campaign* load();



private:
	std::vector<Grid*> gridlist;
	std::string campaignName;
	//int nEdges;
	//std::vector< std::vector<Grid*> > adjlist;
};

