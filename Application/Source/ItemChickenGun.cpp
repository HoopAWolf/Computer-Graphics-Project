#ifndef ITEM_CHICKEN_GUN
#define ITEM_CHICKEN_GUN

#include "ItemWeapon.h"

class ItemChickenGun : public ItemWeapon
{
public:
	ItemChickenGun()
	{
		itemID_ = 2;
		texture_string_ = "chicken_gun";
		item_name_ = "Chicken Gun";


		weapon_type_ = RANGE_AUTO;
		durability_ = 280;
		damage_ = 300;
		attack_speed_ = 9;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif