#include "ItemChickenGun.h"
#include "DataBase.h"

EntityProjectile* ItemChickenGun::onItemAttackProjectile(float timer, float dt)
{
	if (timer > timer_ + ((attack_speed_ / 100.) * 100))
	{
		EntityChickenProjectile* chicken = new EntityChickenProjectile(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer, true);
		timer_ = timer;
		DataBase::instance()->playSoundFromStringSG("chicken_gun");
		return chicken;
	}

	return nullptr;
}