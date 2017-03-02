#ifndef ITEM_CHICKEN_GUN
#define ITEM_CHICKEN_GUN

#include "ItemWeapon.h"

class ItemChickenGun : public ItemWeapon
{

	float timer_;

public:
	ItemChickenGun()
	{
		itemID_ = 14;
		texture_string_ = "chicken_gun";
		item_name_ = "Chicken Gun";

		recoil_ = .05;
		weapon_type_ = RANGE_AUTO;
		durability_ = 280;
		damage_ = 380;
		attack_speed_ = 4;
		timer_ = 0;
		bulletcount_ = 30;

		rarity_ = LEGENDARY;

		price_ = 1500;

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
			EntityChickenProjectile* chicken = new EntityChickenProjectile(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer, true);
			timer_ = timer;
			return chicken;
		}

		return nullptr;
	}
};

#endif