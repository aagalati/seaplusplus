#include "stdafx.h"
#include "Campaign.h"
#include <iostream>

IMPLEMENT_SERIAL(Campaign, CObject, 8)

Campaign::Campaign(){}


Campaign::~Campaign()
{
	
}

Campaign::Campaign(std::string campaignName)
{
	this->campaignName = campaignName;
}


Campaign::Campaign(const Campaign& orig) : 
	gridlist(orig.gridlist.size()) {
	for (std::size_t i = 0; i < orig.gridlist.size(); ++i)
		gridlist[i] = new Grid(orig.gridlist[i]); 
	this->campaignName = orig.campaignName;

}

std::string Campaign::getCampaignName() const
{
	return campaignName;
}

int Campaign::getCampaignSize()
{
	return gridlist.size();
}

void Campaign::addGrid(Grid g)
{
	Grid* gptr = &g;
	gridlist.push_back(gptr);
}



void Campaign::removeGrid(int i)
{
	gridlist.erase(gridlist.begin() + i);
}

/*void Campaign::editCampaign(int n)
{

}*/

void Campaign::Serialize(CArchive& archie)
{
	if (archie.IsStoring())
	{
		CString n(campaignName.c_str());

		archie << n;
		for (std::vector<Grid*>::iterator iter = gridlist.begin(); iter != gridlist.end(); iter++)
		{
			Grid* g = *iter;
			g->Serialize(archie);
	
		}
	}
	if (archie.IsLoading())
	{
		CString n;
		archie >> n;
		Grid* g = new Grid();
		g->Serialize(archie);

	}
	
}

void Campaign::save()
{
	CFile save;
	save.Open(_T("CampaignSaved.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	CArchive archie(&save, CArchive::store);

	Campaign* _campaign = new Campaign(*this);
	_campaign->Serialize(archie);

	delete _campaign;

	archie.Close();
	save.Close();
}

Campaign* Campaign::load()
{
	CFile load;
	load.Open(_T("CampaignSaved.txt"), CFile::modeRead);
	CArchive archie(&load, CArchive::load);

	Campaign* campaign = new Campaign();

	try
	{
		while (true)
		{
			Grid* g = new Grid();
			g->Serialize(archie);
			campaign->addGrid(g);
		}
	}
	catch (exception e)
	{
		return campaign;
	}
	return campaign;

}