#ifndef ITEM_LUCILLE
#define ITEM_LUCILLE

#include "ItemWeapon.h"

class ItemLucille : public ItemWeapon
{
public:
	ItemLucille()
	{
		itemID_ = 14;
		texture_string_ = "lucille";
		item_name_ = "Lucille";


		weapon_type_ = MEDIUM;
		durability_ = 180;
		damage_ = 10;
		attack_speed_ = 4;

		rarity_ = RARE;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif