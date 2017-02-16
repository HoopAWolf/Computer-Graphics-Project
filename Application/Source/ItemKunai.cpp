#ifndef ITEM_KUNAI
#define ITEM_KUNAI

#include "ItemWeapon.h"

class ItemKunai : public ItemWeapon
{
public:
	ItemKunai()
	{
		itemID_ = 6;
		texture_string_ = "kunai";
		item_name_ = "Kunai";


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