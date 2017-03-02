#ifndef ITEM_M4A4
#define ITEM_M4A4

#include "ItemWeapon.h"

class ItemM4A4 : public ItemWeapon
{
	float timer_;
public:
	ItemM4A4()
	{
		itemID_ = 9;
		texture_string_ = "m4a4";
		item_name_ = "M4A4";

		recoil_ = .05;
		weapon_type_ = RANGE_AUTO;
		durability_ = 43;
		damage_ = 5;
		attack_speed_ = .2;
		timer_ = 0;
		bulletcount_ = 10;

		rarity_ = UNCOMMON;
		price_ = 500;
	}

	void onItemUse(float timer, float dt){}

	//------------------USES------------------
	EntityProjectile* onItemAttackProjectile(float timer, float dt);
};

#endif