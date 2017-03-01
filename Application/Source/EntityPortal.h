#ifndef _ENTITY_PORTAL_H_
#define _ENTITY_PORTAL_H_


#include "EntityNPC.h"
#include "MapBase.h"
#include "PlayerBase.h"
#include "Mtx44.h"

class EntityPortal : public EntityNPC
{
	float tempDT, timer_;
	Vector3 newTarget;
public:
	EntityPortal(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		texture_string_ = "portal";
		elemental_type_ = NONE;
		health_ = 10;
		damage_ = 1;
		attack_speed_ = 1;
		walking_speed_ = 5;
		position_ = position;
		size_ = Vector3(3, 1, 3);
		up_ = up;
		forward_ = forward;
		right_ = right;
		target_ = target;
		drop_ID_ = 0;
		NPC_state_ = IDLE;
		NPCID_ = 7;
		NPC_name_ = "Hi I am a Elephant";

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

	void updateAI(float timer, unsigned dimensionID, float dt)
	{
		tempDT = dt;
		position_.x = Camera::position.x;
		position_.z = Camera::position.z;

		if (position_.y != 0)
		{
			position_.y -= 5 * dt;
		}

		switch (NPC_state_)
		{
		case IDLE:

			break;

		case INTERACTION:
			if (PlayerBase::instance()->getBoundingBox().isAABBInsideAABB(getBoundingBox().increaseBoundry(Vector3(10, 2, 10), Vector3(10, 2, 10))))
			{
				health_ = 0;
				NPC_state_ = IDLE;
			}
			break;
		}
	}

	string getInteractionString()
	{
		return "TELEPORTING";
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}

};

#endif