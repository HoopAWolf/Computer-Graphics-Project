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

public:
	virtual ~EntityBoss();

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

	virtual string getMultiTextureString(unsigned dataNo)
	{
		return multiple_texture_string_[dataNo];
	}

};

#endif