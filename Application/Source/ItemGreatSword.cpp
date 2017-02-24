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
		damage_ = 50;
		attack_speed_ = 2;
		rarity_ = UNCOMMON;

		price_ = 150;
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