#ifndef _PLAYER_BASE_H_
#define _PLAYER_BASE_H_

#include "ItemBase.h"
#include <vector>
#include <map>
#include "Vector3.h"

using std::vector;
using std::map;


class PlayerBase
{
private:
	enum PLAYER_STATE
	{
		IDLE,

		WALKING,
		SPRINTING,

		RIGHT_CLICK
	};

	PlayerBase(){};
	static PlayerBase *s_instance;
	int player_health_;
	unsigned damage_, attack_speed_, moving_speed_, ammo_, attribute_points_, resistance_;

	vector<ItemBase *> inventory_data_;
	map<unsigned, Vector3> skills_; //VECTOR 3 (X - POINTS IN SKILL, Y - SKILL COOLDOWN, Z - SKILL DAMAGE/DURATION)
	// 0 - FIRE, 1 - WATER, 2 - LIGHTNING, 3 - EARTH
	PLAYER_STATE player_state_;

public:
	static PlayerBase* instance()
	{
		if (!s_instance)
			s_instance = new PlayerBase;

		return s_instance;
	}

	void startPlayer();
	void playerUpdate(float timer);

	ItemBase* getItemFromInvetory(int slot);
	ItemBase* getCurrentHeldItem();
	unsigned getPlayerDamage();
	unsigned getPlayerAttackSpeed();
	unsigned getPlayerMovingSpeed();
	unsigned getPlayerResistance();
	unsigned getAttributePoint();
	unsigned getCurrentSkillPoint(unsigned skill_slot);
	unsigned getCurrentSkillDamage(unsigned skill_slot);
	unsigned getCurrentSkillCoolDown(unsigned skill_slot);
	int getPlayerHealth();
	PLAYER_STATE getPlayerState()
	{
		return player_state_;
	}

	bool isPlayerDead();

	void useSkills(unsigned skill_slot, float timer);
	void healPlayer(unsigned ammount);
	void setPlayerState(PLAYER_STATE player_state);











};

#endif