#ifndef ITEM_MINIGUN
#define ITEM_MINIGUN

#include "ItemWeapon.h"

class ItemMinigun : public ItemWeapon
{
	float timer_;

public:
	ItemMinigun()
	{
		itemID_ = 15;
		texture_string_ = "mini_gun";
		item_name_ = "Minigun";

		recoil_ = .05;
		weapon_type_ = RANGE_AUTO;
		durability_ = 250;
		damage_ = 10;
		attack_speed_ = .01;
		timer_ = 0;
		bulletcount_ = 1;

		rarity_ = LEGENDARY;
		price_ = 1670;
	}

	void onItemUse(float timer, float dt){}

	//------------------USES------------------
	EntityProjectile* onItemAttackProjectile(float timer, float dt);
};

#endif