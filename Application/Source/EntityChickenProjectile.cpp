#ifndef _ENTITY_CHICKEN_PROJECTILE_H_
#define _ENTITY_CHICKEN_PROJECTILE_H_

#include "EntityProjectile.h"
#include "MapBase.h"

class EntityChickenProjectile : public EntityProjectile
{
	float timer_;

public:
	EntityChickenProjectile(Vector3 position, Vector3 forward, unsigned damage, float timer)
	{
		texture_string_ = "chicken_";
		projectileID_ = 2;
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

	void updateAI(float timer, unsigned dimensionID)
	{
		unsigned MOVING_SPEED = 50;

		if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
			((int)(position_.x + (forward_.x * (MOVING_SPEED * 0.017)))),
			((int)(position_.z + (forward_.z * (MOVING_SPEED * 0.017))))) != '#')
		{
			position_ += (forward_ * (MOVING_SPEED * 0.017));
		}
		else
		{
			health_ = 0;
		}

		if (position_.y > 0)
		{
			position_.y -= .02;
		}

		if (timer > timer_ + 5)
			health_ = 0;
	}

};

#endif