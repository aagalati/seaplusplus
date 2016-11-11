
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(string name, EnhancementType enhType, int enhBonus);
	Weapon();
	~Weapon();

	string getItemType() const;
	const Weapon& operator=(const Weapon&);

	void setEnhancement(EnhancementType enhanceType, int enhanceBonus);

};



