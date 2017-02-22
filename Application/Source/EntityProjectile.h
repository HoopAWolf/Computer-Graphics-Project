#ifndef _ENTITY_PROJECTILE_H_
#define _ENTITY_PROJECTILE_H_

#include "EntityBase.h"

class EntityProjectile abstract : public EntityBase
{
protected:
	unsigned projectileID_;

public:
	virtual ~EntityProjectile(){};

	virtual unsigned getProjectileID()
	{
		return projectileID_;
	}
};

#endif