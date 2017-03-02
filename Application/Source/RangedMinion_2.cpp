#include "RangedMinion_2.h"
#include "DataBase.h"

void RangedMinion_2::updateAI(float timer, unsigned dimensionID, float dt)
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
		else if ((newTarget - position_).Length() <= 20 && (newTarget - position_).Length() > 10)
		{
			minion_state_ = BASIC_ATTACK;
			timer_ = timer;
		}
		else if ((newTarget - position_).Length() < 7)
		{
			minion_state_ = RETREAT;
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
	case RETREAT:
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

		newTarget = Vector3(position_.x + ((rand() % 100 < 50) ? Camera::view.x + 10 : Camera::view.x + -10), position_.y, position_.z + ((rand() % 100 < 50) ? Camera::view.z + 10 : Camera::view.z + -10));
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

		if (((Vector3(Camera::position.x, position_.y, Camera::position.z)) - position_).Length() > 10)
		{
			minion_state_ = TARGET_PLAYER;
		}
		else if (timer > timer_ + 10)
		{
			minion_state_ = TARGET_PLAYER;
			timer_ = timer;
		}
		break;

	case BASIC_ATTACK:
		if (rotateminionArm >= 90 && !Minionlimit)
		{
			try{
				forward_ = (newTarget - position_).Normalized();
			}
			catch (DivideByZero exp)
			{
				std::cout << "zero danger" << std::endl;
			}
			EntityFireBall* bullet = new EntityFireBall(position_, forward_, damage_, timer, false);
			DataBase::instance()->setEntity(dimensionID, bullet);
			Minionlimit = true;



		}
		else if (rotateminionArm <= 0 && !Minionlimit)
		{
			Minionlimit = false;
		}
		else if (rotateminionArm <= 0 && Minionlimit)
		{
			Minionlimit = false;
			minion_state_ = TARGET_PLAYER;
		}

		if (Minionlimit)
		{
			tempDT = -dt * 5;
		}
		if (!Minionlimit)
		{
			tempDT = dt * 5;
		}

		rotateminionArm += (float)(80 * tempDT);
		break;

	case DEATH:
		break;
	}
}