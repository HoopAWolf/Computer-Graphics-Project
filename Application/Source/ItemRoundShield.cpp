#ifndef ITEM_ROUND_SHIELD
#define ITEM_ROUND_SHIELD

#include "ItemWeapon.h"

class ItemRoundShield : public ItemWeapon
{
public:
	ItemRoundShield()
	{
		itemID_ = 0;
		texture_string_ = "texture2.tga";
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