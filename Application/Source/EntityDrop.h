#ifndef _ENTITY_DROP_H_
#define _ENTITY_DROP_H_

#include "EntityBase.h"
#include "PlayerBase.h"

class EntityDrop : public EntityBase
{
	float timer_;

public:
	EntityDrop(unsigned itemID, Vector3 coord, float timer)
	{
		position_ = coord;
		size_ = Vector3(2, 2, 2);
		elemental_type_ = NONE;
		texture_string_ = "";
		health_ = 1;
		damage_ = 0;
		attack_speed_ = 0;
		walking_speed_ = 0;
		drop_ID_ = itemID;
		timer_ = timer;
	}

	unsigned getItemDrop()
	{
		return drop_ID_;
	}

	void setTextureString(string texture_string)
	{
		texture_string_ = texture_string;
	}

	void onDeath(){}

	bool isEntityDead()
	{
		if (health_ <= 0)
			return true;
		else
			return false;
	}


	void updateAI(float timer, unsigned dimensionID)
	{
		rotation_Y_ = timer * 15;
		if (getBoundingBox().isAABBInsideAABB(PlayerBase::instance()->getBoundingBox()) && !PlayerBase::instance()->isInventoryFull())
		{
			PlayerBase::instance()->addIntoPlayerInventory(drop_ID_);
			health_ = 0;
		}

		if (timer > timer_ + 60)
			health_ = 0;
	
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}

	string getDropInfo(unsigned iterator);

};

#endif