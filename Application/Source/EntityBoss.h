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
		TARGET_PLAYER,
		RETREAT,
		BLOCK,

		TAUNT,

		FINAL_ATTACK, 

		DEATH
	};

	enum ATTACK_STATE
	{
		PASSIVE,
		BASIC_ATTACK,

		SKILL_1,
		SKILL_2,
		SKILL_3
	};


	string boss_name_;
	unsigned bossID_;
	BOSS_STATE boss_state_;
	ATTACK_STATE boss_attack_state_;
	unsigned armor_;
	bool is_invisible_;


	int count = 0;

	float dt = -dt;
	float dt1 = dt;
	float dt2 = 0;
	float dt3 = -dt;
	float dt4 = -dt;
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

	virtual bool isInvisible()
	{
		return is_invisible_;
	}

};

#endif