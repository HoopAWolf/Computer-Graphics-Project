#include "Boss_1.h"
#include "PlayerBase.h"
#include "MapBase.h"
#include "DataBase.h"

void Boss_1::updateAI(float timer, unsigned dimensionID, float dt)
{

	switch (boss_state_)
	{
	case IDLE:

		newTarget = Vector3(Camera::position.x, position_.y, Camera::position.z);

		if ((newTarget - position_).Length() < 50)
		{
			boss_state_ = TARGET_PLAYER;
			timer_ = timer;
		}
		else
		{
			if (rand() % 100 < 20)
			{
				boss_state_ = WALKING;
				newTarget = Vector3(position_.x + ((rand() % 100 < 50) ? 10 : -10), position_.y, position_.z + ((rand() % 100 < 50) ? 10 : -10));
				timer_ = timer;
			}
		}
		break;

	case TARGET_PLAYER:
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

		newTarget = Vector3(Camera::position.x, position_.y, Camera::position.z);
		forward_ = (newTarget - position_).Normalized();

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

		if ((newTarget - position_).Length() >= 100)
		{
			boss_state_ = IDLE;
			timer_ = timer;
		}
		else if ((newTarget - position_).Length() <= 10)
		{
			boss_attack_state_ = BASIC_ATTACK;
			timer_ = timer;
		}
		else if (timer > timer_ + 10)
		{
			boss_state_ = IDLE;
			timer_ = timer;
		}

		break;

	case WALKING:
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

		forward_ = (newTarget - position_).Normalized();

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
			boss_state_ = IDLE;
		}
		else if (((Vector3(Camera::position.x, position_.y, Camera::position.z)) - position_).Length() < 20)
		{
			boss_state_ = TARGET_PLAYER;
		}
		else if (timer > timer_ + 10)
		{
			boss_state_ = IDLE;
			timer_ = timer;
		}
		break;

	case FINAL_ATTACK:

		break;

	case DEATH:

		break;
	}

	switch (boss_attack_state_)
	{
	case BASIC_ATTACK:
		randomNum = rand() % 100;
		if (randomNum < 40)
		{
			if (rotateleftArmX >= 90 && !limit)
			{
				//forward_ = (newTarget - position_).Normalized();

				if (PlayerBase::instance()->getBoundingBox().isAABBInsideAABB(getBoundingBox().increaseBoundry(Vector3(4, 4, 4), Vector3(4, 4, 4))))
				{
					PlayerBase::instance()->playerAttacked(damage_);
				}
				limit = true;
			}
			else if (rotateleftArmX <= 0 && !limit)
			{
				limit = false;
			}
			else if (rotateleftArmX <= 0 && limit)
			{
				limit = false;
				boss_attack_state_ = PASSIVE;
			}

			if (limit)
			{
				tempDT = -dt * 2;
			}
			if (!limit)
			{
				tempDT = dt * 2;
			}

			rotateleftArmX += (float)(80 * tempDT);
		}
		else if (randomNum > 40 && randomNum <= 70)
		{
			boss_attack_state_ = SKILL_2;
		}
		else if (randomNum > 70 && randomNum <= 90)
		{
			boss_attack_state_ = SKILL_1;
		}
		else if (randomNum > 90 && randomNum <= 100)
		{
			boss_attack_state_ = SKILL_3;
		}

		break;

	case SKILL_1:
		EntityMinion* minion;

		for (int i = 0; i < 3; i++)
		{
			if (rand() % 100 < 50)
			{
				minion = new RangedMinion_1(position_, Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0));
				DataBase::instance()->setEntity(false, true, false, dimensionID, minion);
			}
			else
			{
				minion = new MeleeMinion_1(position_, Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0));
				DataBase::instance()->setEntity(false, true, false, dimensionID, minion);
			}
		}

		boss_attack_state_ = PASSIVE;
		break;

	case SKILL_2:
		if (rotateleftArmX >= 90 && !limit)
		{
			//forward_ = (newTarget - position_).Normalized();

			if (PlayerBase::instance()->getBoundingBox().isAABBInsideAABB(getBoundingBox().increaseBoundry(Vector3(10, 10, 10), Vector3(10, 10, 10))))
			{
				PlayerBase::instance()->playerAttacked(damage_ * 2);
			}
			limit = true;
		}
		else if (rotateleftArmX <= 0 && !limit)
		{
			limit = false;
		}
		else if (rotateleftArmX <= 0 && limit)
		{
			limit = false;
			boss_attack_state_ = PASSIVE;
		}

		if (limit)
		{
			tempDT = -dt * 5;
		}
		if (!limit)
		{
			tempDT = dt * 5;
		}

		rotateleftArmX += (float)(80 * tempDT);
		break;

	case SKILL_3:

		if (rotateleftArmX >= 90 && !limit)
		{
			//forward_ = (newTarget - position_).Normalized();

			if (PlayerBase::instance()->getBoundingBox().isAABBInsideAABB(getBoundingBox().increaseBoundry(Vector3(5, 5, 5) * third_attacks_, Vector3(5, 5, 5) * third_attacks_)))
			{
				PlayerBase::instance()->playerAttacked(damage_);
				third_attacks_++;
			}
			limit = true;
		}
		else if (rotateleftArmX <= 0 && !limit)
		{
			limit = false;
		}
		else if (rotateleftArmX <= 0 && limit)
		{
			limit = false;
			if (third_attacks_ >= 3)
			{
				third_attacks_ = 1;
				boss_attack_state_ = PASSIVE;
			}
		}

		if (limit)
		{
			tempDT = -dt * 5;
		}
		if (!limit)
		{
			tempDT = dt * 5;
		}

		rotateleftArmX += (float)(80 * tempDT);
		break;
	default:
		break;
	}

}
