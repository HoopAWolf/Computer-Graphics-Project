#ifndef RANGEDMINION_2
#define RANGEDMINION_2

#include "EntityMinion.h"
#include "PlayerBase.h"
#include "MapBase.h"

class RangedMinion_2 : public EntityMinion
{
	float tempDT, timer_;
	Vector3 newTarget;

public:
	RangedMinion_2(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "ranged_minion_2_body";
		multiple_texture_string_[1] = "ranged_minion_2_arm_1";
		multiple_texture_string_[2] = "ranged_minion_2_arm_2";
		multiple_texture_string_[3] = "ranged_minion_2_leg_1";
		multiple_texture_string_[4] = "ranged_minion_2_leg_2";
		elemental_type_ = NONE;
		health_ = 12 + PlayerBase::instance()->getPlayerLevel();
		damage_ = 10;
		attack_speed_ = 1;
		walking_speed_ = 5;
		position_ = position;
		size_ = Vector3(2, 4, 2);
		up_ = up;
		forward_ = forward;
		right_ = right;
		target_ = target;
		timer_ = 0;
		drop_ID_ = 0;
		minion_name_ = "Minion";
		minionID_ = 3;
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