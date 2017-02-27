#include "EntitySpawner.h"
#include "DataBase.h"

void EntitySpawner::updateAI(float timer, unsigned dimensionID, float dt)
{
	EntityMinion* minion;
	if (timer >= timer_ + 20)
	{
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

		timer_ = timer;
	}
}