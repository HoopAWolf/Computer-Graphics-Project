#ifndef _ENTITY_DROP_H_
#define _ENTITY_DROP_H_

#include "EntityBase.h"

class EntityDrop : public EntityBase
{
public:
	EntityDrop()
	{
		size_ = Vector3(2, 2, 2);
		elemental_type_ = NONE;
		texture_string_ = "";
		health_ = 0;
		damage_ = 0;
		attack_speed_ = 0;
		walking_speed_ = 0;
		drop_ = nullptr;
	}

	~EntityDrop();

	ELEMENTAL_TYPE getElementalType()
	{
		return elemental_type_;
	}

	ItemBase* getItemDrop()
	{
		return nullptr;
	}

	int getHealth()
	{
		return health_;
	}

	unsigned getDamage()
	{
		return damage_;
	}

	unsigned getAttackSpeed()
	{
		return attack_speed_;
	}

	unsigned getWalkingSpeed()
	{
		return walking_speed_;
	}

	string getTextureString()
	{
		return texture_string_;
	}

	void setTextureString(string texture_string)
	{
		texture_string_ = texture_string;
	}

	void onDeath(){}

	Vector3 getPosition()
	{
		return position_;
	}

	Vector3 getSize()
	{
		return size_;
	}


	void setPosition(Vector3 position)
	{
		position_ = position;
	}

};

#endif