#ifndef ITEM_MINIGUN
#define ITEM_MINIGUN

#include "ItemWeapon.h"

class ItemMinigun : public ItemWeapon
{
public:
	ItemMinigun()
	{
		itemID_ = 10;
		texture_string_ = "minigun";
		item_name_ = "Minigun";


		weapon_type_ = RANGE_AUTO;
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