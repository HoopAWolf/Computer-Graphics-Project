#ifndef ITEM_SHOTGUN
#define ITEM_SHOTGUN

#include "ItemWeapon.h"

class Itemshotgun : public ItemWeapon
{
public:
	Itemshotgun()
	{
		itemID_ = 3;
		texture_string_ = "shotgun";
		item_name_ = "Shotgun";




		weapon_type_ = RANGE_AUTO;
		durability_ = 43;
		damage_ = 20;
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