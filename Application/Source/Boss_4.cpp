#ifndef BOSS_4
#define BOSS_4

#include "EntityBoss.h"

class Boss_4 : public EntityBoss
{
public:
	Boss_4(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "boss_4_body";
		multiple_texture_string_[1] = "boss_4_arm_1";
		multiple_texture_string_[2] = "boss_4_arm_2";
		multiple_texture_string_[3] = "boss_4_leg_1";
		multiple_texture_string_[4] = "boss_4_leg_2";
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

	unsigned getItemDrop()
	{
		return drop_ID_;
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
			rotateleftArmX += (float)(80 * dt);
			if (rotateleftArmX <= -90)
			{
				limit = true;
			}
			if (rotateleftArmX >= 0)
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
			if (rotateleftArmX < 0)
			{
				rotateleftArmX++;
			}
		}
		//=================================================================================================
		if (boss_state_ == SKILL_1)
		{
			rotateleftArmZ += (float)(80 * dt1);
			rotaterightArmZ -= (float)(80 * dt1);
			rotateleftArmX += (float)(160 * dt1);
			spin += (float)(80 * dt2);
			if (rotateleftArmZ >= 90)
			{
				limit1 = true;
			}
			if (limit1 == true)
			{
				dt1 = 0;
				dt2 = 0.05;
			}
			if (spin >= 1800)
			{
				limit2 = true;
			}
			if (limit2 == true)
			{
				spin = 0;
				dt1 = 0.017;
				dt2 = 0;
			}
		}
		//===========================================================================================
		if (boss_state_ == SKILL_2)
		{
			rotateleftArmX += (float)(80 * dt);
			rotaterightArmX += (float)(80 * dt);
			if (rotateleftArmX <= -90)
			{
				limit = true;
			}
			if (rotateleftArmX >= 135)
			{
				limit = false;
			}
			if (limit3 == true)
			{
				dt = 0.3;
			}
			if (limit3 == false)
			{
				dt = -0.017;
			}
		}
		//============================================================================================
		if (boss_state_ == SKILL_3)
		{
			//throw shuriken??
		}
		//=============================================================================================
		if (boss_state_ == FINAL_ATTACK)
		{

		}
		//==================================================================================================
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}
};

#endif