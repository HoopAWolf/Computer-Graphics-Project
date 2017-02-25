#ifndef _ENTITY_CHICKEN_PROJECTILE_H_
#define _ENTITY_CHICKEN_PROJECTILE_H_

#include "EntityProjectile.h"

class EntityChickenProjectile : public EntityProjectile
{
	float timer_;

public:
	EntityChickenProjectile(Vector3 position, Vector3 forward, unsigned damage, float timer, bool isPlayerShot)
	{
		texture_string_ = "chicken_";
		projectileID_ = 2;
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