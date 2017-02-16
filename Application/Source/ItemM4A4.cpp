#ifndef ITEM_M4A4
#define ITEM_M4A4

#include "ItemWeapon.h"

class ItemM4A4 : public ItemWeapon
{
public:
	ItemM4A4()
	{
		itemID_ = 0;
		texture_string_ = "texture2.tga";
		item_name_ = "Great Sword";


		weapon_type_ = RANGE_AUTO;
		durability_ = 43;
		damage_ = 15;
		attack_speed_ = 6.5;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif