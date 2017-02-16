#ifndef ITEM_GREAT_SWORD
#define ITEM_GREAT_SWORD

#include "ItemWeapon.h"

class ItemGreatSword : public ItemWeapon
{
public:
	ItemGreatSword()
	{
		itemID_ = 1;
		texture_string_ = "greatsword";
		item_name_ = "Great Sword";


		weapon_type_ = HEAVY;
		durability_ = 250;
		damage_ = 150;
		attack_speed_ = 6.5;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif