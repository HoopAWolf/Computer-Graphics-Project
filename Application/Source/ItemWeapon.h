#ifndef _ITEM_WEAPON_H_
#define _ITEM_WEAPON_H_

#include "ItemBase.h"

class ItemWeapon abstract  : public ItemBase
{
private:
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
	int damage_;

	WEAPON_TYPE weapon_type_;

public:
	//------------------GETTERS------------------
	virtual WEAPON_TYPE getWeaponType() = 0;
	virtual int getWeaponDurability() = 0;
	virtual int getWeaponDamage() = 0;
};

#endif