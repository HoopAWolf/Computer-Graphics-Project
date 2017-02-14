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

	ItemBase* getItemDrop()
	{
		return nullptr;
	}

	void setTextureString(string texture_string)
	{
		texture_string_ = texture_string;
	}

	void onDeath(){}

	bool isDead()
	{
		return false;
	}

	void updateAI(float timer){}

	void setPosition(Vector3 position)
	{
		position_ = position;
	}

};

#endif