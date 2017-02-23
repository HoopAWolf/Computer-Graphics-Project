#ifndef _ENTITY_BOSS_H_
#define _ENTITY_BOSS_H_

#include <string>
#include "EntityBase.h"
using std::string;

class EntityBoss abstract : public EntityBase
{

protected:
	enum BOSS_STATE
	{
		IDLE,
		WALKING,
		RETREAT,
		BLOCK,

		TAUNT,

		BASIC_ATTACK,

		SKILL_1,
		SKILL_2,
		SKILL_3,

		FINAL_ATTACK, 

		DEATH
	};
	string boss_name_;
	unsigned bossID_;
	BOSS_STATE boss_state_;
	unsigned armor_;

	int count = 0;

	float dt = -0.017;
	float dt1 = 0.017;
	float dt2 = 0;
	float dt3 = -0.017;
	float dt4 = -0.017;
	float rotateleftLeg = 0.0f;
	float rotaterightLeg = 0.0f;
	float rotateleftArmX = 0.0f;
	float rotateleftArmY = 0.0f;
	float rotateleftArmZ = 0.0f;
	float rotaterightArmX = 0.0f;
	float rotaterightArmY = 0.0f;
	float rotaterightArmZ = 0.0f;
	float spin = 0.0f;

	bool rightlegForward = true;
	bool rightlegBackward = false;
	bool leftlegForward = false;
	bool leftlegBackward = true;
	bool walking = false;
	bool attacking = false;
	bool limit = false;
	bool limit1 = false;
	bool limit2 = false;
	bool limit3 = false;
	bool limit4 = false;
	bool limit5 = false;


public:
	virtual ~EntityBoss(){};

	virtual string getBossName()
	{
		return boss_name_;
	}

	virtual BOSS_STATE getBossState()
	{
		return boss_state_;
	}

	virtual unsigned getBossArmor()
	{
		return armor_;
	}

	virtual unsigned getBossID()
	{
		return bossID_;
	}

	virtual float getrotateleftLeg()
	{
		return rotateleftLeg;
	}

	virtual float getrotaterightLeg()
	{
		return rotaterightLeg;
	}

	virtual float getrotateleftArmX()
	{
		return rotateleftArmX;
	}

	virtual float getrotateleftArmY()
	{
		return rotateleftArmY;
	}

	virtual float getrotateleftArmZ()
	{
		return rotateleftArmZ;
	}

	virtual float getrotaterightArmX()
	{
		return rotaterightArmX;
	}

	virtual float getrotaterightArmY()
	{
		return rotaterightArmY;
	}

	virtual float getrotaterightArmZ()
	{
		return rotaterightArmZ;
	}

	virtual float getspin()
	{
		return spin;
	}

};

#endif