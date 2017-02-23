#ifndef _ENTITY_BULLET_H_
#define _ENTITY_BULLET_H_

#include "EntityProjectile.h"
#include "MapBase.h"

class EntityBullet : public EntityProjectile
{
	float timer_;

public:
	EntityBullet(Vector3 position, Vector3 forward, unsigned damage, float timer)
	{
		texture_string_ = "bullet";
		projectileID_ = 1;
		health_ = 1;
		position_ = position;
		forward_ = forward;
		damage_ = damage;
		size_ = Vector3(1, 1, 1);
		timer_ = timer;
	}

	unsigned getItemDrop()
	{
		return 0;
	}

	void onDeath()
	{

	}

	bool isEntityDead()
	{
		if (health_ <= 0)
			return true;
		else
			return false;
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}

	void updateAI(float timer, unsigned dimensionID, float dt)
	{
		unsigned MOVING_SPEED = 1000;

		if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
			((int)(position_.x + (forward_.x * (MOVING_SPEED * dt)))),
			((int)(position_.z + (forward_.z * (MOVING_SPEED * dt))))) != '#')
		{
			position_ += (forward_ * (MOVING_SPEED * dt));
		}
		else
		{
			health_ = 0;
		}

		if (timer > timer_ + 5)
			health_ = 0;
	}

};

#endif