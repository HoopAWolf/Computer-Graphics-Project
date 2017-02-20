#ifndef BOSS_4
#define BOSS_4

#include "EntityBoss.h"

class Boss_4 : public EntityBoss
{
public:
	Boss_4(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "OBJ//boss_4_body.obj";
		multiple_texture_string_[1] = "OBJ//boss_4_arm_1.obj";
		multiple_texture_string_[2] = "OBJ//boss_4_arm_2.obj";
		multiple_texture_string_[3] = "OBJ//boss_4_leg_1.obj";
		multiple_texture_string_[4] = "OBJ//boss_4_leg_2.obj";
		elemental_type_ = ELEMENTAL_TYPE(rand() % 5);
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
		boss_name_ = "hi i am boss 4";
		bossID_ = 3;
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


	void updateAI(float timer, unsigned dimensionID)
	{
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
			rotateleftArm -= (float)(80 * 0.017);
			if (rotateleftArm <= -90)
			{
				attacking = false;
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
			if (rotateleftArm < 0)
			{
				rotateleftArm++;
			}
		}
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}
};

#endif