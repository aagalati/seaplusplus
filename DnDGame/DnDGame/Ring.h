
#include "Item.h"
using namespace std;
class Ring : public Item
{
public:
	Ring(string name, EnhancementType enhType, int enhBonus);
	Ring();
	~Ring();

	string getItemType() const;
	const Ring& operator=(const Ring&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



