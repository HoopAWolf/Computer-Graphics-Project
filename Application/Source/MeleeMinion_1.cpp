#ifndef MELEEMINION_1
#define MELEEMINION_1

#include "EntityMinion.h"

class MeleeMinion_1 : public EntityMinion
{
public:
	MeleeMinion_1(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "melee_minion_1_body";
		multiple_texture_string_[1] = "melee_minion_1_arm_1";
		multiple_texture_string_[2] = "melee_minion_1_arm_2";
		multiple_texture_string_[3] = "melee_minion_1_leg_1";
		multiple_texture_string_[4] = "melee_minion_1_leg_2";
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
		minion_name_ = "hi i am melee minion 1";
		minionID_ = 0;
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

	void updateAI(float timer, unsigned dimensionID)
	{
		if (minion_state_ == IDLE)
		{
			minion_state_ = IDLE;
		}

		if (minion_state_ == BASIC_ATTACK)
		{
			rotateminionArm += (float)(80 * dt);
			if (rotateminionArm <= -90);
			{
				Minionlimit = true;
			}
			if (rotateminionArm >= 0)
			{
				Minionlimit = false;
			}
			if (Minionlimit == true)
			{
				dt = 0.017;
			}
			if (Minionlimit == false)
			{
				dt = -0.017;
			}
		}
		if (minion_state_ == WALKING)
		{
			minionwalking = true;
			if (minionrotateleftLeg < 20 && minionleftlegForward == true)
			{
				minionrotateleftLeg += (float)(80 * 0.017);
			}
			else
			{
				minionleftlegForward = false;
				minionleftlegBackward = true;
			}
			if (minionrotateleftLeg > -20 && minionleftlegBackward == true)
			{
				minionrotateleftLeg -= (float)(80 * 0.017);
			}
			else
			{
				minionleftlegForward = true;
				minionleftlegBackward = false;
			}
			if (minionrotaterightLeg < 20 && minionrightlegForward == true)
			{
				minionrotaterightLeg += (float)(80 * 0.017);
			}
			else
			{
				minionrightlegForward = false;
				minionrightlegBackward = true;
			}
			if (minionrotaterightLeg > -20 && minionrightlegBackward == true)
			{
				minionrotaterightLeg -= (float)(80 * 0.017);
			}
			else
			{
				minionrightlegForward = true;
				minionrightlegBackward = false;
			}
		}
		else
		{
			minionwalking = false;
		}


		//======================================================================
		if (minion_state_ == DEATH)
		{
			
		}

		//=====================================================================
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}


};

#endif