#ifndef BOSS_3
#define BOSS_3

#include "EntityBoss.h"

class Boss_3 : public EntityBoss
{
public:
	Boss_3(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "boss_3_body";
		multiple_texture_string_[1] = "boss_3_arm_1";
		multiple_texture_string_[2] = "boss_3_arm_2";
		multiple_texture_string_[3] = "boss_3_leg_1";
		multiple_texture_string_[4] = "boss_3_leg_2";
		elemental_type_ = FIRE;
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
		boss_name_ = "hi i am boss 3";
		bossID_ = 2;
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

	void updateAI(float timer, unsigned dimensionID, float dt)
	{
		if (boss_state_ == WALKING)
		{
			walking = true;
			if (rotateleftLeg < 20 && leftlegForward == true)
			{
				rotateleftLeg += (float)(80 * dt);
			}
			else
			{
				leftlegForward = false;
				leftlegBackward = true;
			}
			if (rotateleftLeg > -20 && leftlegBackward == true)
			{
				rotateleftLeg -= (float)(80 * dt);
			}
			else
			{
				leftlegForward = true;
				leftlegBackward = false;
			}
			if (rotaterightLeg < 20 && rightlegForward == true)
			{
				rotaterightLeg += (float)(80 * dt);
			}
			else
			{
				rightlegForward = false;
				rightlegBackward = true;
			}
			if (rotaterightLeg > -20 && rightlegBackward == true)
			{
				rotaterightLeg -= (float)(80 * dt);
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
				dt = dt;
			}
			if (limit == false)
			{
				dt = -dt;
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
		//=============================================================================================
		if (boss_state_ == SKILL_1)
		{
			rotateleftArmX += (float)(80 * dt);
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
				dt = -dt;
			}
		}
		//==============================================================================================
		if (boss_state_ == SKILL_2)
		{
			//shoot laser from eye?
		}
		//===========================================================================================
		if (boss_state_ == SKILL_3)
		{
			//shoot bomb??
		}
		//=============================================================================================
		if (boss_state_ == FINAL_ATTACK)
		{
			//super explosion
		}
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}
};

#endif