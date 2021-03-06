#ifndef MELEEMINION_1
#define MELEEMINION_1

#include "EntityMinion.h"
#include "PlayerBase.h"
#include "MapBase.h"

class MeleeMinion_1 : public EntityMinion
{
	float tempDT, timer_;
	Vector3 newTarget;

public:
	MeleeMinion_1(Vector3 position, Vector3 up, Vector3 forward, Vector3 right, Vector3 target)
	{
		multiple_texture_string_[0] = "melee_minion_1_body";
		multiple_texture_string_[1] = "melee_minion_1_arm_1";
		multiple_texture_string_[2] = "melee_minion_1_arm_2";
		multiple_texture_string_[3] = "melee_minion_1_leg_1";
		multiple_texture_string_[4] = "melee_minion_1_leg_2";
		elemental_type_ = NONE;
		health_ = 10 + PlayerBase::instance()->getPlayerLevel();
		damage_ = 5;
		attack_speed_ = 1;
		walking_speed_ = 5;
		position_ = position;
		size_ = Vector3(2, 4, 2);
		up_ = up;
		forward_ = forward;
		right_ = right;
		target_ = target;
		newTarget = target;
		drop_ID_ = 0;
		timer_ = 0;
		minion_name_ = "Minion";
		minionID_ = 0;
		minion_state_ = IDLE;
		rotation_Y_ = 90;
	}
	void onDeath()
	{
		PlayerBase::instance()->increaseCurrency(10);
		PlayerBase::instance()->increaseExperience(5);
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

	void updateAI(float timer, unsigned dimensionID, float dt)
	{
		tempDT = dt;
		switch (minion_state_)
		{
		case IDLE:
			newTarget = Vector3(Camera::position.x, position_.y, Camera::position.z);

			if ((newTarget - position_).Length() < 20)
			{
				minion_state_ = TARGET_PLAYER;
				timer_ = timer;
			}
			else
			{
				if (rand() % 100 < 20)
				{
					minion_state_ = WALKING;
					newTarget = Vector3(position_.x + ((rand() % 100 < 50) ? 10 : -10), position_.y, position_.z + ((rand() % 100 < 50) ? 10 : -10));
					timer_ = timer;
				}
			}
			break;

		case TAUNT:
			break;

		case TARGET_PLAYER:
			if (minionrotateleftLeg < 20 && minionleftlegForward == true)
			{
				minionrotateleftLeg += (float)(80 * dt);
			}
			else
			{
				minionleftlegForward = false;
				minionleftlegBackward = true;
			}
			if (minionrotateleftLeg > -20 && minionleftlegBackward == true)
			{
				minionrotateleftLeg -= (float)(80 * dt);
			}
			else
			{
				minionleftlegForward = true;
				minionleftlegBackward = false;
			}
			if (minionrotaterightLeg < 20 && minionrightlegForward == true)
			{
				minionrotaterightLeg += (float)(80 * dt);
			}
			else
			{
				minionrightlegForward = false;
				minionrightlegBackward = true;
			}
			if (minionrotaterightLeg > -20 && minionrightlegBackward == true)
			{
				minionrotaterightLeg -= (float)(80 * dt);
			}
			else
			{
				minionrightlegForward = true;
				minionrightlegBackward = false;
			}

			newTarget = Vector3(Camera::position.x, position_.y, Camera::position.z);
			try{
				forward_ = (newTarget - position_).Normalized();
			}
			catch (DivideByZero exp)
			{
				std::cout << "zero danger" << std::endl;
			}

			if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
				((int)(position_.x + (forward_.x * 10 * dt))),
				position_.z) != '#')
			{
				position_.x = position_.x + (forward_.x * 10 * dt);
			}

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				position_.x,
				((int)(position_.z + (forward_.z * 10 * dt)))) != '#')
			{
				position_.z = position_.z + (forward_.z * 10 * dt);  //MOVING SPEED
			}

			rotation_Y_ = -Math::RadianToDegree(atan2((position_ - newTarget).z, (position_ - newTarget).x)) - 90;

			if ((newTarget - position_).Length() >= 40)
			{
				minion_state_ = IDLE;
				timer_ = timer;
			}
			else if ((newTarget - position_).Length() <= 2)
			{
				minion_state_ = BASIC_ATTACK;
				timer_ = timer;
			}
			else if (timer > timer_ + 10)
			{
				minion_state_ = IDLE;
				timer_ = timer;
			}

			break;

		case WALKING:
			if (minionrotateleftLeg < 20 && minionleftlegForward == true)
			{
				minionrotateleftLeg += (float)(80 * dt);
			}
			else
			{
				minionleftlegForward = false;
				minionleftlegBackward = true;
			}
			if (minionrotateleftLeg > -20 && minionleftlegBackward == true)
			{
				minionrotateleftLeg -= (float)(80 * dt);
			}
			else
			{
				minionleftlegForward = true;
				minionleftlegBackward = false;
			}
			if (minionrotaterightLeg < 20 && minionrightlegForward == true)
			{
				minionrotaterightLeg += (float)(80 * dt);
			}
			else
			{
				minionrightlegForward = false;
				minionrightlegBackward = true;
			}
			if (minionrotaterightLeg > -20 && minionrightlegBackward == true)
			{
				minionrotaterightLeg -= (float)(80 * dt);
			}
			else
			{
				minionrightlegForward = true;
				minionrightlegBackward = false;
			}

			try{
				forward_ = (newTarget - position_).Normalized();
			}
			catch (DivideByZero exp)
			{
				std::cout << "zero danger" << std::endl;
			}

			if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
				((int)(position_.x + (forward_.x * 5 * dt))),
				position_.z) != '#')
			{
				position_.x = position_.x + (forward_.x * 5 * dt);
			}

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				position_.x,
				((int)(position_.z + (forward_.z * 5 * dt)))) != '#')
			{
				position_.z = position_.z + (forward_.z * 5 * dt);  //MOVING SPEED
			}

			rotation_Y_ = -Math::RadianToDegree(atan2((position_ - newTarget).z, (position_ - newTarget).x)) - 90;

			if ((newTarget - position_).Length() < 4)
			{
				minion_state_ = IDLE;
			}
			else if (((Vector3(Camera::position.x, position_.y, Camera::position.z)) - position_).Length() < 20)
			{
				minion_state_ = TARGET_PLAYER;
			}
			else if (timer > timer_ + 10)
			{
				minion_state_ = IDLE;
				timer_ = timer;
			}
			
			break;

		case BASIC_ATTACK:
			if (rotateminionArm <= -90 && !Minionlimit)
			{
				forward_ = (newTarget - position_).Normalized();

				if (PlayerBase::instance()->getBoundingBox().isPointInsideAABB(position_, forward_))
				{
					PlayerBase::instance()->playerAttacked(damage_, timer);
				}
				Minionlimit = true;
			}
			else if (rotateminionArm >= 0 && !Minionlimit)
			{
				Minionlimit = false;
			}
			else if (rotateminionArm >= 0 && Minionlimit)
			{
				Minionlimit = false;
				minion_state_ = TARGET_PLAYER;
			}

			if (Minionlimit)
			{
				tempDT = dt * 10;
			}
			if (!Minionlimit)
			{
				tempDT = -dt * 10;
			}

			rotateminionArm += (float)(80 * tempDT);
			break;

		case DEATH:
			break;
		}
	}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}


};

#endif