#ifndef ITEM_M4A4
#define ITEM_M4A4

#include "ItemWeapon.h"
#include "EntityFireBall.cpp"
#include "Camera3.h"

class ItemM4A4 : public ItemWeapon
{
	float timer_;
public:
	ItemM4A4()
	{
		itemID_ = 11;
		texture_string_ = "m4a4";
		item_name_ = "M4A4";


		weapon_type_ = RANGE_AUTO;
		durability_ = 43;
		damage_ = 5;
		attack_speed_ = 3;

		rarity_ = UNCOMMON;

	}

	void onItemUse(float timer){}

	//------------------USES------------------
	EntityProjectile* onItemAttackProjectile(float timer)
	{
		if (timer > timer_ + (timer * ((10 - attack_speed_) / 100.)))
		{
			EntityFireBall* fireball = new EntityFireBall(Camera::position, Camera::forward, damage_, timer);
			return fireball;
		}

		return nullptr;
	}
};

#endif