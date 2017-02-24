#ifndef ITEM_SHURIKEN
#define ITEM_SHURIKEN

#include "ItemWeapon.h"

class ItemShuriken : public ItemWeapon
{
public:
	ItemShuriken()
	{
		itemID_ = 4;
		texture_string_ = "shuriken";
		item_name_ = "Shuriken";


		weapon_type_ = MEDIUM;
		durability_ = 25;
		damage_ = 10;
		attack_speed_ = 4;
		bulletcount_ = 10;

		rarity_ = COMMON;
		price_ = 10;
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