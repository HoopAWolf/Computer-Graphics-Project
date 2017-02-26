#ifndef ITEM_LASER_GUN
#define ITEM_LASER_GUN

#include "ItemWeapon.h"

class ItemLaserGun : public ItemWeapon
{
	float timer_;

public:
	ItemLaserGun()
	{
		itemID_ = 8;
		texture_string_ = "laser_gun";
		item_name_ = "Laser Gun";

		recoil_ = .3;
		weapon_type_ = RANGE_AUTO;
		durability_ = 10;
		damage_ = 5;
		attack_speed_ = 3;
		bulletcount_ = 80;
		timer_ = 0;

		rarity_ = UNCOMMON;

		price_ = 120;
	}

	//------------------USES------------------
	void onItemUse(float timer, float dt)
	{
		;
	}

	EntityProjectile* onItemAttackProjectile(float timer, float dt)
	{
		if (timer > timer_ + ((attack_speed_ / 100.) * 100))
		{
			EntityFireBall* bullet = new EntityFireBall(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer, true);
			timer_ = timer;
			return bullet;
		}

		return nullptr;

	}
};

#endif