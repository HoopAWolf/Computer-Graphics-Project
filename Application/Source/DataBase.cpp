#include "DataBase.h"

void DataBase::registerWeapons()
{
	if (item_base_.size() == 0)
	{
		ItemBase *temp_obj;
		
		temp_obj = new ItemLightSword;
		item_base_[temp_obj->getItemID()] = new ItemLightSword;
		delete temp_obj;
	}
}

ItemBase* DataBase::getItem(unsigned itemID)
{
	if (itemID < item_base_.size())
	{
		return item_base_[itemID];
	}

	return nullptr;
}

ItemBase* DataBase::getRandomItem(bool normal_item, bool weapon_item, unsigned rarity)
{
	srand(time(nullptr));

	if (normal_item)
	{
		if (rand() % (rarity + 1) == 1)
		{
			return getItem((rand() % item_starting_) + item_starting_);
		}
	}
	else if (weapon_item)
	{
		if (rand() % (rarity + 1) == 1)
		{
			return getItem((rand() % item_starting_));
		}
	}
}