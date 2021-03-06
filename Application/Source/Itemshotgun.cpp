#ifndef ITEM_SHOTGUN
#define ITEM_SHOTGUN

#include "ItemWeapon.h"

class Itemshotgun : public ItemWeapon
{
	float timer_;

public:
	Itemshotgun()
	{
		itemID_ = 1;
		texture_string_ = "shotgun";
		item_name_ = "Shotgun";

		recoil_ = .2;
		weapon_type_ = RANGE_AUTO;
		durability_ = 43;
		damage_ = 20;
		attack_speed_ = 3;
		bulletcount_ = 20;
		timer_ = 0;

		rarity_ = COMMON;
		price_ = 40;
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
			EntityBullet* bullet = new EntityBullet(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer, true);
			timer_ = timer;
			return bullet;
		}

		return nullptr;

	}
};

#endif