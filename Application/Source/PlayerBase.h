#ifndef _PLAYER_BASE_H_
#define _PLAYER_BASE_H_

#include "ItemBase.h"
#include <vector>
#include <map>
#include "Vector3.h"
#include "Camera.h"
#include "AABB.h"

using std::vector;
using std::map;


class PlayerBase
{
public:
	enum PLAYER_STATE
	{
		IDLE,
		SPRINTING,

		LEFT_CLICK,
		RIGHT_CLICK, 

		USE_SKILLS
	};

private:

	PlayerBase(){};
	static PlayerBase *s_instance;
	int player_health_, current_held_item_;
	int current_skill_active_[2];
	unsigned damage_, attack_speed_, moving_speed_, ammo_, attribute_points_, resistance_, dimension_ , 
		level_, experience_, level_cap_;
	Vector3 size_;

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

	ItemBase* getItemFromInventory(int slot);
	ItemBase* getCurrentHeldItem();
	unsigned getCurrentItemSlot();
	unsigned getPlayerDamage();
	unsigned getPlayerAttackSpeed();
	unsigned getPlayerMovingSpeed();
	unsigned getPlayerResistance();
	unsigned getAttributePoint();
	unsigned getDimension();
	unsigned getPlayerLevel();
	unsigned getPlayerExperience();
	unsigned getPlayerLevelCap();
	unsigned getCurrentSkillPoint(unsigned skill_slot);
	unsigned getCurrentSkillDamage(unsigned skill_slot);
	unsigned getCurrentSkillCoolDown(unsigned skill_slot);
	int getPlayerHealth();
	unsigned getCurrentEquippedSkill(unsigned slotNum);
	void playerAttack(float timer);

	PLAYER_STATE getPlayerState()
	{
		return player_state_;
	}
	AABB getBoundingBox();

	bool isPlayerDead();

	void useSkills(unsigned skill_slot, float timer);
	void healPlayer(unsigned ammount);
	void setPlayerState(PLAYER_STATE player_state);
	void setPlayerDimension(unsigned dimensionID);
	void addIntoPlayerInventory(unsigned itemID);
	void increaseExperience(unsigned ammount);

	bool isInventoryFull();
	void moveCurrItem(bool forward);
	string getSkillName(unsigned skillID);

};

#endif