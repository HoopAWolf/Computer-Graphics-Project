#ifndef ITEM_CHEST_PLATE
#define ITEM_CHEST_PLATE

#include "ItemWeapon.h"

class ItemChestPlate : public ItemWeapon
{
public:
	ItemChestPlate()
	{
		itemID_ = 0;
		texture_string_ = "chest_plate";
		item_name_ = "Chest Plate";

		weapon_type_ = LIGHT;
		durability_ = 10;
		damage_ = 1;
		attack_speed_ = 1;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif