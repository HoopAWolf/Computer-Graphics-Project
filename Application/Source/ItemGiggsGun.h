#ifndef ITEM_GIGGS_GUN
#define ITEM_GIGGS_GUN

#include "ItemWeapon.h"

class ItemGiggsGun : public ItemWeapon
{
	float timer_;

public:
	ItemGiggsGun()
	{
		itemID_ = 13;
		texture_string_ = "giggs_gun";
		item_name_ = "Giggs Gun";

		recoil_ = .05;
		weapon_type_ = RANGE_AUTO;
		durability_ = 45;
		damage_ = 20;
		attack_speed_ = .5;
		bulletcount_ = 3;
		timer_ = 0;

		rarity_ = LEGENDARY;

		price_ = 1420;
	}

	//------------------USES------------------
	void onItemUse(float timer, float dt)
	{

	}

	EntityProjectile* onItemAttackProjectile(float timer, float dt);
};

#endif