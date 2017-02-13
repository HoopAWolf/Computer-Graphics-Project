#ifndef _ENTITY_BASE_H_
#define _ENTITY_BASE_H_

#include "ItemBase.h"
#include "Vector3.h"

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
	int health_;
	unsigned damage_;
	unsigned attack_speed_;
	unsigned walking_speed_;
	Vector3 position_, size_, up_, forward_, right_, target_;
	ItemBase* drop_;

public:
	virtual ~EntityBase(){};

	virtual ELEMENTAL_TYPE getElementalType() = 0;
	virtual ItemBase* getItemDrop() = 0;
	virtual int getHealth() = 0;
	virtual unsigned getDamage() = 0;
	virtual unsigned getAttackSpeed() = 0;
	virtual unsigned getWalkingSpeed() = 0;
	virtual string getTextureString() = 0;
	virtual Vector3 getPosition() = 0;
	virtual Vector3 getSize() = 0;

	virtual void onDeath() = 0;
	virtual bool isEntityDead() = 0;

	virtual void setPosition(Vector3 position) = 0;
	virtual void runAISequence() = 0;
};

#endif