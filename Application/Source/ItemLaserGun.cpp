#include "ItemLaserGun.h"
#include "DataBase.h"

EntityProjectile* ItemLaserGun::onItemAttackProjectile(float timer, float dt)
{
	if (timer > timer_ + ((attack_speed_ / 100.) * 100))
	{
		EntityFireBall* bullet = new EntityFireBall(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer, true);
		timer_ = timer;
		DataBase::instance()->playSoundFromStringSG("laser_gun");
		return bullet;
	}

	return nullptr;

}
