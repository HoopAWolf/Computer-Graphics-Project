#include "Boss_4.h"
#include "DataBase.h"

void Boss_4::updateAI(float timer, unsigned dimensionID, float dt)
{

	switch (boss_state_)
	{
	case IDLE:

		newTarget = Vector3(Camera::position.x, position_.y, Camera::position.z);

		if ((newTarget - position_).Length() < 100)
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
		try{
			forward_ = (newTarget - position_).Normalized();
		}
		catch (DivideByZero exp)
		{
			std::cout << "zero danger" << std::endl;
		}

		if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
			((int)(position_.x + (forward_.x * 20 * dt))),
			position_.z) != '#')
		{
			position_.x = position_.x + (forward_.x * 20 * dt);
		}

		if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
			position_.x,
			((int)(position_.z + (forward_.z * 20 * dt)))) != '#')
		{
			position_.z = position_.z + (forward_.z * 20 * dt);  //MOVING SPEED
		}

		rotation_Y_ = -Math::RadianToDegree(atan2((position_ - newTarget).z, (position_ - newTarget).x)) - 90;

		if ((newTarget - position_).Length() >= 500)
		{
			boss_state_ = IDLE;
			timer_ = timer;
		}
		else if ((newTarget - position_).Length() <= 15)
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
					PlayerBase::instance()->playerAttacked(damage_, timer);
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
				tempDT = -dt * 4;
			}
			if (!limit)
			{
				tempDT = dt * 4;
			}

			rotateleftArmX += (float)(80 * tempDT);
		}
		else if (randomNum > 40 && randomNum <= 70)
		{
			boss_attack_state_ = SKILL_2;
			attack_timer_ = timer;
		}
		else if (randomNum > 70 && randomNum <= 90)
		{
			boss_attack_state_ = SKILL_1;
		}
		else if (randomNum > 90 && randomNum <= 100 && !is_invisible_)
		{
			boss_attack_state_ = SKILL_3;
			invisible_timer_ = timer;
		}

		break;

	case SKILL_1:
		if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
			((int)(Camera::position.x + (-Camera::view.x + 5))),
			((int)Camera::position.z + (-Camera::view.z + 5))) != '#')
		{
			setPosition(Vector3(Camera::position.x + (-Camera::view.x + 5), 0, Camera::position.z + (-Camera::view.z + 5)));
		}
		boss_attack_state_ = PASSIVE;
		break;

	case SKILL_2:

		boss_state_ = FINAL_ATTACK;
		newTarget = Vector3(Camera::position.x, position_.y, Camera::position.z);

		if (position_.y < 15 && timer < attack_timer_ + 10)
		{
			position_.y += (up_.y * 20 * dt);
			attack_timer_ = timer;
		}
		else
		{
			if (timer > attack_timer_ + 10)
			{
				if (position_.y > 0)
					position_.y -= (up_.y * 20 * dt);
				else
				{
					boss_state_ = TARGET_PLAYER;
					boss_attack_state_ = PASSIVE;
				}
			}

			if (timer > attack_speed_timer_ + .2)
			{
				try{
					forward_ = (newTarget - position_).Normalized();
				}
				catch (DivideByZero exp)
				{
					std::cout << "zero danger" << std::endl;
				}
				forward_.y -= .3;
				EntityFireBall* bullet = new EntityFireBall(position_, forward_, damage_, timer, false);
				DataBase::instance()->setEntity(dimensionID, bullet);
				attack_speed_timer_ = timer;
			}

		}
		break;

	case SKILL_3:
		is_invisible_ = true;
		boss_attack_state_ = PASSIVE;

		break;
	default:
		break;
	}

	if (is_invisible_ && timer > invisible_timer_ + 5)
	{
		is_invisible_ = false;
	}
}