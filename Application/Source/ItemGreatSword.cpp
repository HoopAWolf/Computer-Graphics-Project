#ifndef ITEM_GREAT_SWORD
#define ITEM_GREAT_SWORD

#include "ItemWeapon.h"

class ItemGreatSword : public ItemWeapon
{
public:
	ItemGreatSword()
	{
		itemID_ = 9;
		texture_string_ = "great_sword";
		item_name_ = "Great Sword";


		weapon_type_ = HEAVY;
		durability_ = 250;
		damage_ = 150;
		attack_speed_ = 6.5;
		rarity_ = UNCOMMON;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif