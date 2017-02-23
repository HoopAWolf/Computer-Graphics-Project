#ifndef ITEM_GIGGS_GUN
#define ITEM_GIGGS_GUN

#include "ItemWeapon.h"

class ItemGiggsGun : public ItemWeapon
{
public:
	ItemGiggsGun()
	{
		itemID_ = 15;
		texture_string_ = "giggs_gun";
		item_name_ = "Giggs Gun";


		weapon_type_ = RANGE_AUTO;
		durability_ = 45;
		damage_ = 20;
		attack_speed_ = 3;

		rarity_ = LEGENDARY;

	}

	//------------------USES------------------
	void onItemUse(float timer, float dt)
	{
		
	}

	EntityProjectile* onItemAttackProjectile(float timer, float dt)
	{

		return nullptr;

	}
};

#endif