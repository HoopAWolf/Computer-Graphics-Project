#ifndef ITEM_SWORD
#define ITEM_SWORD

#include "ItemWeapon.h"

class ItemSword : public ItemWeapon
{
public:
	ItemSword()
	{
		itemID_ = 6;
		texture_string_ = "sword";
		item_name_ = "Sword";

		weapon_type_ = LIGHT;
		durability_ = 15;
		damage_ = 3.5;
		attack_speed_ = 1.5;

		rarity_ = COMMON;
	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif