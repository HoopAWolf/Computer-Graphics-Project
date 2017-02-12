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
	virtual WEAPON_TYPE getWeaponType() = 0;
	virtual int getWeaponDurability() = 0;
	virtual unsigned getWeaponDamage() = 0;
	virtual unsigned getWeaponAttackSpeed() = 0;
};

#endif