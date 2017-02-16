#ifndef ITEM_SWORD
#define ITEM_SWORD

#include "ItemWeapon.h"

class ItemSword : public ItemWeapon
{
public:
	ItemSword()
	{
		itemID_ = 14;
		texture_string_ = "sword";
		item_name_ = "Sword";

		weapon_type_ = LIGHT;
		durability_ = 15;
		damage_ = 3.5;
		attack_speed_ = 1.5;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif