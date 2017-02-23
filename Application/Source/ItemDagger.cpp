#ifndef ITEM_DAGGER
#define ITEM_DAGGER

#include "ItemWeapon.h"

class ItemDagger : public ItemWeapon
{
public:
	ItemDagger()
	{
		itemID_ = 2;
		texture_string_ = "dagger";
		item_name_ = "Dagger";


		weapon_type_ = LIGHT;
		durability_ = 5;
		damage_ = 5;
		attack_speed_ = 1;

		rarity_ = COMMON;

	}

	//------------------USES------------------
	void onItemUse(float timer, float dt)
	{
		;
	}

	EntityProjectile* onItemAttackProjectile(float timer, float dt)
	{

		return nullptr;

	}
};

#endif