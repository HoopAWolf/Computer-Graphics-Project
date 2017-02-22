#ifndef _ENTITY_FIRE_BALL_H_
#define _ENTITY_FIRE_BALL_H_

#include "EntityProjectile.h"
#include "MapBase.h"

class EntityFireBall : public EntityProjectile
{
public:
	EntityFireBall(Vector3 position, Vector3 forward, unsigned damage)
	{
		texture_string_ = "fireball";
		projectileID_ = 0;
		position_ = position;
		forward_ = forward;
		damage_ = damage;
		size_ = Vector3(1, 1, 1);
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
		unsigned MOVING_SPEED = 2;

		if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
			((int)(position_.x + (forward_.x * (MOVING_SPEED * timer)))),
			((int)(position_.z + (forward_.z * (MOVING_SPEED * timer)))) != '#'))
		{
			position_ += (forward_ * (MOVING_SPEED * timer));
		}
		else
		{
			health_ = 0;
		}
	}

};

#endif