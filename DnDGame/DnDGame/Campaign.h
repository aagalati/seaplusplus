#pragma once
//#include <afx.h>

#include <iostream>
#include <vector>
#include "DNDObject.h"

#include "Grid.h"

using std::string;

class Campaign
{
public:

	//Constructors
	Campaign();
	~Campaign();
	Campaign(std::string campaignName);
	//Copy
	Campaign(const Campaign& orig);

	
	//Accessor
	std::string getCampaignName() const;

	//Mutators
	void addGrid(Grid* g);
	void removeGrid(int i);
	void editCampaign(int n); 



private:
	std::vector<Grid*> gridlist;
	std::string campaignName;
};

