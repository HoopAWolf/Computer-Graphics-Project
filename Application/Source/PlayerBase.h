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

		USE_SKILLS,
		IN_UI
	};

private:

	PlayerBase(){};
	static PlayerBase *s_instance;
	int player_health_, current_held_item_, ammo_, currency_, current_skill_;

	unsigned damage_, moving_speed_,attribute_points_ , resistance_, dimension_ , 
		level_, experience_, level_cap_;
	bool isRecharging, hit;
	float rechargingTimer, rotationX, health_regen_timer, attack_speed_;
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
	void playerUpdate(float timer, float dt);

	ItemBase* getItemFromInventory(int slot);
	ItemBase* getCurrentHeldItem();
	unsigned getCurrentItemSlot();
	unsigned getPlayerDamage();
	float getPlayerAttackSpeed();
	unsigned getPlayerMovingSpeed();
	unsigned getPlayerResistance();
	unsigned getAttributePoint();
	unsigned getDimension();
	unsigned getPlayerLevel();
	unsigned getPlayerExperience();
	unsigned getPlayerLevelCap();
	int getPlayerCurrency();
	int getPlayerAmmo();
	unsigned getCurrentSkillPoint(unsigned skill_slot);
	unsigned getCurrentSkillDamage(unsigned skill_slot);
	unsigned getCurrentSkillCoolDown(unsigned skill_slot);
	int getPlayerHealth();
	unsigned getCurrentEquippedSkill();
	float getRotationX();
	void playerAttacked(int damage);

	PLAYER_STATE getPlayerState()
	{
		return player_state_;
	}
	AABB getBoundingBox();

	bool isPlayerDead();
	void deaded();

	void useSkills(float timer);
	void healPlayer(unsigned ammount);
	void setPlayerState(PLAYER_STATE player_state);
	void setPlayerDimension(unsigned dimensionID);
	void addIntoPlayerInventory(unsigned itemID);
	void increaseExperience(unsigned ammount);
	void increaseSkillPoint(unsigned skill_slot);
	void increaseCurrency(unsigned currency);
	void decreaseCurrency(unsigned currency);
	void swapItemInInventory(int itemOne, int itemTwo);

	bool isInventoryFull();
	void moveCurrItem(bool forward);
	void moveCurrSkill(bool forward);
	string getSkillName(unsigned skillID);

};

#endif