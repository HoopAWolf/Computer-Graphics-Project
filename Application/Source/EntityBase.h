#ifndef _ENTITY_BASE_H_
#define _ENTITY_BASE_H_

#include "ItemBase.h"
#include "Vector3.h"
#include "AABB.h"

class EntityBase abstract
{
protected:
	enum ELEMENTAL_TYPE
	{
		NONE,

		LIGHTNING,
		FIRE,
		WATER,
		EARTH
	};

	string texture_string_;
	ELEMENTAL_TYPE elemental_type_;
	int health_, rotation_Y_;
	unsigned damage_;
	unsigned attack_speed_;
	unsigned walking_speed_;
	Vector3 position_, size_, up_, forward_, right_, target_;
	ItemBase* drop_;

public:
	virtual ~EntityBase(){};

	virtual ELEMENTAL_TYPE getElementalType()
	{
		return elemental_type_;
	}

	virtual ItemBase* getItemDrop() = 0;

	virtual int getHealth()
	{
		return health_;
	}

	virtual int getRotationY()
	{
		return rotation_Y_;
	}

	virtual unsigned getDamage()
	{
		return damage_;
	}

	virtual unsigned getAttackSpeed()
	{
		return attack_speed_;
	}

	virtual unsigned getWalkingSpeed()
	{
		return walking_speed_;
	}

	virtual string getTextureString()
	{
		return texture_string_;
	}

	virtual Vector3 getPosition()
	{
		return position_;
	}

	virtual Vector3 getSize()
	{
		return size_;
	}

	virtual AABB getBoundingBox()
	{
		AABB bounding;
		bounding.setBoundry(-size_, size_);
		bounding.getBoundryAtCoord(position_);

		return bounding;
	}

	virtual void onDeath() = 0;
	virtual bool isEntityDead() = 0;

	virtual void setPosition(Vector3 position) = 0;
	virtual void updateAI(float timer) = 0;

};

#endif