#ifndef ITEM_GIGGS_GUN
#define ITEM_GIGGS_GUN

#include "ItemWeapon.h"

class ItemGiggsGun : public ItemWeapon
{
public:
	ItemGiggsGun()
	{
		itemID_ = 4;
		texture_string_ = "giggs_gun";
		item_name_ = "Giggs Gun";


		weapon_type_ = RANGE_AUTO;
		durability_ = 45;
		damage_ = 46;
		attack_speed_ = 6;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif