#ifndef ITEM_SPEAR
#define ITEM_SPEAR

#include "ItemWeapon.h"

class ItemSpear : public ItemWeapon
{
public:
	ItemSpear()
	{
		itemID_ = 0;
		texture_string_ = "texture2.tga";
		item_name_ = "Spear";


		weapon_type_ = MEDIUM;
		durability_ = 27;
		damage_ = 27;
		attack_speed_ = 5.5;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif