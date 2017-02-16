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
	unsigned minionID;

public:
	virtual ~EntityMinion(){};

	virtual MINION_STATE getMinionState() = 0;

	virtual unsigned getMinionID() = 0;
};

#endif