#include "stdafx.h"
#include "Campaign.h"
#include <iostream>


Campaign::Campaign()
{
	
}


Campaign::~Campaign()
{
}

Campaign::Campaign(std::string campaignName)
{
	this->campaignName = campaignName;

}

Campaign::Campaign(const Campaign& orig) : gridlist(orig.gridlist.size()) {
	for (std::size_t i = 0; i < orig.gridlist.size(); ++i)
		gridlist[i] = new Grid(orig.gridlist[i]); 
	this->campaignName = orig.campaignName;

}

std::string Campaign::getCampaignName() const
{
	return campaignName;
}

void Campaign::addGrid(Grid* g)
{
	gridlist.push_back(g);
}

void Campaign::removeGrid(int i)
{
	gridlist.erase(gridlist.begin() + i);
}

void Campaign::editCampaign(int n)
{

}