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
	unsigned bossID;
	BOSS_STATE boss_state_;
	unsigned armor_;

public:
	virtual ~EntityBoss();

	virtual string getBossName() = 0;
	virtual BOSS_STATE getBossState() = 0;
	virtual unsigned getBossArmor() = 0;
	virtual unsigned getBossID() = 0;

};

#endif