#ifndef ITEM_SPEAR
#define ITEM_SPEAR

#include "ItemWeapon.h"

class ItemSpear : public ItemWeapon
{
public:
	ItemSpear()
	{
		itemID_ = 5;
		texture_string_ = "spear";
		item_name_ = "Spear";


		weapon_type_ = MEDIUM;
		durability_ = 27;
		damage_ = 10;
		attack_speed_ = 2;

		rarity_ = COMMON;
		price_ = 20;
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