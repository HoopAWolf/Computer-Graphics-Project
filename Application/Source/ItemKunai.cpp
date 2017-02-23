#ifndef ITEM_KUNAI
#define ITEM_KUNAI

#include "ItemWeapon.h"

class ItemKunai : public ItemWeapon
{
public:
	ItemKunai()
	{
		itemID_ = 13;
		texture_string_ = "kunai";
		item_name_ = "Kunai";


		weapon_type_ = LIGHT;
		durability_ = 25;
		damage_ = 15;
		attack_speed_ = 4;

		rarity_ = RARE;

	}

	//------------------USES------------------
	void onItemUse(float timer, float dt)
	{
		;
	}

	EntityProjectile* onItemAttackProjectile(float timer, float dt)
	{

		return nullptr;

	}
};

#endif