#include "DataBase.h"

void DataBase::registerWeapons()
{
	if (weapon_base_.size() == 0)
	{
		weapon_base_.push_back(new ItemLightSword);
	}
}

ItemWeapon* DataBase::getWeapon(int itemID)
{
	for (int it = 0; it < weapon_base_.size(); it++)
	{
		if (weapon_base_[it]->getItemID() == itemID)
		{
			return weapon_base_[it];
		}
	}

	return nullptr;
}