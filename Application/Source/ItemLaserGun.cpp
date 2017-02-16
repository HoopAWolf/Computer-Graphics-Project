#ifndef ITEM_LASER_GUN
#define ITEM_LASER_GUN

#include "ItemWeapon.h"

class ItemLaserGun : public ItemWeapon
{
public:
	ItemLaserGun()
	{
		itemID_ = 7;
		texture_string_ = "laser_gun";
		item_name_ = "Laser Gun";

		weapon_type_ = RANGE_AUTO;
		durability_ = 10;
		damage_ = 5;
		attack_speed_ = 3;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif