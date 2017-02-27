#ifndef BOSS_4
#define BOSS_4

#include "EntityBoss.h"
#include "MapBase.h"
#include "PlayerBase.h"

class Boss_4 : public EntityBoss
{
	float tempDT, timer_, attack_timer_, invisible_timer_, attack_speed_timer_;
	int randomNum;
	Vector3 newTarget;

public:
	Boss_4(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "boss_4_body";
		multiple_texture_string_[1] = "boss_4_arm_1";
		multiple_texture_string_[2] = "boss_4_arm_2";
		multiple_texture_string_[3] = "boss_4_leg_1";
		multiple_texture_string_[4] = "boss_4_leg_2";
		elemental_type_ = LIGHTNING;
		health_ = 100;
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
		boss_name_ = "Flash";
		bossID_ = 3;
		boss_state_ = IDLE;
		armor_ = 30;
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