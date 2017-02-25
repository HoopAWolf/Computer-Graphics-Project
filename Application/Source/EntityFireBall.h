#ifndef _ENTITY_FIRE_BALL_H_
#define _ENTITY_FIRE_BALL_H_

#include "EntityProjectile.h"

class EntityFireBall : public EntityProjectile
{
	float timer_;

public:
	EntityFireBall(Vector3 position, Vector3 forward, unsigned damage, float timer, bool isPlayerShot)
	{
		texture_string_ = "fireball";
		projectileID_ = 0;
		health_ = 1;
		position_ = position;
		forward_ = forward;
		damage_ = damage;
		size_ = Vector3(1, 1, 1);
		timer_ = timer;
		is_player_shot_ = isPlayerShot;
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

	void updateAI(float timer, unsigned dimensionID, float dt);

};

#endif