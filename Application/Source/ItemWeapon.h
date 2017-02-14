#ifndef _ITEM_WEAPON_H_
#define _ITEM_WEAPON_H_

#include "ItemBase.h"

class ItemWeapon abstract  : public ItemBase
{

protected:
	enum WEAPON_TYPE
	{
		LIGHT,
		MEDIUM,
		HEAVY,

		RANGE_AUTO,
		RANGE_MANUAL,

		SHIELD
	};

	int durability_;
	unsigned damage_;
	unsigned attack_speed_;

	WEAPON_TYPE weapon_type_;

public:
	virtual ~ItemWeapon(){};

	//------------------GETTERS------------------
	virtual WEAPON_TYPE getWeaponType()
	{
		return weapon_type_;
	}

	virtual int getWeaponDurability()
	{
		return durability_;
	}

	virtual unsigned getWeaponDamage()
	{
		return damage_;
	}

	virtual unsigned getWeaponAttackSpeed()
	{
		return attack_speed_;
	}
};

#endif