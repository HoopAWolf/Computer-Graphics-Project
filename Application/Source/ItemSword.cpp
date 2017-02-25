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
		attack_speed_ = 3;

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