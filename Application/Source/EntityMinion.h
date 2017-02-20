#ifndef _ENTITY_MINION_H_
#define _ENTITY_MINION_H_

#include "EntityBase.h"

class EntityMinion abstract : public EntityBase
{

protected:
	enum MINION_STATE
	{
		IDLE,
		WALKING,
		RETREAT,

		TAUNT,

		BASIC_ATTACK,

		DEATH
	};

	MINION_STATE minion_state_;
	unsigned minionID_;
	string minion_name_;

public:
	virtual ~EntityMinion(){};

	virtual MINION_STATE getMinionState()
	{
		return minion_state_;
	}

	virtual string getMinionName()
	{
		return minion_name_;
	}

	virtual unsigned getMinionID()
	{
		return minionID_;
	}
};

#endif