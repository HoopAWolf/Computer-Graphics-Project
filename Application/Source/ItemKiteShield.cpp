#ifndef ITEM_KITE_SHIELD
#define ITEM_KITE_SHIELD

#include "ItemWeapon.h"

class ItemKiteShield : public ItemWeapon
{
public:
	ItemKiteShield()
	{
		itemID_ = 0;
		texture_string_ = "kite_shield";	
		item_name_ = "Kite Shield";


		weapon_type_ = SHIELD;
		durability_ = 25;
		damage_ = 2;
		attack_speed_ = 1;

		rarity_ = COMMON;

	}

	//------------------USES------------------
	void onItemUse(float timer)
	{
		;
	}

	EntityProjectile* onItemAttackProjectile(float timer)
	{

		return nullptr;

	}
};

#endif