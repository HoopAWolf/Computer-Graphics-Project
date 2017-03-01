#include "EntitySpawner.h"
#include "DataBase.h"

void EntitySpawner::updateAI(float timer, unsigned dimensionID, float dt)
{

	if (dimensionID == 1)
	{
		size_ = Vector3(15, 3, 15);
	}

	EntityMinion* minion;
	if (timer >= timer_ + 20)
	{
		if (dimensionID == 2)
		{
			forward_ = (Camera::position - position_).Normalized();
			forward_.y -= .3;
			EntityFireBall* bullet = new EntityFireBall(position_, forward_, damage_, timer, false);
			DataBase::instance()->setEntity(dimensionID, bullet);
		}

		for (int i = 0; i < 3; i++)
		{
			if (dimensionID == 1)
			{ 
				if (rand() % 100 < 50)
				{

					minion = new MeleeMinion_1(position_, Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0));
					DataBase::instance()->setEntity(false, true, false, dimensionID, minion);

				}
				else
				{

					minion = new MeleeMinion_2(position_, Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0));
					DataBase::instance()->setEntity(false, true, false, dimensionID, minion);

				}
			}
			else if (dimensionID == 2)
			{
				if (rand() % 100 < 50)
				{

					minion = new MeleeMinion_2(Vector3(position_.x + 9, 0, position_.z + 9), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0));
					DataBase::instance()->setEntity(false, true, false, dimensionID, minion);

				}
				else
				{

					minion = new RangedMinion_1(Vector3(position_.x - 9, 0, position_.z), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0));
					DataBase::instance()->setEntity(false, true, false, dimensionID, minion);

				}
			}
		}

		timer_ = timer;
	}

}