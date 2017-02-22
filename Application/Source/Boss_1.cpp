#ifndef BOSS_1
#define BOSS_1

#include "EntityBoss.h"

class Boss_1 : public EntityBoss
{
public:
	Boss_1(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "boss_1_body";
		multiple_texture_string_[1] = "boss_1_arm_1";
		multiple_texture_string_[2] = "boss_1_arm_2";
		multiple_texture_string_[3] = "boss_1_leg_1";
		multiple_texture_string_[4] = "boss_1_leg_2";
		elemental_type_ = LIGHTNING;
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
		boss_name_ = "hi i am boss 1";
		bossID_ = 0;
		boss_state_ = IDLE;
		armor_ = 0;
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

	void updateAI(float timer, unsigned dimensionID)
	{
		if (boss_state_ == IDLE)
		{
			boss_state_ = BASIC_ATTACK;
		}

		if (boss_state_ == WALKING)
		{
			walking = true;
			if (rotateleftLeg < 20 && leftlegForward == true)
			{
				rotateleftLeg += (float)(80 * 0.017);
			}
			else
			{
				leftlegForward = false;
				leftlegBackward = true;
			}
			if (rotateleftLeg > -20 && leftlegBackward == true)
			{
				rotateleftLeg -= (float)(80 * 0.017);
			}
			else
			{
				leftlegForward = true;
				leftlegBackward = false;
			}
			if (rotaterightLeg < 20 && rightlegForward == true)
			{
				rotaterightLeg += (float)(80 * 0.017);
			}
			else
			{
				rightlegForward = false;
				rightlegBackward = true;
			}
			if (rotaterightLeg > -20 && rightlegBackward == true)
			{
				rotaterightLeg -= (float)(80 * 0.017);
			}
			else
			{
				rightlegForward = true;
				rightlegBackward = false;
			}
		}
		else
		{
			walking = false;
		}

		if (boss_state_ == BASIC_ATTACK)
		{
			attacking = true;
		}

		if (attacking == true)
		{
			rotateleftArm += (float)(80 * dt);
			if (rotateleftArm <= -90)
			{
				limit = true;
			}
			if (rotateleftArm >= 0)
			{
				limit = false;
			}
			if (limit == true)
			{
				dt = 0.017;
			}
			if (limit == false)
			{
				dt = -0.017;
			}
		}

		//=====================================================

		if (walking == false)
		{
			if (rotaterightLeg > 0)
			{
				rotaterightLeg--;
			}
			if (rotaterightLeg < 0)
			{
				rotaterightLeg++;
			}
			if (rotateleftLeg > 0)
			{
				rotateleftLeg--;
			}
			if (rotateleftLeg < 0)
			{
				rotateleftLeg++;
			}
		}

		if (attacking == false)
		{
			if (rotateleftArm <= 0)
			{
				rotateleftArm++;
			}
		}
		//=====================================================================



		//================================================================
		std::cout << getrotateleftArm() << std::endl;
		std::cout << getrotaterightLeg() << std::endl;
		std::cout << getrotateleftLeg() << std::endl;
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}


};

#endif