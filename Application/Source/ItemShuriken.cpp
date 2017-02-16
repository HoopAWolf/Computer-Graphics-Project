#ifndef ITEM_SHURIKEN
#define ITEM_SHURIKEN

#include "ItemWeapon.h"

class ItemShuriken : public ItemWeapon
{
public:
	ItemShuriken()
	{
		itemID_ = 12;
		texture_string_ = "shuriken";
		item_name_ = "Shuriken";


		weapon_type_ = RANGE_AUTO;
		durability_ = 25;
		damage_ = 17;
		attack_speed_ = 3.5;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif