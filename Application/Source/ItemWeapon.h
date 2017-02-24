#ifndef _ITEM_WEAPON_H_
#define _ITEM_WEAPON_H_

#include "ItemBase.h"
#include "EntityFireBall.cpp"
#include "EntityBullet.cpp"
#include "EntityChickenProjectile.cpp"
#include "Camera3.h"

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
	unsigned bulletcount_;
	float attack_speed_;
	float recoil_;
	int price_;

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

	virtual float getRecoil()
	{
		return recoil_;
	}

	virtual unsigned getWeaponDamage()
	{
		return damage_;
	}

	virtual float getWeaponAttackSpeed()
	{
		return attack_speed_;
	}

	virtual int getPriceOfWeapon()
	{
		return price_;
	}

	virtual unsigned getBulletCount()
	{
		return bulletcount_;
	}

	//------------------USES------------------
	virtual EntityProjectile* onItemAttackProjectile(float timer, float dt) = 0;
};

#endif