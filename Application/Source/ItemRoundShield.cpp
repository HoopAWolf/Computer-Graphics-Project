#ifndef ITEM_ROUND_SHIELD
#define ITEM_ROUND_SHIELD

#include "ItemWeapon.h"

class ItemRoundShield : public ItemWeapon
{
public:
	ItemRoundShield()
	{
		itemID_ = 1;
		texture_string_ = "round_shield";
		item_name_ = "Round Shield";

		weapon_type_ = SHIELD;
		durability_ = 25;
		damage_ = 1;
		attack_speed_ = 1;
		
		rarity_ = COMMON;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif