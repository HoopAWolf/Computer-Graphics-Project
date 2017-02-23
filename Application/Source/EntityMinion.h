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

	float minionrotateleftLeg = 0.0f;
	float minionrotaterightLeg = 0.0f;
	float rotateminionArm = 0.0f;
	float rotateminionBody = 0.0f;

	bool minionrightlegBackward = 0.0f;
	bool minionrightlegForward = 0.0f;
	bool minionleftlegBackward = 0.0f;
	bool minionleftlegForward = 0.0f;
	bool Minionlimit = false;
	bool minionwalking = false;

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

	virtual float getMinionrotateArm()
	{
		return rotateminionArm;
	}

	virtual float getMinionrotateleftLeg()
	{
		return minionrotateleftLeg;
	}

	virtual float getMinionrotaterightLeg()
	{
		return minionrotaterightLeg;
	}


};

#endif