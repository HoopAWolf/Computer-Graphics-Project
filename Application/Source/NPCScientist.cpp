#ifndef NPC_Scientist
#define NPC_Scientist


#include "EntityNPC.h"
#include "MapBase.h"
#include "Mtx44.h"
class NPCScientist : public EntityNPC
{
public:
	NPCScientist(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		texture_string_ = "scientist_";
		elemental_type_ = NONE;
		health_ = 10;
		damage_ = 1;
		attack_speed_ = 1;
		walking_speed_ = 5;
		position_ = position;
		size_ = Vector3(2, 4, 2);
		rotation_Y_ = 90;
		up_ = up;
		forward_ = forward;
		right_ = right;
		target_ = target;
		drop_ID_ = 0;
		NPC_state_ = IDLE;
		NPCID_ = 2;
		NPC_name_ = "Hi  I am a Scientist";

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
		if (NPC_state_ == IDLE)
		{
			NPC_state_ = IDLE;
		}

		if (NPC_state_ == WALKING)
		{
			NPCWALKING = true;
		}
		else
		{
			NPCWALKING = false;
		}

	
		Mtx44 rotation;


		//Walking 


		float yaw = (80. * dt);

		rotation.SetToRotation(yaw, up_.x, up_.y, up_.z);
		forward_ = rotation * forward_;  //ROTATING SPEED

		position_= position_ + (forward_ * 10 * dt);  //MOVING SPEED
		rotation_Y_ += yaw;
		


			
	


	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}

};

#endif