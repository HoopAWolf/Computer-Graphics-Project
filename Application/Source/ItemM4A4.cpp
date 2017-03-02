#include "ItemM4A4.h"
#include "DataBase.h"

EntityProjectile* ItemM4A4::onItemAttackProjectile(float timer, float dt)
{
	if (timer > timer_ + ((attack_speed_ / 100.) * 100))
	{
		EntityBullet* bullet = new EntityBullet(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer, true);
		timer_ = timer;
		DataBase::instance()->playSoundFromStringSG("m4a4");
		return bullet;
	}

	return nullptr;
}
