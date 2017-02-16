#ifndef ITEM_HAMMER
#define ITEM_HAMMER

#include "ItemWeapon.h"

class ItemHammer : public ItemWeapon
{
public:
	ItemHammer()
	{
		itemID_ = 5;
		texture_string_ = "hammer";
		item_name_ = "Hammer";


		weapon_type_ = HEAVY;
		durability_ = 245;
		damage_ = 148;
		attack_speed_ = 4.5;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif