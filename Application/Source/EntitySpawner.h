#ifndef ENTITYSPAWNER_H
#define ENTITYSPAWNER_H

#include "EntityMinion.h"


class EntitySpawner : public EntityMinion
{
	float timer_ = 0;

public:
	EntitySpawner(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		texture_string_ = "spawner";

		elemental_type_ = NONE;
		health_ = 1 + PlayerBase::instance()->getPlayerLevel();
		damage_ = 10;
		attack_speed_ = 1;
		position_ = position;
		size_ = Vector3(2, 4, 2);
		drop_ID_ = 0;
		timer_ = 0;
		minion_name_ = "spawner";
		minionID_ = 5;

	}
	void onDeath(){}

	bool isEntityDead()
	{
		if (health_ <= 0)
			return true;
		else
			return false;
	}

	unsigned getItemDrop()
	{
		return drop_ID_;
	}

	void updateAI(float timer, unsigned dimensionID, float dt);

	void setPosition(Vector3 position)
	{
		position_ = position;
	}


};

#endif