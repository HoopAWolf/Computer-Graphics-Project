#ifndef NPC_Elephant
#define NPC_Elephant


#include "EntityNPC.h"
#include "MapBase.h"
#include "PlayerBase.h"
#include "Mtx44.h"

class NPCElephant : public EntityNPC
{
	float tempDT, timer_;
	Vector3 newTarget;
public:
	NPCElephant(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		texture_string_ = "elephant_";
		elemental_type_ = NONE;
		health_ = 10;
		damage_ = 1;
		attack_speed_ = 1;
		walking_speed_ = 5;
		position_ = position;
		size_ = Vector3(2, 4, 2);
		up_ = up;
		forward_ = forward;
		right_ = right;
		target_ = target;
		drop_ID_ = 0;
		NPC_state_ = IDLE;
		NPCID_ = 3;
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
		switch (NPC_state_)
		{
		case IDLE:

			if (rand() % 100 < 20)
			{
				NPC_state_ = WALKING;
				newTarget = Vector3(position_.x + ((rand() % 100 < 50) ? 10 : -10), position_.y, position_.z + ((rand() % 100 < 50) ? 10 : -10));
				timer_ = timer;
			}

			break;

		case WALKING:

			forward_ = (newTarget - position_).Normalized();

			if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
				((int)(position_.x + (forward_.x * 5 * dt))),
				position_.z) != '#')
			{
				position_.x = position_.x + (forward_.x * 5 * dt);
			}

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				position_.x,
				((int)(position_.z + (forward_.z * 5 * dt)))) != '#')
			{
				position_.z = position_.z + (forward_.z * 5 * dt);  //MOVING SPEED
			}

			rotation_Y_ = -Math::RadianToDegree(atan2((position_ - newTarget).z, (position_ - newTarget).x)) - 90;

			if ((newTarget - position_).Length() < 4)
			{
				NPC_state_ = IDLE;
			}
			else if (timer > timer_ + 10)
			{
				NPC_state_ = IDLE;
				timer_ = timer;
			}

			break;
		case INTERACTION:
			newTarget = Camera::position;
			rotation_Y_ = -Math::RadianToDegree(atan2((position_ - newTarget).z, (position_ - newTarget).x)) - 90;
			if (!(PlayerBase::instance()->getBoundingBox().isAABBInsideAABB(getBoundingBox().increaseBoundry(Vector3(10, 10, 10), Vector3(10, 10, 10)))))
			{
				NPC_state_ = IDLE;
			}
			break;
		}
	}

	string getInteractionString()
	{
		return "Well Hello Human";
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}

};

#endif