#ifndef ITEM_GIGGS_GUN
#define ITEM_GIGGS_GUN

#include "ItemWeapon.h"

class ItemGiggsGun : public ItemWeapon
{
	float timer_;

public:
	ItemGiggsGun()
	{
		itemID_ = 15;
		texture_string_ = "giggs_gun";
		item_name_ = "Giggs Gun";


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