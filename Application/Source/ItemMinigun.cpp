#ifndef ITEM_MINIGUN
#define ITEM_MINIGUN

#include "ItemWeapon.h"

class ItemMinigun : public ItemWeapon
{
public:
	ItemMinigun()
	{
		itemID_ = 17;
		texture_string_ = "mini_gun";
		item_name_ = "Minigun";


		weapon_type_ = RANGE_AUTO;
		durability_ = 250;
		damage_ = 10;
		attack_speed_ = 6;

		rarity_ = LEGENDARY;
	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif