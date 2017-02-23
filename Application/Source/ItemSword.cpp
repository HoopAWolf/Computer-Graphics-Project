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
		damage_ = 3;
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