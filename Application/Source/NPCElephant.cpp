#ifndef NPC_Elephant
#define NPC_Elephant


#include "EntityNPC.h"


class NPCElephant : public EntityNPC
{
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

	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}

};

#endif