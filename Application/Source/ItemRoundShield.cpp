#ifndef ITEM_ROUND_SHIELD
#define ITEM_ROUND_SHIELD

#include "ItemWeapon.h"

class ItemRoundShield : public ItemWeapon
{
public:
	ItemRoundShield()
	{
		itemID_ = 17;
		texture_string_ = "round_shield";
		item_name_ = "Round Shield";

		weapon_type_ = MEDIUM;
		durability_ = 25;
		damage_ = 11;
		attack_speed_ = 2.5;
		

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif