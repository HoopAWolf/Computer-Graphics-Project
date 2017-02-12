#ifndef _ENTITY_BASE_H_
#define _ENTITY_BASE_H_

#include "DataBase.h"

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

	virtual void onDeath() = 0;
};

#endif