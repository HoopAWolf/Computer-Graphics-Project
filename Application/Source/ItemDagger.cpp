#ifndef ITEM_DAGGER
#define ITEM_DAGGER

#include "ItemWeapon.h"

class ItemDagger : public ItemWeapon
{
public:
	ItemDagger()
	{
		itemID_ = 0;
		texture_string_ = "dagger";
		item_name_ = "Dagger";


		weapon_type_ = LIGHT;
		durability_ = 5;
		damage_ = 5;
		attack_speed_ = 3;

		rarity_ = COMMON;

		price_ = 2;
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