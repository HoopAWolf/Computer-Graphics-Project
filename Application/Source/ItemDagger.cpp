#ifndef ITEM_DAGGER
#define ITEM_DAGGER

#include "ItemWeapon.h"

class ItemDagger : public ItemWeapon
{
public:
	ItemDagger()
	{
		itemID_ = 0;
		texture_string_ = "texture2.tga";
		item_name_ = "Dagger";


		weapon_type_ = LIGHT;
		durability_ = 5;
		damage_ = 5;
		attack_speed_ = 1;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif