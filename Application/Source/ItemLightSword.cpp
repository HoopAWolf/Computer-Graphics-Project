#ifndef ITEM_LIGHT_SWORD
#define ITEM_LIGHT_SWORD

#include "ItemWeapon.h"

class ItemLightSword : public ItemWeapon
{
public:
	ItemLightSword()
	{
		itemID_ = 0;
		texture_string_ = "lightsword";
		item_name_ = "Light Sword";
		
		weapon_type_ = LIGHT;
		durability_ = 10;
		damage_ = 3;
		attack_speed_ = 1;

	}

	string getTextureString()
	{
		return texture_string_;
	}

	string getItemName()
	{
		return item_name_;
	}

	int getItemID()
	{
		return itemID_;
	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}

	WEAPON_TYPE getWeaponType()
	{
		return weapon_type_;
	}

	int getWeaponDurability()
	{
		return durability_;
	}

	int getWeaponDamage()
	{
		return damage_;
	}

	int getWeaponAttackSpeed()
	{
		return attack_speed_;
	}

};

#endif