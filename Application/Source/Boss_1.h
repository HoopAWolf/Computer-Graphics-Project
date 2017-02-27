#ifndef BOSS_1
#define BOSS_1

#include "EntityBoss.h"
#include "PlayerBase.h"
#include "MapBase.h"

class Boss_1 : public EntityBoss
{
	float tempDT, timer_, third_attacks_;
	int randomNum;
	Vector3 newTarget;

public:
	Boss_1(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "boss_1_body";
		multiple_texture_string_[1] = "boss_1_arm_1";
		multiple_texture_string_[2] = "boss_1_arm_2";
		multiple_texture_string_[3] = "boss_1_leg_1";
		multiple_texture_string_[4] = "boss_1_leg_2";
		elemental_type_ = EARTH;
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
		boss_name_ = "hi i am boss 1";
		bossID_ = 0;
		boss_state_ = IDLE;
		armor_ = 50;
		third_attacks_ = 1;
	}
	void onDeath()
	{
		PlayerBase::instance()->increaseCurrency(1000);
		PlayerBase::instance()->increaseExperience(4000);
	}

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