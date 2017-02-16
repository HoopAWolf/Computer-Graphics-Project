#ifndef ITEM_KITE_SHIELD
#define ITEM_KITE_SHIELD

#include "ItemWeapon.h"

class ItemKiteShield : public ItemWeapon
{
public:
	ItemKiteShield()
	{
		itemID_ = 16;
		texture_string_ = "kite_shield";
		item_name_ = "Kite Shield";


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