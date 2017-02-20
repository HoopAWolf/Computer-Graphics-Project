#ifndef ITEM_M4A4
#define ITEM_M4A4

#include "ItemWeapon.h"

class ItemM4A4 : public ItemWeapon
{
public:
	ItemM4A4()
	{
		itemID_ = 11;
		texture_string_ = "m4a4";
		item_name_ = "M4A4";


		weapon_type_ = RANGE_AUTO;
		durability_ = 43;
		damage_ = 5;
		attack_speed_ = 3;

		rarity_ = UNCOMMON;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif