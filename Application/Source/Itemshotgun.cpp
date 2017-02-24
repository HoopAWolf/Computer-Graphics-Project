#ifndef ITEM_SHOTGUN
#define ITEM_SHOTGUN

#include "ItemWeapon.h"

class Itemshotgun : public ItemWeapon
{
	float timer_;

public:
	Itemshotgun()
	{
		itemID_ = 3;
		texture_string_ = "shotgun";
		item_name_ = "Shotgun";




		weapon_type_ = RANGE_AUTO;
		durability_ = 43;
		damage_ = 20;
		attack_speed_ = 3;
		bulletcount_ = 20;
		timer_ = 0;

		rarity_ = COMMON;

	}

	//------------------USES------------------
	void onItemUse(float timer, float dt)
	{
		;
	}

	EntityProjectile* onItemAttackProjectile(float timer, float dt)
	{
		if (timer > timer_ + ((attack_speed_ / 100.) * timer_))
		{
			EntityBullet* bullet = new EntityBullet(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer);
			timer_ = timer;
			return bullet;
		}

		return nullptr;

	}
};

#endif