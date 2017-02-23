#ifndef ITEM_MINIGUN
#define ITEM_MINIGUN

#include "ItemWeapon.h"

class ItemMinigun : public ItemWeapon
{
	float timer_;

public:
	ItemMinigun()
	{
		itemID_ = 17;
		texture_string_ = "mini_gun";
		item_name_ = "Minigun";


		weapon_type_ = RANGE_AUTO;
		durability_ = 250;
		damage_ = 10;
		attack_speed_ = .01;
		timer_ = 0;

		rarity_ = LEGENDARY;
	}

	void onItemUse(float timer, float dt){}

	//------------------USES------------------
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