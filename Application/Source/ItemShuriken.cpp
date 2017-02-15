#ifndef ITEM_SHURIKEN
#define ITEM_SHURIKEN

#include "ItemWeapon.h"

class ItemShuriken : public ItemWeapon
{
public:
	ItemShuriken()
	{
		itemID_ = 0;
		texture_string_ = "texture2.tga";
		item_name_ = "Shuriken";


		weapon_type_ = LIGHT;
		durability_ = 25;
		damage_ = 17;
		attack_speed_ = 3.5;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif