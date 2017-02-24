#ifndef BOSS_2
#define BOSS_2

#include "EntityBoss.h"

class Boss_2 : public EntityBoss
{
public:
	Boss_2(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "boss_2_body";
		multiple_texture_string_[1] = "boss_2_arm_1";
		multiple_texture_string_[2] = "boss_2_arm_2";
		multiple_texture_string_[3] = "boss_2_leg_1";
		multiple_texture_string_[4] = "boss_2_leg_2";
		elemental_type_ = WATER;
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
		boss_name_ = "hi i am boss 2";
		bossID_ = 1;
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
		if (boss_state_ == IDLE)
		{
			boss_state_ = SKILL_2;
		}
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
			rotaterightArmX += (float)(80 * dt);
			if (rotaterightArmX <= -90);
			{
				limit = true;
			}
			if (rotaterightArmX >= 0)
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
		//==========================================================================================
		if (boss_state_ == SKILL_1)
		{
			rotaterightArmX += (float)(80 * dt);
			if (rotaterightArmX <= -90)
			{
				limit = true;
			}
			if (rotaterightArmX >= 135)
			{
				limit = false;
			}
			if (limit == true)
			{
				dt = 0.3;
			}
			if (limit == false)
			{
				dt = -dt;
			}
		}
		//===========================================================================================
		if (boss_state_ == SKILL_2)
		{
			rotateleftArmY += (float)(80 * dt4);
			if (rotateleftArmY <= -90)
			{
				limit4 = true;
			}
			if (limit4 == true)
			{
				dt4 = 0;
				count++;
			}
			else if (limit4 == false)
			{
				dt4 = -dt;
			}
			if (count >= 200)
			{
				dt4 = dt;
				if (rotateleftArmY >= 0)
				{
					dt4 = 0;
				}
			}
		}
		//===========================================================================================
		if (boss_state_ == SKILL_3)
		{
			//shield bash?
		}
		//=============================================================================================
		if (boss_state_ == FINAL_ATTACK)
		{
			rotaterightArmX += (float)(80 * dt4);
			if (rotaterightArmX <= -90)
			{
				limit4 = true;
				count++;
			}
			if (rotaterightArmX >= 135)
			{

				limit4 = false;

			}
			if (limit4 == true && limit5 == false)
			{
				dt4 = 0.3;
			}
			if (limit4 == false && limit5 == false)
			{
				dt4 = -0.3;
			}
			if (count == 5)
			{
				limit5 = true;
			}
			if (limit5 == true)
			{
				dt4 = 0;
			}
		}
		//==============================================================================================
	}

	




	void setPosition(Vector3 position)
	{
		position_ = position;
	}
};

#endif