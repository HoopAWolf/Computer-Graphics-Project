#ifndef ITEM_MINIGUN
#define ITEM_MINIGUN

#include "ItemWeapon.h"

class ItemMinigun : public ItemWeapon
{
	unsigned timer_ = 0;

public:
	ItemMinigun()
	{
		itemID_ = 17;
		texture_string_ = "mini_gun";
		item_name_ = "Minigun";


		weapon_type_ = RANGE_AUTO;
		durability_ = 250;
		damage_ = 10;
		attack_speed_ = 6;

		rarity_ = LEGENDARY;
	}

	 void onItemUse(float timer){}

	//------------------USES------------------
	EntityProjectile* onItemAttackProjectile(float timer)
	{
		if (timer > timer_ + (timer * ((10 - attack_speed_) / 100.)))
		{
			EntityFireBall* fireball = new EntityFireBall(Camera::position, Camera::forward, damage_);
			return fireball;
		}
		
		return nullptr;
	}
};

#endif