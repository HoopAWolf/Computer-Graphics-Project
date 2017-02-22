#ifndef ITEM_BATTLE_AXE
#define ITEM_BATTLE_AXE

#include "ItemWeapon.h"

class ItemBattleAxe : public ItemWeapon
{
public:
	ItemBattleAxe()
	{
		itemID_ = 8;
		texture_string_ = "battle_axe";
		item_name_ = "Battle Axe";


		weapon_type_ = MEDIUM;
		durability_ = 160;
		damage_ = 20;
		attack_speed_ = 3;
		rarity_ = UNCOMMON;

	}

	//------------------USES------------------
	void onItemUse(float timer)
	{
		;
	}

	EntityProjectile* onItemAttackProjectile(float timer)
	{

		return nullptr;

	}
};

#endif