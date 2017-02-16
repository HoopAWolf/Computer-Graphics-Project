#ifndef ITEM_WOODEN_SWORD
#define ITEM_WOODEN_SWORD

#include "ItemWeapon.h"

class ItemWoodenSword : public ItemWeapon
{
public:
	ItemWoodenSword()
	{
		itemID_ = 15;
		texture_string_ = "wooden_sword";
		item_name_ = "Wooden Sword";
		
		weapon_type_ = LIGHT;
		durability_ = 10;
		damage_ = 3;
		attack_speed_ = 1;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif