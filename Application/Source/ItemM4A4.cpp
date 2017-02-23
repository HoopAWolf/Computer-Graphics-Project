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
		attack_speed_ = .2;
		timer_ = 0;

		rarity_ = UNCOMMON;

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