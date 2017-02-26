#ifndef RANGEDMINION_1
#define RANGEDMINION_1

#include "EntityMinion.h"
#include "PlayerBase.h"
#include "MapBase.h"

class RangedMinion_1 : public EntityMinion
{
	float tempDT, timer_;
	Vector3 newTarget;

public:
	RangedMinion_1(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "ranged_minion_1_body";
		multiple_texture_string_[1] = "ranged_minion_1_arm_1";
		multiple_texture_string_[2] = "ranged_minion_1_arm_2";
		multiple_texture_string_[3] = "ranged_minion_1_leg_1";
		multiple_texture_string_[4] = "ranged_minion_1_leg_2";
		elemental_type_ = NONE;
		health_ = 250 + PlayerBase::instance()->getPlayerLevel();
		damage_ = 10;
		attack_speed_ = 1;
		walking_speed_ = 5;
		position_ = position;
		size_ = Vector3(2, 4, 2);
		up_ = up;
		forward_ = forward;
		right_ = right;
		target_ = target;
		drop_ID_ = 0;
		timer_ = 0;
		minion_name_ = "Minion";
		minionID_ = 2;
		minion_state_ = IDLE;

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