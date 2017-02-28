#include "EntityChickenProjectile.h"
#include "DataBase.h"
#include "PlayerBase.h"

void EntityChickenProjectile::updateAI(float timer, unsigned dimensionID, float dt)
{
	unsigned MOVING_SPEED = 50;

	if (MapBase::instance()->checkingMapDataByCoord(dimensionID,
		((int)(position_.x + (forward_.x * (MOVING_SPEED * dt)))),
		((int)(position_.z + (forward_.z * (MOVING_SPEED * dt))))) != '#')
	{
		position_ += (forward_ * (MOVING_SPEED * dt));
	}
	else
	{
		health_ = 0;
	}

	if (forward_.y > -20)
	{
		forward_.y -= .008;
	}

	if (timer > timer_ + 5)
		health_ = 0;

	if (is_player_shot_)
	{
		for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(3, dimensionID); i++)
		{
			if (getBoundingBox().isAABBInsideAABB(DataBase::instance()->getEntityBoss(dimensionID, i)->getBoundingBox()))
			{
				DataBase::instance()->getEntityBoss(dimensionID, i)->onAttacked(damage_);
				health_ = 0;
				goto here;
			}
		}

		for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(2, dimensionID); i++)
		{
			if (getBoundingBox().isAABBInsideAABB(DataBase::instance()->getEntityMinion(dimensionID, i)->getBoundingBox()))
			{
				DataBase::instance()->getEntityMinion(dimensionID, i)->onAttacked(damage_);
				health_ = 0;
				break;
			}
		}
	here:
		;
	}
	else
	{
		if (getBoundingBox().isAABBInsideAABB(PlayerBase::instance()->getBoundingBox()))
		{
			PlayerBase::instance()->playerAttacked(damage_, timer);
			health_ = 0;
		}
	}
}

