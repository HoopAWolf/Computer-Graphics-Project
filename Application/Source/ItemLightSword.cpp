#ifndef ITEM_LIGHT_SWORD
#define ITEM_LIGHT_SWORD

#include "ItemWeapon.h"

class ItemLightSword : public ItemWeapon
{
public:
	ItemLightSword()
	{
		itemID_ = 0;
		texture_string_ = "lightsword";
		item_name_ = "Light Sword";
		
		weapon_type_ = LIGHT;
		durability_ = 10;
		damage_ = 3;
		attack_speed_ = 1;

	}

	//------------------USES------------------
	void onItemUse()
	{
		;
	}
};

#endif